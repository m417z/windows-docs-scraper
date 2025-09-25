# DXVA2_Frequency structure

## Description

Defines a video frequency.

## Members

### `Numerator`

Numerator of the frequency.

### `Denominator`

Denominator of the frequency.

## Remarks

The value 0/0 indicates an unknown frequency. Values of the form *n*/0, where *n* is not zero, are invalid. Values of the form 0/*n*, where *n* is not zero, indicate a frequency of zero.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)