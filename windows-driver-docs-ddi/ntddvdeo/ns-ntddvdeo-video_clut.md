## Description

The **VIDEO_CLUT** structure is used to define a color look-up table (CLUT) for a video device.

## Members

### `NumEntries`

Number of entries in the **LookupTable** array.

### `FirstEntry`

Location in the device palette to which the first entry in the **LookupTable** of colors should be copied to. The other entries in the **LookupTable** should be copied sequentially, from this starting point into the device's palette.

### `RgbArray`

VIDEO_CLUTDATA structure with RGB values.

### `RgbLong`

Generic 32-bit value that can be used to access the color entries in the **LookupTable**.

### `LookupTable[1]`

Union with array of color entries to copy into the device's color registers/palette. The color entries can be accessed as a generic 32-bit value or as Red/Green/Blue/Unused fields.