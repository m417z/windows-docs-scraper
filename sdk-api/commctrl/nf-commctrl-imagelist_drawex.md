# ImageList_DrawEx function

## Description

Draws an image list item in the specified device context. The function uses the specified drawing style and blends the image with the specified color.

## Parameters

### `himl`

Type: **HIMAGELIST**

A handle to the image list

### `i`

Type: **int**

The index of the image to draw.

### `hdcDst`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the destination device context.

### `x`

Type: **int**

The x-coordinate at which to draw within the specified device context.

### `y`

Type: **int**

The y-coordinate at which to draw within the specified device context.

### `dx`

Type: **int**

The width of the portion of the image to draw relative to the upper-left corner of the image. If *dx* and
*dy* are zero, the function draws the entire image. The function does not ensure that the parameters are valid.

### `dy`

Type: **int**

The height of the portion of the image to draw, relative to the upper-left corner of the image. If
*dx* and
*dy* are zero, the function draws the entire image. The function does not ensure that the parameters are valid.

### `rgbBk`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The background color of the image. This parameter can be an application-defined RGB value or one of the following values:

| Value | Meaning |
| --- | --- |
| **CLR_NONE** | No background color. The image is drawn transparently. |
| **CLR_DEFAULT** | The default background color. The image is drawn using the background color of the image list. |

### `rgbFg`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The foreground color of the image. This parameter can be an application-defined RGB value or one of the following values:

| Value | Meaning |
| --- | --- |
| **CLR_NONE** | No blend color. The image is blended with the color of the destination device context. |
| **CLR_DEFAULT** | The default foreground color. The image is drawn using the system highlight color as the foreground color. |

### `fStyle`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The drawing style and, optionally, the overlay image. For information about specifying an overlay image index, see the comments section at the end of this topic. This parameter can be a combination of an overlay image index and one or more of the following values:

| Value | Meaning |
| --- | --- |
| **ILD_BLEND** |  |
| **ILD_BLEND25** | Draws the image, blending 25 percent with the blend color specified by *rgbFg*. This value has no effect if the image list does not contain a mask. |
| **ILD_BLEND50** | Draws the image, blending 50 percent with the blend color specified by *rgbFg*. This value has no effect if the image list does not contain a mask. |
| **ILD_FOCUS** |  |
| **ILD_IMAGE** | Set this flag if the overlay does not require a mask to be drawn. This flag causes **ImageList_DrawEx** to draw just the image, ignoring the mask. |
| **ILD_MASK** | Draws the mask. |
| **ILD_NORMAL** | Draws the image using the background color for the image list. If the background color is the CLR_NONE value, the image is drawn transparently using the mask. |
| **ILD_SELECTED** |  |
| **ILD_TRANSPARENT** | Draws the image transparently using the mask, regardless of the background color. This value has no effect if the image list does not contain a mask. |

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

An overlay image is drawn transparently over the primary image specified in the *i* parameter. To specify an overlay image in the *fStyle* parameter, use the [INDEXTOOVERLAYMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro to shift the one-based index of the overlay image. Use the OR operator to logically combine the return value of the macro with the drawing style flags specified in the *fStyle* parameter. You must first specify this image as an overlay image by using the [ImageList_SetOverlayImage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_setoverlayimage) function.