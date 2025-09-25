# IOleInPlaceActiveObject::OnDocWindowActivate

## Description

Notifies the active in-place object when the container's document window is activated or deactivated.

## Parameters

### `fActivate` [in]

The state of the MDI child document window. If this parameter is **TRUE**, the window is in the act of activating; if it is **FALSE**, it is in the act of deactivating.

## Return value

This method returns S_OK on success.

## Remarks

### Notes to Callers

Call **IOleInPlaceActiveObject::OnDocWindowActivate** when the MDI child document window is activated or deactivated and the object is currently the active object for the document.

### Notes to Implementers

You should include code in this method that installs frame-level tools during object activation. These tools include the shared composite menu and/or optional toolbars and frame adornments. You should then take focus. When deactivating, the object should remove the frame-level tools. Note that if you do not call [IOleInPlaceUIWindow::SetBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-setborderspace) with pborderwidths set to **NULL**, you can avoid having to renegotiate border space.

While executing **IOleInPlaceActiveObject::OnDocWindowActivate**, do not make calls to the [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) or [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) functions, or a dialog box. Doing so may cause the system to deadlock. There are further restrictions on which OLE interface methods and functions can be called from within **IOleInPlaceActiveObject::OnDocWindowActivate**.

## See also

[GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb)

[IOleInPlaceActiveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceactiveobject)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)