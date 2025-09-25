# TcDeleteFlow function

## Description

The
**TcDeleteFlow** function deletes a flow that has been added with the
[TcAddFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddflow) function. Clients should delete all filters associated with a flow before deleting it, otherwise, an error will be returned and the function will not delete the flow.

Traffic control clients that have registered a **DeleteFlowComplete** handler (a mechanism for allowing traffic control to call the
[ClDeleteFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_del_flow_complete_handler) callback function to alert clients of completed flow deletions) can expect a return value of ERROR_SIGNAL_PENDING.

## Parameters

### `FlowHandle` [in]

Handle for the flow, as received from a previous call to the
[TcAddFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddflow) function.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_SIGNAL_PENDING** | The function is being executed asynchronously; the client will be called back through the client-exposed [ClDeleteFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_del_flow_complete_handler) function when the flow has been added, or when the process has been completed. |
| **ERROR_INVALID_HANDLE** | The flow handle is invalid or **NULL**. |
| **ERROR_NOT_READY** | Action performed on the flow by a previous function call to [TcModifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcmodifyflow), [TcDeleteFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcdeleteflow), or [TcAddFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddflow) has not yet completed. |
| **ERROR_TC_SUPPORTED_OBJECTS_EXIST** | At least one filter associated with this flow exists. |

## Remarks

If the
**TcDeleteFlow** function returns ERROR_SIGNAL_PENDING, the
[ClDeleteFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_del_flow_complete_handler) function will be called on a different thread than the thread that called the
**TcDeleteFlow** function.

**Note** Use of the
**TcDeleteFlow** function requires administrative privilege.

## See also

[ClDeleteFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_del_flow_complete_handler)

[TcAddFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddflow)

[TcEnumerateFlows](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcenumerateflows)