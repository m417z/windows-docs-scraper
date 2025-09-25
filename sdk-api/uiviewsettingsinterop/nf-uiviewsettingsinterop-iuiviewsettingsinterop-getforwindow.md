## Description

Gets an [UIViewSettings](https://learn.microsoft.com/uwp/api/Windows.UI.ViewManagement.UIViewSettings) object for the window of the active application.

## Parameters

### `hwnd`

Handle to the window of the active application.

### `riid`

The GUID for the resource interface.

The REFIID, or GUID, of the interface to the resource can be obtained by using the __uuidof() macro. For example:

`__uuidof(UIViewSettings)`

### `ppv`

Address of a pointer to a [UIViewSettings](https://learn.microsoft.com/uwp/api/Windows.UI.ViewManagement.UIViewSettings) object.

## Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[UIViewSettings](https://learn.microsoft.com/uwp/api/Windows.UI.ViewManagement.UIViewSettings)