import { SerialPort } from 'serialport';

const PORT = '/dev/cu.usbmodem1201';
const BAUDRATE = 9600;

let serial;
async function open() {
  return new Promise((resolve) => {
    serial = new SerialPort({ path: PORT, baudRate: BAUDRATE });

    serial.on('open', () => {
      console.log(`Serial port ${PORT} opened.`);
      resolve();
    });

    serial.on('data', (buffer) => {
      let str = buffer.toString();
    });
  });
}

async function init() {
  await open();
}
init();

import express from 'express';

import path from 'node:path';
import { fileURLToPath } from 'node:url';
const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const app = express();

app.use(express.static(path.resolve(__dirname, './public')));

app.get('/update/:n', (req, res) => {
  let n = req.params.n * 1;
  serial.write(Buffer.from([n]));
  res.send(n + '');
  console.log(n);
});

app.listen(80);
