# DrawThemeBackground function

## Description

Draws the border and fill defined by the visual style for the specified control part.

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

### `pClipRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains a clipping rectangle. This parameter may be set to **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Drawing operations are scaled to fit and not exceed the rectangle specified in *pRect*. Your application should not draw outside the rectangle specified by *pClipRect*.

#### Examples

Prior to calling **DrawThemeBackground** to draw the background image for a window, you may call [IsThemeBackgroundPartiallyTransparent](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-isthemebackgroundpartiallytransparent). This method determines whether [DrawThemeParentBackground](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemeparentbackground) should be called to draw in backgrounds behind partially-transparent or alpha-blended child controls, and is demonstrated in the following example.

```cpp
if (_hTheme)
{
  if (IsThemeBackgroundPartiallyTransparent(_hTheme, BP_PUSHBUTTON, _iStateId))
  {
    DrawThemeParentBackground(_hwnd, hdcPaint, prcPaint);
  }

  DrawThemeBackground(_hTheme,
                    hdcPaint,
                    BP_PUSHBUTTON,
                    _iStateId,
                    &rcClient,
                    prcPaint);
}

```

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)