# PeerGroupConnect function

## Description

The **PeerGroupConnect** function initiates a PNRP search for a peer group and attempts to connect to it. After this function is called successfully, a peer can communicate with other members of the peer group.

## Parameters

### `hGroup` [in]

Handle to the peer group to which a peer intends to connect. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen),[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin), or [PeerGroupPasswordJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergrouppasswordjoin) function. This parameter is required.

## Return value

Returns S_OK if the operation succeeds. Otherwise, the function returns the following value.

| Return code | Description |
| --- | --- |
| **PEER_E_INVALID_GROUP** | The handle to the peer group is invalid. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

An application registers for peer events before calling this function. If the function call is unsuccessful, a PEER_GROUP_EVENT_CONNECTION_FAILED event is raised. Otherwise, a PEER_GROUP_EVENT_STATUS_CHANGED event is raised.

The PEER_GROUP_EVENT_CONNECTION_FAILED event is also raised when a group creator fails to call **PeerGroupConnect** immediately after creation. If this does not take place, users given an invitation will call **PeerGroupConnect** successfully but they will not be able to listen and will eventually receive the connection failed event.

In the event of a clock skew between participating machines, the success of **PeerGroupConnect** may depend on the severity of the skew. When troubleshooting a failure to join, this possibility should be taken into consideration by verifying that the machine clocks are synchronized.

To be present in the peer group and receive events but remain unconnected, use the [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)
function.

If a time-out value for **PeerGroupConnect** is not provided in the application, encountering a failure will cause the application to hang. A time-out value of 30 seconds is recommended.

Prior to calling **PeerGroupConnect**, a group exists in a '**Disconnected State**'. During this time the group cannot be detected or receive connections. In order to return a group to this state, the [PeerGroupClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupclose) function must be called.

## See also

[PeerGroupClose](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupclose)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)

[PeerGroupPasswordJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergrouppasswordjoin)