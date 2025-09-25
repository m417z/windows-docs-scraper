# _DXVADDI_FREQUENCY structure

## Description

The DXVADDI_FREQUENCY structure describes the video frame rate in Hertz (Hz). For example, NTSC TV is 60000 over 1001.

## Members

### `Numerator` [in]

The numerator of the frequency fraction.

### `Denominator` [in]

The denominator of the frequency fraction.

## Remarks

The user-mode display driver must interpret the video frame rate for the following special cases as indicated:

* **Numerator**/**Denominator** = 0/0 is interpreted as an unknown frequency.
* **Numerator**/**Denominator** = n/0, where n is any number, is interpreted as invalid.
* **Numerator**/**Denominator** = 0/n is interpreted as zero frequency.

## See also

[DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc)