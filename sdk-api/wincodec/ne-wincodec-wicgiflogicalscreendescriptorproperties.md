# WICGifLogicalScreenDescriptorProperties enumeration

## Description

Specifies the logical screen descriptor properties for Graphics Interchange Format (GIF) metadata.

## Constants

### `WICGifLogicalScreenSignature:0x1`

 [VT_UI1 | VT_VECTOR] Indicates the signature property.

### `WICGifLogicalScreenDescriptorWidth:0x2`

[VT_UI2] Indicates the width in pixels.

### `WICGifLogicalScreenDescriptorHeight:0x3`

[VT_UI2] Indicates the height in pixels.

### `WICGifLogicalScreenDescriptorGlobalColorTableFlag:0x4`

[VT_BOOL] Indicates the global color table flag. **TRUE** if a global color table is present; otherwise, **FALSE**.

### `WICGifLogicalScreenDescriptorColorResolution:0x5`

[VT_UI1] Indicates the color resolution in bits per pixel.

### `WICGifLogicalScreenDescriptorSortFlag:0x6`

[VT_BOOL] Indicates the sorted color table flag. **TRUE** if the table is sorted; otherwise, **FALSE**.

### `WICGifLogicalScreenDescriptorGlobalColorTableSize:0x7`

[VT_UI1] Indicates the value used to calculate the number of bytes contained in the global color table.

To calculate the actual size of the color table, raise 2 to the value of the field + 1.

### `WICGifLogicalScreenDescriptorBackgroundColorIndex:0x8`

[VT_UI1] Indicates the index within the color table to use for the background (pixels not defined in the image).

### `WICGifLogicalScreenDescriptorPixelAspectRatio:0x9`

[VT_UI1] Indicates the factor used to compute an approximation of the aspect ratio.

### `WICGifLogicalScreenDescriptorProperties_FORCE_DWORD:0x7fffffff`