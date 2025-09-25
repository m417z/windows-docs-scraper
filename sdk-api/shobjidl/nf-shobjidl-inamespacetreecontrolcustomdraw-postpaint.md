# INameSpaceTreeControlCustomDraw::PostPaint

## Description

Called after the namespace tree control is drawn.

## Parameters

### `hdc` [in]

Type: **HDC**

A handle to the control's device context. Use this HDC to perform any GDI functions.

### `prc` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that describes the bounding rectangle of the area being drawn.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[INameSpaceTreeControlCustomDraw](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrolcustomdraw)