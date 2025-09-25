# PeerCollabRegisterEvent function

## Description

The **PeerCollabRegisterEvent** function registers an application with the peer collaboration infrastructure to receive callbacks for specific peer collaboration events.

## Parameters

### `hEvent` [in]

Handle created by CreateEvent that the application is signaled on when an event is triggered. When an application is signaled, it must call [PeerCollabGetEventData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgeteventdata) to retrieve events until PEER_S_NO_EVENT_DATA is returned.

### `cEventRegistration` [in]

The number of [PEER_COLLAB_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_collab_event_registration) structures in *pEventRegistrations*.

### `pEventRegistrations` [in]

An array of [PEER_COLLAB_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_collab_event_registration) structures that specify the peer collaboration events for which the application requests notification.

### `phPeerEvent` [out]

The peer event handle returned by this function. This handle is passed to [PeerCollabGetEventData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgeteventdata) when a peer collaboration network event is raised on the peer.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_SERVICE_NOT_AVAILABLE** | An attempt was made to call [PeerCollabRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabregisterevent) from an elevated process. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |

## Remarks

If the p2phost.exe service is not running, this function will attempt to launch it for registrations that require p2phost.

If attempt is made to launch p2phost.exe from an elevated process, an error is returned. As a result, security cannot be compromised by an application mistakenly granting administrative privileges to p2phost.exe. It is not possible to launch p2phost.exe in a non-interactive mode, as it needs to display Windows dialog boxes for incoming invites.

When **PeerCollabRegisterEvent** is called on machines under heavy stress, the function may return the PEER_E_SERVICE_NOT_AVAILABLE error code.

An application can call **PeerCollabRegisterEvent** multiple times, where each call is considered to be a separate registration. When an event is registered multiple times, each registration receives a copy of the event.

## See also

[PEER_COLLAB_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_collab_event_registration)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabGetEventData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgeteventdata)