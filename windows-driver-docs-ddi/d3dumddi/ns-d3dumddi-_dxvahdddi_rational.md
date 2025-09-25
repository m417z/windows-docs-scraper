# _DXVAHDDDI_RATIONAL structure

## Description

The DXVAHDDDI_RATIONAL structure describes a fractional value that represents the vertical and horizontal frequencies of a video mode (that is, vertical sync and horizontal sync).

## Members

### `Numerator` [in]

The numerator of the frequency fraction.

### `Denominator` [in]

The denominator of the frequency fraction.

## Remarks

An output rate of 0/0 is valid. The driver interprets 0/0 as 0/1. The driver interprets 0/any value as zero.

The NTSC frame rate is 30000/1001, and the PAL frame rate is 25/1.