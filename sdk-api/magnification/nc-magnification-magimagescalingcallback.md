# MagImageScalingCallback callback function

## Description

**Note** The *MagImageScalingCallback* function is deprecated in Windows 7 and later, and should not be used in new applications. There is no alternate functionality.

Prototype for a callback function that implements a custom transform for image scaling.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The magnification window.

### `srcdata` [in]

Type: **void***

The input data.

### `srcheader` [in]

Type: **[MAGIMAGEHEADER](https://learn.microsoft.com/windows/desktop/api/magnification/ns-magnification-magimageheader)**

The description of the input format.

### `destdata` [out]

Type: **void***

The output data.

### `destheader` [in]

Type: **[MAGIMAGEHEADER](https://learn.microsoft.com/windows/desktop/api/magnification/ns-magnification-magimageheader)**

The description of the output format.

### `unclipped` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The coordinates of the scaled version of the source bitmap.

### `clipped` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The coordinates of the window to which the scaled bitmap is clipped.

### `dirty` [in]

Type: **[HRGN](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The region that needs to be refreshed.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## See also

[MAGIMAGEHEADER](https://learn.microsoft.com/windows/desktop/api/magnification/ns-magnification-magimageheader)

[MagGetImageScalingCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-maggetimagescalingcallback)