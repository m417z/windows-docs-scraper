# TCI_MOD_FLOW_COMPLETE_HANDLER callback function

## Description

The
**ClModifyFlowComplete** function is used by traffic control to notify the client of the completion of its previous call to the
[TcModifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcmodifyflow) function.

The
**ClModifyFlowComplete** callback function is optional. If this function is not specified,
[TcModifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcmodifyflow) will block until it completes.

## Parameters

### `ClFlowCtx` [in]

Client provided–flow context handle. This can be the container used to hold an arbitrary client-defined context for this instance of the client. This value will be the same as the value provided by the client during its corresponding call to
[TcModifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcmodifyflow).

### `Status` [in]

Completion status for the
[TcModifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcmodifyflow) request. This value may be any of the return values possible for the
**TcModifyFlow** function, with the exception of ERROR_SIGNAL_PENDING.

**Note** Use of the
**ClModifyFlowComplete** function requires administrative privilege.

## See also

[TcModifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcmodifyflow)