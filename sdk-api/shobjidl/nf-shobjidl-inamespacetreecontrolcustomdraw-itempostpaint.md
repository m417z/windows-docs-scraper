# INameSpaceTreeControlCustomDraw::ItemPostPaint

## Description

Called after an item in the namespace tree control is drawn.

## Parameters

### `hdc` [in]

Type: **HDC**

A handle to the control's device context. Use this HDC to perform any GDI functions.

### `prc` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that describes the bounding rectangle of the area being drawn.

### `pnstccdItem` [in]

Type: **[NSTCCUSTOMDRAW](https://learn.microsoft.com/windows/desktop/api/shobjidl/ns-shobjidl-nstccustomdraw)***

A pointer to the [NSTCCUSTOMDRAW](https://learn.microsoft.com/windows/desktop/api/shobjidl/ns-shobjidl-nstccustomdraw) struct that determines the details of the drawing.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[INameSpaceTreeControlCustomDraw](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrolcustomdraw)