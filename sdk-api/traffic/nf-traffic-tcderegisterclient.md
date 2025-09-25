# TcDeregisterClient function

## Description

The
**TcDeregisterClient** function deregisters a client with the Traffic Control Interface (TCI). Before deregistering, a client must delete each installed flow and filter with the
[TcDeleteFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcdeleteflow) and
[TcDeleteFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcdeletefilter) functions, and close all open interfaces with the
[TcCloseInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tccloseinterface) function, respectively.

## Parameters

### `ClientHandle` [in]

Handle assigned to the client through the previous call to the
[TcRegisterClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcregisterclient) function.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_INVALID_HANDLE** | Invalid interface handle, or the handle was set to **NULL**. |
| **ERROR_TC_SUPPORTED_OBJECTS_EXIST** | Interfaces are still open for this client. all interfaces must be closed to deregister a client. |

## Remarks

Once a client calls
**TcDeregisterClient**, the only traffic control function the client is allowed to call is
[TcRegisterClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcregisterclient).

**Note** Use of the
**TcDeregisterClient** function requires administrative privilege.

## See also

[TcCloseInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tccloseinterface)

[TcDeleteFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcdeletefilter)

[TcDeleteFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcdeleteflow)

[TcRegisterClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcregisterclient)