## Description

Creates a [UserActivityRequestManager](https://learn.microsoft.com/uwp/api/windows.applicationmodel.useractivities.useractivityrequestmanager) associated with the specified window.

## Parameters

### `window`

Handle to the window of the active application.

### `iid`

The GUID for the resource interface.

The REFIID, or GUID, of the interface to the resource can be obtained by using the __uuidof() macro. For example:

`__uuidof(UserActivityRequestManager)`

### `value`

Address of a pointer to a [UserActivityRequestManager](https://learn.microsoft.com/uwp/api/windows.applicationmodel.useractivities.useractivityrequestmanager) object.

## Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also