# PeerCollabEnumApplicationRegistrationInfo function

## Description

The **PeerCollabEnumApplicationRegistrationInfo** function obtains the enumeration handle used to retrieve peer application information.

## Parameters

### `registrationType` [in]

A [PEER_APPLICATION_REGISTRATION_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_application_registration_type) value that specifies whether the peer's application is registered to the **current user** or **all users** of the peer's machine.

### `phPeerEnum` [out]

Pointer to a peer enumeration handle for the peer application registration information. This data is obtained by passing this handle to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem).

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |

## Remarks

To obtain the individual peer applications, pass the returned handle to [PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem). An array of [PEER_APPLICATION_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application_registration_info) structures will be returned. To close the enumeration and release the resources associated with it, pass this handle to [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration). Individual items returned by the enumeration must be released with [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

An *application* is a set of software or software features available on the peer's endpoint. Commonly, this refers to software packages that support peer networking activities, like games or other collaborative applications.

A peer's application has a GUID representing a single specific application. When an application is registered for a peer, this GUID and the corresponding application can be made available to all trusted contacts of the peer, indicating the activities the peer can participate in. To unregister a peer's application, call [PeerCollabUnregisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabunregisterapplication) with this GUID.

Peer application registration information items are returned as individual [PEER_APPLICATION_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application_registration_info) structures.

## See also

[PEER_APPLICATION_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application_registration_info)

[PEER_APPLICATION_REGISTRATION_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_application_registration_type)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabUnregisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabunregisterapplication)