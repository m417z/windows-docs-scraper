# DrawThemeIcon function

## Description

Draws an image from an image list with the icon effect defined by the visual style.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part in which the image is drawn. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `pRect` [in]

Type: **LPCRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains, in logical coordinates, the rectangle in which the image is drawn.

### `himl` [in]

Type: **HIMAGELIST**

Handle to an [image list](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nn-commoncontrols-iimagelist) that contains the image to draw.

### `iImageIndex` [in]

Type: **int**

Value of type **int** that specifies the index of the image to draw.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IImageList](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nn-commoncontrols-iimagelist)

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)

**Reference**