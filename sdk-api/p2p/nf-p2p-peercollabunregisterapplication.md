# PeerCollabUnregisterApplication function

## Description

The **PeerCollabUnregisterApplication** function unregisters the specific applications of a peer from the local computer.

## Parameters

### `pApplicationId` [in]

Pointer to the GUID value that represents a particular peer's application.

### `registrationType` [in]

A [PEER_APPLICATION_REGISTRATION_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_application_registration_type) value that describes whether the peer's application is deregistered for the current user or all users of the peer's machine.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_FOUND** | The application requested to unregister was not registered for the given *registrationType.* |

## Remarks

An *application* is a set of software or software features available on the peer's endpoint. Commonly, this refers to software packages that support peer networking activities, like games or other collaborative applications.

The collaboration infrastructure can receive application invites from trusted contacts or from "People Near Me", which are based on what scope the collaboration infrastructure is signed in with using PeerCollabSignin.

A peer's application has a GUID representing a single specific application. When application is registered for a peer, this GUID and the corresponding application can be made available to all trusted contacts of the peer, indicating the activities the peer can participate in. To unregister a peer's application, call **PeerCollabUnregisterApplication** with this GUID.

To unregister the application for all users, the caller of this API must be elevated.

## See also

[PEER_APPLICATION_REGISTRATION_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_application_registration_type)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabRegisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabregisterapplication)