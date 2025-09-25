# PeerCollabGetApplicationRegistrationInfo function

## Description

The **PeerCollabGetApplicationRegistrationInfo** function obtains application-specific registration information.

## Parameters

### `pApplicationId` [in]

Pointer to the GUID value that represents a particular peer's application registration flags.

### `registrationType` [in]

A [PEER_APPLICATION_REGISTRATION_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_application_registration_type) enumeration value that describes whether the peer's application is registered to the current user or all users of the local machine.

### `ppApplication` [out]

Pointer to the address of a [PEER_APPLICATION_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application_registration_info) structure that contains the information about a peer's specific registered application. The data returned in this parameter can be freed by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_FOUND** | The requested application is not registered for the given *registrationType*. |

## Remarks

An *application* is a set of software or software features available on the peer's endpoint. Commonly, this refers to software packages that support peer networking activities, like games or other collaborative applications.

A peer's application has a GUID representing a single application. When an application is registered for a peer, this GUID and the corresponding application can be made available to all trusted contacts of the peer, indicating the activities the peer can participate in. To unregister a peer's application, call [PeerCollabUnregisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabunregisterapplication) with this GUID.

## See also

[PEER_APPLICATION_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application_registration_info)

[PEER_APPLICATION_REGISTRATION_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_application_registration_type)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabRegisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabregisterapplication)

[PeerCollabUnregisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabunregisterapplication)