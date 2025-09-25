# PeerCollabSetEndpointName function

## Description

The **PeerCollabSetEndpointName** function sets the name of the current endpoint used by the peer application.

## Parameters

### `pwzEndpointName` [in]

Pointer to the new name of the current endpoint, represented as a zero-terminated Unicode string. An error is raised if the new name is the same as the current one. An endpoint name is limited to 255 Unicode characters.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_SIGNED_IN** | The operation requires the user to be signed in. |

## Remarks

An endpoint name is set to the machine name by default. However, a new endpoint name set by the **PeerCollabSetEndpointName** function will persist across reboots.

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)