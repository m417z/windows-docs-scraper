# WICPngFilterOption enumeration

## Description

Specifies the Portable Network Graphics (PNG) filters available for compression optimization.

## Constants

### `WICPngFilterUnspecified:0`

Indicates an unspecified PNG filter. This enables WIC to algorithmically choose the best filtering option for the image.

### `WICPngFilterNone:0x1`

Indicates no PNG filter.

### `WICPngFilterSub:0x2`

Indicates a PNG sub filter.

### `WICPngFilterUp:0x3`

Indicates a PNG up filter.

### `WICPngFilterAverage:0x4`

Indicates a PNG average filter.

### `WICPngFilterPaeth:0x5`

Indicates a PNG paeth filter.

### `WICPngFilterAdaptive:0x6`

Indicates a PNG adaptive filter. This enables WIC to choose the best filtering mode on a per-scanline basis.

### `WICPNGFILTEROPTION_FORCE_DWORD:0x7fffffff`