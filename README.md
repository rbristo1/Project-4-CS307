Project 04: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]

# Project-4-CS307

To use:
Compile with make
use "src/generateMap N | src/dijkstras" to test with a random board of size N

| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | .003 s           | 85,348 B        |
| 20            | .005 s           | 93,308 B            |
| 50            | .011 s           | 141,700 B            |
| 100           | .021 s           | 311,396 B            |
| 200           | .025 s           | 928,852 B            |
| 500           | .450 s           | 5,232,444 B            |
| 1000          | 1.901 s          | 20,448,012 B            |
|---------------|---------------|----------------|
