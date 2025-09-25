# PeerCollabGetAppLaunchInfo function

## Description

The **PeerCollabGetAppLaunchInfo** function obtains the peer application launch information, including the contact name, the peer endpoint, and the invitation request.

## Parameters

### `ppLaunchInfo` [out]

Pointer to a [PEER_APP_LAUNCH_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_app_launch_info) structure that receives the peer application launch data.

Free the memory associated with this structure by passing it to [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_FOUND** | The requested data does not exist. |

## Remarks

When an application invite is accepted, the application is launched with the information sent as part of the application invite. This information can be obtained by calling **PeerCollabGetAppLaunchInfo**.

## See also

[PEER_APP_LAUNCH_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_app_launch_info)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)