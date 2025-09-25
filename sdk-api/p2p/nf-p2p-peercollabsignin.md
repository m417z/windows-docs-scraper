# PeerCollabSignin function

## Description

The **PeerCollabSignin** function signs the peer into a hosted Internet (serverless presence) or subnet ("People Near Me") peer collaboration network presence provider.

## Parameters

### `hwndParent` [in]

Windows handle to the parent application signing in.

### `dwSigninOptions` [in]

[PEER_SIGNIN_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_signin_flags) enumeration value that contains the presence provider sign-in options for the calling peer.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The application did not make a previous call to [PeerCollabStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabstartup). |
| **PEER_E_SERVICE_NOT_AVAILABLE** | An attempt was made to call [PeerCollabSignIn](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsignin) from an elevated process. |
| **PEER_S_NO_CONNECTIVITY** | The sign-in succeeded, but IPv6 addresses are not available at this time. |

## Remarks

If the p2phost.exe service is not running, this function will launch it.

If an attempt is made to launch the p2phost.exe service from an elevated process, an error is returned. As a result, security cannot be compromised by an application mistakenly granting administrative privileges to p2phost.exe. It is not possible to launch p2phost.exe in a non-interactive mode, as it needs to display Windows dialog boxes for incoming invites.

Calling **PeerCollabSignin** displays a sign-in user interface if the user has not authorized automatic sign-in. If *hwndParent* is specified, the user interface window will use *hwndParent* as the parent window.

When a user signs in to "People Near Me", the user's display name, machine name, and IP address are published to peers on the subnet. The user can optionally specify a display picture for publishing. This information is not published if **PeerCollabSignin** is not called or the user signs out.

Once signed in, the user can view a list of peers signed in on the subnet and available for interaction. This list will be empty if nobody else has signed in to "People Near Me" on the subnet.

 Multiple applications can use the infrastructure at any given moment. It is not recommended for a single application to call [PeerCollabSignout](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsignout), as other applications will not be able to use the infrastructure.
Applications must also be prepared to handle the user signing in and signing out, or situations where a machine goes to sleep or hibernation.

The **PeerCollabSignin** function currently requires up to two seconds to complete.

Display names are not necessarily unique. Users should verify the identity of the person using a display name by e-mail, phone, or in person before accepting an invitation to interact.

To sign out of a peer collaborative network, call [PeerCollabSignout](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsignout) with the same set of sign-in options. A user can also sign out through the user interface.

## See also

[PEER_SIGNIN_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_signin_flags)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabGetSigninOptions](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetsigninoptions)

[PeerCollabSignOut](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsignout)