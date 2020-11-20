// {
const model_url =
  "https://cdn.jsdelivr.net/gh/ml5js/ml5-data-and-models/models/pitch-detection/crepe/";

const freqs = [440, 493.8833, 261.6256, 293.6648, 329.6276, 349.2282, 391.9954];

let notes = [
  {
    note: "A",
    freq: 440,
  },
  {
    note: "B",
    freq: 493.8833,
  },
  {
    note: "C",
    freq: 261.6256,
  },
  {
    note: "D",
    freq: 293.6648,
  },
  {
    note: "E",
    freq: 329.6276,
  },
  {
    note: "F",
    freq: 349.2282,
  },
  {
    note: "G",
    freq: 391.9954,
  },
];

let generatedNotes = [];

let audioContext;
let mic;
let pitch;

let buttonStart, buttonStop

function setup() {
  createCanvas(100, 100);
  background(0);
  audioContext = getAudioContext();
  mic = new p5.AudioIn();
  mic.start(startPitch);

//   buttonStart = createButton('click me');
//   buttonStart.position(19, 19);
//   buttonStart.mousePressed(buttonClickedStart);

//   const start = document.querySelector('.start')
//   start.addEventListener("click", buttonClickedStart)
}

function touchStarted() {
  getAudioContext().resume();
}

function startPitch() {
  pitch = ml5.pitchDetection(model_url, audioContext, mic.stream, modelLoaded);
}
function modelLoaded() {
  console.log("model loaded");
  getPitch();
}
function getPitch() {
  pitch.getPitch(function (err, frequency) {
    if (frequency) {
      console.log(frequency);
      var closest = freqs.reduce(function (prev, curr) {
        return Math.abs(curr - frequency) < Math.abs(prev - frequency)
          ? curr
          : prev;
      });
      console.log(closest);
      for (let i = 0; i < notes.length; i++) {
        // console.log(notes[0].freq)
        if (notes[i]["freq"] === closest) {
          generatedNotes.push(notes[i]["note"]);
        }
        console.log(generatedNotes);
      }
    } else {
      console.log("no pitch detected");
      generatedNotes.push("rust");
    }
    getPitch();
  });
}

// const buttonClickedStart = () => {
//     console.log('start')
//     generatedNotes = [];
//     console.log(generatedNotes)
//     getAudioContext().resume();
// }
