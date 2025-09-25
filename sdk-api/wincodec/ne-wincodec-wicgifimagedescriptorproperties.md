# WICGifImageDescriptorProperties enumeration

## Description

Specifies the image descriptor metadata properties for Graphics Interchange Format (GIF) frames.

## Constants

### `WICGifImageDescriptorLeft:0x1`

[VT_UI2] Indicates the X offset at which to locate this frame within the logical screen.

### `WICGifImageDescriptorTop:0x2`

[VT_UI2] Indicates the Y offset at which to locate this frame within the logical screen.

### `WICGifImageDescriptorWidth:0x3`

[VT_UI2] Indicates width of this frame, in pixels.

### `WICGifImageDescriptorHeight:0x4`

[VT_UI2] Indicates height of this frame, in pixels.

### `WICGifImageDescriptorLocalColorTableFlag:0x5`

[VT_BOOL] Indicates the local color table flag. **TRUE** if global color table is present; otherwise, **FALSE**.

### `WICGifImageDescriptorInterlaceFlag:0x6`

[VT_BOOL] Indicates the interlace flag. **TRUE** if image is interlaced; otherwise, **FALSE**.

### `WICGifImageDescriptorSortFlag:0x7`

[VT_BOOL] Indicates the sorted color table flag. **TRUE** if the color table is sorted from most frequently to least frequently used color; otherwise, **FALSE**.

### `WICGifImageDescriptorLocalColorTableSize:0x8`

[VT_UI1] Indicates the value used to calculate the number of bytes contained in the global color table.

To calculate the actual size of the color table, raise 2 to the value of the field + 1.

### `WICGifImageDescriptorProperties_FORCE_DWORD:0x7fffffff`