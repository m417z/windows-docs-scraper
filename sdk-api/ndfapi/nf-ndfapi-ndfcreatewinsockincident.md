# NdfCreateWinSockIncident function

## Description

The **NdfCreateWinSockIncident** function provides access to the Winsock Helper Class provided by Microsoft.

## Parameters

### `sock`

Type: **SOCKET**

A descriptor identifying a connected socket.

### `host` [in, optional]

Type: **LPCWSTR**

A pointer to the local host.

### `port`

Type: **USHORT**

The port providing Winsock access.

### `appId` [in, optional]

Type: **LPCWSTR**

Unique identifier associated with the application.

### `userId` [in, optional]

Type: **SID***

Unique identifier associated with the user.

### `handle` [out]

Type: **NDFHANDLE***

Handle to the Network Diagnostics Framework incident.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete this operation. |
| **NDF_E_BAD_PARAM** | One or more parameters are invalid. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## See also

[NdfCloseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcloseincident)

[NdfCreateIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcreateincident)

[NdfExecuteDiagnosis](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfexecutediagnosis)