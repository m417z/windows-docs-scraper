## Description

Gets an [Print3DManager](https://learn.microsoft.com/uwp/api/windows.graphics.printing3d.print3dmanager) object for the window of the active application.

## Parameters

### `appWindow`

Handle to the window of the active application.

### `riid`

The GUID for the resource interface.

The REFIID, or GUID, of the interface to the resource can be obtained by using the __uuidof() macro. For example:

`__uuidof(Print3DManager)`

### `printManager`

Address of a pointer to a [Print3DManager](https://learn.microsoft.com/uwp/api/windows.graphics.printing3d.print3dmanager) object.

## Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[Print3DManager](https://learn.microsoft.com/uwp/api/windows.graphics.printing3d.print3dmanager)