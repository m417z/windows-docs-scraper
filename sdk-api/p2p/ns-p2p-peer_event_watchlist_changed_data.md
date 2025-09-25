# PEER_EVENT_WATCHLIST_CHANGED_DATA structure

## Description

The **PEER_EVENT_WATCHLIST_CHANGED_DATA** structure contains information returned when a PEER_EVENT_WATCHLIST_CHANGED event is raised on a peer participating in a peer collaboration network.

## Members

### `pContact`

Pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure that contains information about the peer contact in the watchlist whose change raised the event.

### `changeType`

[PEER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_change_type) enumeration value that specifies the type of change that occurred in the peer's watchlist.

## Remarks

The PEER_EVENT_WATCHLIST_CHANGED event is raised when the watch list is changed. The watch list is composed of the contacts that have **fWatch** set to true. If a new contact is added with **fWatch** set to true, or if an existing contact's **fWatch** is changed to true, the **changeType** member is set to PEER_CHANGE_ADDED. If **fWatch** is changed to false or if a contact is deleted, **changeType** is set to PEER_CHANGE_DELETED.

The p2phost.exe service must running to receive this event. P2phost.exe is launched when an application calls [PeerCollabRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabregisterevent) on this event.

## See also

[PEER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_change_type)

[PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)