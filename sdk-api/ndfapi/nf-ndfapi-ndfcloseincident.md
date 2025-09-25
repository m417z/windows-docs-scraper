# NdfCloseIncident function

## Description

The **NdfCloseIncident** function is used to close an Network Diagnostics Framework (NDF) incident following its resolution.

## Parameters

### `handle` [in]

Type: **NDFHANDLE**

Handle to the NDF incident that is being closed.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |

## See also

[NdfCreateIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcreateincident)

[NdfCreateWinSockIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcreatewinsockincident)

[NdfExecuteDiagnosis](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfexecutediagnosis)