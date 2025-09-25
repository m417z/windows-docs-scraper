# PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA structure

## Description

The **PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA** structure contains information returned when a PEER_EVENT_PEOPLE_NEAR_ME_CHANGED event is raised on a peer participating in a subnet-specific peer collaboration network.

## Members

### `changeType`

[PEER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_change_type) enumeration value that describes the type of change that occurred for a contact available on the local subnet.

### `pPeopleNearMe`

Pointer to a [PEER_PEOPLE_NEAR_ME](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_people_near_me) structure that contains the peer endpoint information for the contact on the subnet that raised the change event.

## Remarks

The information that can be changed in a peer contact include the endpoint's name or its associated IPv6 address.

 If the **changeType** is set to PEER_CHANGE_ADDED and **pEndpoint** is set to **NULL**, then the local peer has signed in. Otherwise, if **changeType** is set to PEER_CHANGE_DELETEDimplies the local peer has signed out.

## See also

[PEER_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_change_type)

[PEER_PEOPLE_NEAR_ME](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_people_near_me)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)