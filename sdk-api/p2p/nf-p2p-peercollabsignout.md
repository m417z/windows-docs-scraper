# PeerCollabSignout function

## Description

The **PeerCollabSignout** function signs a peer out of a specific type of peer collaboration network presence provider.

## Parameters

### `dwSigninOptions` [in]

[PEER_SIGNIN_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_signin_flags) enumeration value that contains the presence provider sign-in options for the calling peer. This value is obtained by calling [PeerCollabGetSigninOptions](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetsigninoptions) from the peer application.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The application did not make a previous call to [PeerCollabStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabstartup). |

## Remarks

If the local peer's collaboration infrastructure is signed out of both Internet and People Near Me presence, all transient information like objects and the endpoint ID are deleted. Any application that uses this information must republish the information. A single event that indicates signout is raised, instead of sending multiple individual events for each object or application.

 Multiple applications can use the infrastructure at any given moment. It is not recommended for a single application to sign out, as other applications will not be able to use the infrastructure.
Applications must also be prepared to handle user sign in and sign out, or situations where a machine goes to sleep or into hibernation.

## See also

[PEER_SIGNIN_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_signin_flags)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabGetSigninOptions](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetsigninoptions)