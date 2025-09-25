## Description

Creates a [UserActivitySession](https://learn.microsoft.com/uwp/api/windows.applicationmodel.useractivities.useractivitysession) associated with the specified window.

## Parameters

### `window`

Handle to the window of the active application.

### `iid`

The GUID for the resource interface.

The REFIID, or GUID, of the interface to the resource can be obtained by using the __uuidof() macro. For example:

`__uuidof(UserActivitySession)`

### `value`

Address of a pointer to a [UserActivitySession](https://learn.microsoft.com/uwp/api/windows.applicationmodel.useractivities.useractivitysession) object.

## Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also