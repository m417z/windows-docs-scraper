# IOleInPlaceActiveObject::ResizeBorder

## Description

Alerts the object that it needs to resize its border space.

## Parameters

### `prcBorder` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the new outer rectangle within which the object can request border space for its tools.

### `pUIWindow` [in]

A pointer to an [IOleInPlaceUIWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceuiwindow) interface pointer for the frame or document window object whose border has changed.

### `fFrameWindow` [in]

This parameter is **TRUE** if the frame window object is calling **IOleInPlaceActiveObject::ResizeBorder**; otherwise, it is **FALSE**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The specified parameter values are not valid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for the operation. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

### Notes to Callers

**IOleInPlaceActiveObject::ResizeBorder** is called by the top-level container's document or frame window object when the border space allocated to the object should change. Because the active in-place object is not informed about which window has changed (the frame- or document-level window), **IOleInPlaceActiveObject::ResizeBorder** must be passed the pointer to the window's [IOleInPlaceUIWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceuiwindow) interface.

### Notes to Implementers

In most cases, resizing only requires that you grow, shrink, or scale your object's frame adornments. However, for more complicated adornments, you may be required to renegotiate for border space with calls to [IOleInPlaceUIWindow::SetBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-setborderspace) and **IOleInPlaceUIWindow::SetBorderSpace**.

**Note** While executing **IOleInPlaceActiveObject::ResizeBorder**, do not make calls to the [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) or [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) functions, or a dialog box. Doing so may cause the system to deadlock. There are further restrictions on which OLE interface methods and functions can be called from within **IOleInPlaceActiveObject::ResizeBorder**.

## See also

[GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb)

[IOleInPlaceActiveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceactiveobject)

[IOleInPlaceUIWindow::GetBorder](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-getborder)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)