# TcCloseInterface function

## Description

The
**TcCloseInterface** function closes an interface previously opened with a call to
[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea). All flows and filters on a particular interface should be closed before closing the interface with a call to
**TcCloseInterface**.

## Parameters

### `IfcHandle` [in]

Handle associated with the interface to be closed. This handle is obtained by a previous call to the
[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea) function.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_INVALID_HANDLE** | The interface handle is invalid. |
| **ERROR_TC_SUPPORTED_OBJECTS_EXIST** | Not all flows have been deleted for this interface. |

## Remarks

Regardless of whether
**TcCloseInterface** is called, an interface will be closed following a TC_NOTIFY_IFC_CLOSE notification event. If the
**TcCloseInterface** function is called with the handle of an interface that has already been closed, the handle will be invalidated and
**TcCloseInterface** will return ERROR_INVALID_HANDLE.

**Note** Use of
**TcCloseInterface** requires administrative privilege.

## See also

[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea)