# IShellBrowser::EnableModelessSB

## Description

Tells Windows Explorer to enable or disable its modeless dialog boxes.

## Parameters

### `fEnable`

Type: **BOOL**

Specifies whether the modeless dialog boxes are to be enabled or disabled. If this parameter is nonzero, modeless dialog boxes are enabled. If this parameter is zero, modeless dialog boxes are disabled.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or a COM-defined error value otherwise.

## Remarks

This method is similar to the [IOleInPlaceFrame::EnableModeless](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-enablemodeless) method. Although the current version of Windows Explorer does not have any modeless dialog boxes, the view should call this method when it wants to disable or enable modeless dialog boxes associated with the Windows Explorer window.

## See also

[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)