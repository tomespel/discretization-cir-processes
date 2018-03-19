# Discretisation Schemes for CIR Processes
[![Build Status](https://travis-ci.org/tjespel/discretization-cir-processes.svg?branch=master)](https://travis-ci.org/tjespel/discretization-cir-processes) [![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0) [![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Ftjespel%2Fdiscretization-cir-processes.svg?type=shield)](https://app.fossa.io/projects/git%2Bgithub.com%2Ftjespel%2Fdiscretization-cir-processes?ref=badge_shield)

This is the simulation project `discretization-cir-process` at Imperial College London in the MSc in Mathematics and Finance. This project is part of the Numerical Methods in Finance (M5MF02) course and is carried under the supervision of Doctor Blanka Horvath. We based our work on Auélien Alfonsi's work on high order discretization schemes for the CIR process ([hal-00143723, 2008](https://hal.archives-ouvertes.fr/hal-00143723/document)).


## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Credits](#credits)
- [License](#license)

## Features

Our work features:
- Implementation of Aurélien Alfonsi's second order discretization schme for CIR processes ([hal-00143723, 2008](https://hal.archives-ouvertes.fr/hal-00143723/document)).
- A calibrated Heston model.
- A presentation with graphs representing our work.

## Installation

Download the `src` folder and use `C++` or above. We recommend the `g++` compiler.

## Usage

In order to compile and run the project, you can use the following command in the `src` folder.

```
make
./run
```

In case of an issue, run the following command.

```
make clean
```

Another cause of issue is the absence of the directory `/src/bin`. In this case, you can create it manually using the following command.
```
mkdir bin
```

## Credits

The team includes the following members, with the associated GitHub identifiers.

| Name | GitHub id |
| --- | --- |
|Thomas Espel|tjespel|
|Kees Groeneweg|kegror|
|Luis Pavon|luispavon22|
|Mehdi Tomas|mehditomas|

## License
Apache 2

[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Ftjespel%2Fdiscretization-cir-processes.svg?type=large)](https://app.fossa.io/projects/git%2Bgithub.com%2Ftjespel%2Fdiscretization-cir-processes?ref=badge_large)
