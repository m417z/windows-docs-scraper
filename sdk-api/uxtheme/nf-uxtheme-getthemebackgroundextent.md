# GetThemeBackgroundExtent function

## Description

Calculates the size and location of the background, defined by the visual style, given the content area.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC to use when drawing. This parameter may be set to **NULL**.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part that contains the content. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part that contains the content. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `pContentRect` [in]

Type: **LPCRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the content background rectangle, in logical coordinates. This rectangle is returned from [GetThemeBackgroundContentRect](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemebackgroundcontentrect).

### `pExtentRect` [out]

Type: **LPRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the background rectangle, in logical coordinates. This rectangle is based on the *pContentRect*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A theme can define a content area within each background image. This is the area where content such as text and icons can be placed without overwriting background borders.

## See also

[GetThemeBackgroundContentRect](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemebackgroundcontentrect)

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)

**Reference**