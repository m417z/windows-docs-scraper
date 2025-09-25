# FD_XFORM structure

## Description

The FD_XFORM structure describes an arbitrary two-dimensional font transform.

## Members

### `eXX`

### `eXY`

### `eYX`

### `eYY`

Are the four elements that comprise a 2x2 row-major matrix. **eXX** and **eXY** are the elements in the first row; **eYX** and **eYY** are the elements in the second row.

## Remarks

This structure is used typically to hold notional-to-device-space font transformations.