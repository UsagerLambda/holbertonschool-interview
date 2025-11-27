#!/usr/bin/node

const request = require('request');

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`, (error, response, body) => {
  if (error) return console.error(error);

  const characters = JSON.parse(body).characters;
  let i = 0;

  const printNext = () => {
    if (i >= characters.length) return;
    request(characters[i++], (err, res, data) => {
      if (!err) console.log(JSON.parse(data).name);
      printNext();
    });
  };

  printNext();
});
