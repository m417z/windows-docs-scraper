# _D3DKMDT_WIRE_FORMAT_AND_PREFERENCE structure

## Description

Holds information about the preferred pixel encoding format.

## Members

### `Preference`

Functions as it has in previous releases, but using only 2 bits.

### `Rgb`

UINT describing supported/requested pixel encoding using RGB sample format.

### `YCbCr444`

UINT describing supported/requested pixel encoding using YcbCr 4:4:4 sample format.

### `YCbCr422`

UINT describing supported/requested pixel encoding using YcbCr 4:2:2 sample format.

### `YCbCr420`

UINT describing supported/requested pixel encoding using YcbCr 4:2:0 sample format.

### `Intensity`

UINT describing supported/requested pixel encoding using intensity only.

### `Value`

UINT used to operate on the combined bit-fields.

## Remarks

The five standard color sample formats for pixel transmission are exposed separately to allow the driver to report capabilities individually but it is expected that the vast majority of display devices will not support all sample formats as input, in particular support of intensity only signals is likely restricted to monochrome displays which should therefore not support color sample formats.

During mode enumeration via EnumVidPnCofuncModality, the driver should set values into all five fields to indicate the pixel encodings that are supported as inputs to the display device in the current configuration.

When SetTimingsFromVidPn is called, one of these fields will indicate the pixel encoding and sample format to be applied.