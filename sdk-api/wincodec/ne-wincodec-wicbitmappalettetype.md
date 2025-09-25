# WICBitmapPaletteType enumeration

## Description

Specifies the type of palette used for an indexed image format.

## Constants

### `WICBitmapPaletteTypeCustom:0`

An arbitrary custom palette provided by caller.

### `WICBitmapPaletteTypeMedianCut:0x1`

An optimal palette generated using a median-cut algorithm. Derived from the colors in an image.

### `WICBitmapPaletteTypeFixedBW:0x2`

A black and white palette.

### `WICBitmapPaletteTypeFixedHalftone8:0x3`

A palette that has its 8-color on-off primaries and the 16 system colors added. With duplicates removed, 16 colors are available.

### `WICBitmapPaletteTypeFixedHalftone27:0x4`

A palette that has 3 intensity levels of each primary: 27-color on-off primaries and the 16 system colors added. With duplicates removed, 35 colors are available.

### `WICBitmapPaletteTypeFixedHalftone64:0x5`

A palette that has 4 intensity levels of each primary: 64-color on-off primaries and the 16 system colors added. With duplicates removed, 72 colors are available.

### `WICBitmapPaletteTypeFixedHalftone125:0x6`

A palette that has 5 intensity levels of each primary: 125-color on-off primaries and the 16 system colors added. With duplicates removed, 133 colors are available.

### `WICBitmapPaletteTypeFixedHalftone216:0x7`

A palette that has 6 intensity levels of each primary: 216-color on-off primaries and the 16 system colors added. With duplicates removed, 224 colors are available. This is the same as **WICBitmapPaletteFixedHalftoneWeb**.

### `WICBitmapPaletteTypeFixedWebPalette`

A palette that has 6 intensity levels of each primary: 216-color on-off primaries and the 16 system colors added. With duplicates removed, 224 colors are available. This is the same as **WICBitmapPaletteTypeFixedHalftone216**.

### `WICBitmapPaletteTypeFixedHalftone252:0x8`

A palette that has its 252-color on-off primaries and the 16 system colors added. With duplicates removed, 256 colors are available.

### `WICBitmapPaletteTypeFixedHalftone256:0x9`

A palette that has its 256-color on-off primaries and the 16 system colors added. With duplicates removed, 256 colors are available.

### `WICBitmapPaletteTypeFixedGray4:0xa`

A palette that has 4 shades of gray.

### `WICBitmapPaletteTypeFixedGray16:0xb`

A palette that has 16 shades of gray.

### `WICBitmapPaletteTypeFixedGray256:0xc`

A palette that has 256 shades of gray.

### `WICBITMAPPALETTETYPE_FORCE_DWORD:0x7fffffff`