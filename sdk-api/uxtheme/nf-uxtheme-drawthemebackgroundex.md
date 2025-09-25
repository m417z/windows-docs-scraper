# DrawThemeBackgroundEx function

## Description

[**DrawThemeBackgroundEx** is available for use in the operating

systems specified in the Requirements section. It may be altered or unavailable in

subsequent versions.]

Draws the background image defined by the visual style for the specified control part.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC used for drawing the theme-defined background image.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part to draw. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part to draw. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `pRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the rectangle, in logical coordinates, in which the background image is drawn.

### `pOptions` [in]

Type: **const [DTBGOPTS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-dtbgopts)***

Pointer to a [DTBGOPTS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-dtbgopts) structure that contains clipping information. This parameter may be set to **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Drawing operations are scaled to fit and to not exceed the rectangle specified in *pRect*.