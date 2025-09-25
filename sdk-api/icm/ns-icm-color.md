## Description

Description of the COLOR union.

## Members

### `gray`

TBD

### `rgb`

TBD

### `cmyk`

TBD

### `XYZ`

TBD

### `Yxy`

TBD

### `Lab`

TBD

### `gen3ch`

TBD

### `named`

TBD

### `hifi`

TBD

### `reserved1`

TBD

### `reserved2`

TBD

## Remarks

A variable of type COLOR may be accessed as any of the supported color space colors by accessing the appropriate member of the union. For instance, given the following variable declaration:

`COLOR aColor;`

the red, green and blue values could be set in the following manner:

`aColor.rgb.red=100;`

`aColor.rgb.green=50;`

`aColor.rgb.blue=2;`

## See also