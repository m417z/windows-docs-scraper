# INameSpaceTreeControlCustomDraw::ItemPrePaint

## Description

Called before an item in the namespace tree control is drawn.

## Parameters

### `hdc` [in]

Type: **HDC**

A handle to the control's device context. Use this HDC to perform any GDI functions.

### `prc` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that describes the bounding rectangle of the area being drawn.

### `pnstccdItem` [in]

Type: **[NSTCCUSTOMDRAW](https://learn.microsoft.com/windows/desktop/api/shobjidl/ns-shobjidl-nstccustomdraw)***

A pointer to the [NSTCCUSTOMDRAW](https://learn.microsoft.com/windows/desktop/api/shobjidl/ns-shobjidl-nstccustomdraw) structure that determines the details of the drawing.

### `pclrText` [in, out]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)***

On entry, a pointer to a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) structure that declares the default color of the text. When this method returns, contains a pointer to a **COLORREF** structure that declares the color that should be used in its place, if any. This allows the client to provide their own color if they do not want to use the default.

### `pclrTextBk` [in, out]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)***

On entry, a pointer to a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) structure that declares the default color of the background. When this method returns, contains a pointer to a **COLORREF** structure that declares the color that should be used in its place, if any. This allows the client to provide their own color if they do not want to use the default.

### `plres` [out]

Type: **LRESULT***

When this method returns, contains a pointer to an **LRESULT**, which points to one or more of the values from the [CDRF Constants](https://learn.microsoft.com/windows/desktop/Controls/cdrf-constants) enumeration.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[INameSpaceTreeControlCustomDraw](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrolcustomdraw)