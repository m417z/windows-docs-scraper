# IOleInPlaceActiveObject::OnFrameWindowActivate

## Description

Notifies the object when the container's top-level frame window is activated or deactivated.

## Parameters

### `fActivate` [in]

 The state of the container's top-level frame window. This parameter is **TRUE** if the window is activating and **FALSE** if it is deactivating.

## Return value

This method returns S_OK on success.

## See also

[GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb)

[IOleInPlaceActiveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceactiveobject)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)