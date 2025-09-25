# PeerCollabGetSigninOptions function

## Description

The **PeerCollabGetSigninOptions** function obtains the peer's current signed-in peer collaboration network presence options.

## Parameters

### `pdwSigninOptions` [out]

The [PEER_SIGNIN_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_signin_flags) enumeration value is returned by this function.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The application did not make a previous call to [PeerCollabStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabstartup). |
| **PEER_E_NOT_SIGNED_IN** | The application has not signed into the peer collaboration network with a previous call to [PeerCollabSignIn](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsignin). |

## See also

[PEER_SIGNIN_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_signin_flags)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabSignIn](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsignin)

[PeerCollabSignOut](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsignout)