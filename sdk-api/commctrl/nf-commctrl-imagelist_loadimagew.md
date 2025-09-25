# ImageList_LoadImageW function

## Description

Creates an image list from the specified bitmap.

## Parameters

### `hi`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the instance that contains the resource. This parameter can be **NULL** if you are loading an image from a file or loading an OEM resource.

### `lpbmp`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The image to load.

If the *uFlags* parameter includes LR_LOADFROMFILE, *lpbmp* is the address of a null-terminated string that names the file containing the image to load.

If the *hi* parameter is non-**NULL** and LR_LOADFROMFILE is not specified, *lpbmp* is the address of a null-terminated string that contains the name of the image resource in the *hi* module.

If *hi* is **NULL** and LR_LOADFROMFILE is not specified, the [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)) of this parameter must be the identifier of an OEM image to load. To create this value, use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro with one of the OEM image identifiers defined in Winuser.h. These identifiers have the following prefixes.

| Value | Meaning |
| --- | --- |
| **OBM_ for OEM bitmaps** |  |
| **OIC_ for OEM icons** |  |
| **OCR_ for OEM cursors** |  |

### `cx`

Type: **int**

The width of each image. The height of each image and the initial number of images are inferred by the dimensions of the specified resource.

### `cGrow`

Type: **int**

The number of images by which the image list can grow when the system needs to make room for new images. This parameter represents the number of new images that the resized image list can contain.

### `crMask`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The color used to generate a mask. Each pixel of this color in the specified bitmap, cursor, or icon is changed to black, and the corresponding bit in the mask is set to 1. If this parameter is the CLR_NONE value, no mask is generated. If this parameter is the CLR_DEFAULT value, the color of the pixel at the upper-left corner of the image is treated as the mask color.

### `uType`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A flag that specifies the type of image to load. This parameter must be IMAGE_BITMAP to indicate that a bitmap is being loaded.

**Note** **ImageList_LoadImage** is for use only with bitmap files. No other image types are supported.

| Value | Meaning |
| --- | --- |
| **IMAGE_BITMAP** | Loads a bitmap. |

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that specify how to load the image. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **LR_CREATEDIBSECTION** | Causes the function to return a DIB section bitmap rather than a compatible bitmap when the *uType* parameter specifies IMAGE_BITMAP. LR_CREATEDIBSECTION is useful for loading a bitmap without mapping it to the colors of the display device. |
| **LR_DEFAULTCOLOR** | Uses the color format of the display. |
| **LR_DEFAULTSIZE** | Uses the width or height specified by the system metric values for cursors and icons if the *cx* parameter is set to zero. If this value is not specified and *cx* is set to zero, the function sets the size to the one specified in the resource. If the resource contains multiple images, the function sets the size to that of the first image. |
| **LR_LOADFROMFILE** | Loads the image from the file specified by the *lpbmp* parameter. |
| **LR_LOADMAP3DCOLORS** | Searches the color table for the image and replaces the following shades of gray with the corresponding three-dimensional color:<br><br>Dk Gray: RGB(128, 128, 128)COLOR_3DSHADOW <br><br>Gray: RGB(192, 192, 192)COLOR_3DFACE <br><br>Lt Gray: RGB(223, 223, 223)COLOR_3DLIGHT <br><br>For more information, see the Remarks section. |
| **LR_LOADTRANSPARENT** | Retrieves the color value of the first pixel in the image and replaces the corresponding entry in the color table with the default window color (the COLOR_WINDOW display color). All pixels in the image that use that color become the default window value color. This value applies only to images that have a corresponding color table. For more information, see the Remarks section. |
| **LR_MONOCHROME** | Loads the image in black and white. |
| **LR_SHARED** | Shares the image handle if the image is loaded multiple times. Do not use this value for images that have nontraditional sizes that might change after loading or for images that are loaded from a file. |

## Return value

Type: **HIMAGELIST**

Returns the handle to the image list if successful, or **NULL** otherwise.

## Remarks

LR_LOADTRANSPARENT does not load the image transparently. It creates an opaque image list that only appears transparent because all the background pixels have been changed to COLOR_WINDOW. If the images are drawn over a background that is not the color COLOR_WINDOW, the image does not draw properly. Also, LR_LOADTRANSPARENT and LR_LOADMAP3DCOLORS use the system colors that were in effect at the time that **ImageList_LoadImage** was called. If the system colors subsequently change, the application must reload the image to remap the colors.

> [!NOTE]
> The commctrl.h header defines ImageList_LoadImage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea)