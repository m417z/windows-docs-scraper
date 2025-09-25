# NdfExecuteDiagnosis function

## Description

The **NdfExecuteDiagnosis** function is used to diagnose the root cause of the incident that has occurred.

## Parameters

### `handle`

Type: **NDFHANDLE**

Handle to the Network Diagnostics Framework incident.

### `hwnd`

Type: **HWND**

Handle to the window that is intended to display the diagnostic information. If specified, the NDF UI is modal to the window. If **NULL**, the UI is non-modal.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_HANDLE** | *handle* is invalid. |

## See also

[NdfCloseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcloseincident)

[NdfCreateIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcreateincident)

[NdfCreateWinSockIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcreatewinsockincident)