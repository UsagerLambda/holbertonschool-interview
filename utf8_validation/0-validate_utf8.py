#!/usr/bin/python3
"""Determine if a given data set represent a valid UTF-8 encoding."""


def validUTF8(data):
    """Determine if a given data set represent a valid UTF-8 encoding.

    Args:
        data (list): set that can contain multiple characters

    Returns:
        bool: True if data is valid, else return False
    """
    remaining_bytes = 0

    for byte in data:
        byte = byte & 0xFF

        if remaining_bytes == 0:
            if byte >> 7 == 0b0:  # Si on supprime 7 bits à droite
                remaining_bytes = 0
            elif byte >> 5 == 0b110:  # 5 bits
                remaining_bytes = 1
            elif byte >> 4 == 0b1110:  # 4 bits
                remaining_bytes = 2
            elif byte >> 3 == 0b11110:  # 3 bits
                remaining_bytes = 3
            else:
                return False
        else:
            if byte >> 6 != 0b10:  # Si suppr 6 bits à droite ne donne pas 0b10
                return False
            remaining_bytes -= 1

    return remaining_bytes == 0
