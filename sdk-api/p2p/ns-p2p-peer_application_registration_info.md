# PEER_APPLICATION_REGISTRATION_INFO structure

## Description

The **PEER_APPLICATION_REGISTRATION_INFO** structure contains peer application information for registration with the local computer.

## Members

### `application`

[PEER_APPLICATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application) structure that contains the specific peer application data.

### `pwzApplicationToLaunch`

Zero-terminated Unicode string that contains the local path to the executable peer application. Note that this data is for local use only and that this structure is never transmitted remotely.

### `pwzApplicationArguments`

Zero-terminated Unicode string that contains command-line arguments that must be supplied to the application when the application is launched. This data is for local use only. The PEER_APPLICATION_REGISTRATION_INFO structure is never transmitted remotely.

### `dwPublicationScope`

[PEER_PUBLICATION_SCOPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_publication_scope) enumeration value that specifies the publication scope for this application registration information. The only valid value for this member is PEER_PUBLICATION_SCOPE_INTERNET.

## Remarks

An "application" is a set of software or software components available on the peer's endpoint. Commonly, this refers to software packages that support peer networking activities, like games or other collaborative applications.

A peer application has a GUID representing a single specific application. When an application is registered for a peer, this GUID and the corresponding application can be made available to all trusted contacts of the peer, indicating the activities the peer can participate in. To deregister a peer's application, call [PeerCollabUnregisterApplication](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabunregisterapplication) with this GUID.

## See also

[PEER_APPLICATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_application)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)