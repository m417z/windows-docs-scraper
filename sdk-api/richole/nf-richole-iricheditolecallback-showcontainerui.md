# IRichEditOleCallback::ShowContainerUI

## Description

Indicates whether or not the application is to display its container UI. The rich edit control looks ahead for double-clicks and defers the call if appropriate. Applications may defer hiding adornments until an [IOleInPlaceUIWindow::SetBorderSpace](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-setborderspace) call is received.

## Parameters

### `fShow`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Show container UI flag. The value is **TRUE** if the container UI is displayed, and **FALSE** if it is not.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** on success. If the method fails, it can return the following value.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | There was an invalid argument. |

## Remarks

The
**IRichEditOleCallback::ShowContainerUI** method is called by the [IOleInPlaceSite::OnUIActivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuiactivate) and [IOleInPlaceSite::OnUIDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuideactivate) methods of the [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) interface.

## See also

[IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe)

[IRichEditOleCallback](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditolecallback)

**Other Resources**

**Reference**