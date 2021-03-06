# n-body

![Screenshot](screenshot.png)

A N-Body simulation.

This repo contains my Bachelor's thesis.

It has three configurations:
* brute: brute force method
* bhtree: tree based method
* parallel: tree based method (parallel)

## Dependencies
* Qt 5.
* C++11 onwards

## Instructions
```
qmake
make
bin/nbody configuration [iterations] [trace]
```

## Inputs
Input must come in a file format, in which the first line indicates the number of bodies and the second the radius of the universe.

From the third line, each line represents a body, with the parameters as follows:

```
mass posx posy velx vly
```

The program reads the input file from the standard input.

### Provided inputs
`10k.txt`: 10000 bodies orbiting in an elliptical way.

`10k.txt`: 20000 bodies orbiting in an elliptical way.

`30k.txt`: 30000 bodies orbiting in an elliptical way.

`asteroids.txt`: 1000 asteroids orbiting around a star.

`cluster.txt`: A 2500 particle cloud.

`collapse.txt`: A 2500 particle cloud collapses into a galaxy.

`dual.txt`: Two galaxies orbiting each other.

`galaxy.txt`: A galaxy moving through space.

`merge.txt`: Four 1000 particles collapse.

`planets.txt`: A star system composed by 4 planets.

`saturn.txt`: Saturn rings.

`spiral.txt`: A round galaxy becomes a spiral one.

Credits of the input files to Adam Chin and Rohan Kapadia.
