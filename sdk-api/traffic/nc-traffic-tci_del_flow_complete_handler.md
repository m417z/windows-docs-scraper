# TCI_DEL_FLOW_COMPLETE_HANDLER callback function

## Description

The
**ClDeleteFlowComplete** function is used by traffic control to notify the client of the completion of its previous call to the
[TcDeleteFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcdeleteflow) function.

The
**ClDeleteFlowComplete** callback function is optional. If this function is not specified,
[TcDeleteFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcdeleteflow) will block until it completes.

## Parameters

### `ClFlowCtx` [in]

Client provided–flow context handle. This can be the container used to hold an arbitrary client-defined context for this instance of the client. This value will be the same as the value provided by the client during its corresponding call to
[TcDeleteFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcdeleteflow).

### `Status` [in]

Completion status for the
[TcDeleteFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcdeleteflow) request. This value may be any of the return values possible for the
**TcDeleteFlow** function, with the exception of ERROR_SIGNAL_PENDING.

**Note** Use of the
**ClDeleteFlowComplete** function requires administrative privilege.

## See also

[TcDeleteFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcdeleteflow)