# EvtClose function

## Description

Closes an open handle.

## Parameters

### `Object` [in]

An open event handle to close.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

 You cannot use the handle after the handle is closed. When you close a parent handle, any opened handles that were created using the handle are also closed. For example, if you query for events, the query result contains a handle for each event that matches the query. Best practice suggests that you close each event handle when you are done with the event but if you do not, when you close the query handle, all event handles are also closed.