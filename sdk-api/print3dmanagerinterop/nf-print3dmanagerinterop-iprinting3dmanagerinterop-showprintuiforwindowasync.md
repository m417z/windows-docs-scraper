## Description

Programmatically initiates the 3D printing user interface.

## Parameters

### `appWindow`

Handle to the window of the active application.

### `riid`

The GUID for the resource interface.

The REFIID, or GUID, of the interface to the resource can be obtained by using the __uuidof() macro. For example:

`__uuidof(IAsyncAction)`

### `asyncOperation`

Address of a pointer to a [IAsyncAction](https://learn.microsoft.com/uwp/api/Windows.Foundation.IAsyncAction) object that returns void upon completion.

## Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also