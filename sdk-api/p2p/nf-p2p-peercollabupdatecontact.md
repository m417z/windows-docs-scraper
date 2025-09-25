# PeerCollabUpdateContact function

## Description

The **PeerCollabUpdateContact** function updates the information associated with a peer contact specified in the local contact store of the caller.

## Parameters

### `pContact` [in]

Pointer to a [PEER_CONTACT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_contact) structure that contains the updated information for a specific peer contact.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |

## Remarks

If the contact provided is the 'Me' contact, only the nickname, display name and email address can be changed. If a nickname is changed for a contact signed in to "People Near Me", the structure [PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_people_near_me_changed_data) with *changeType* of PEER_CHANGE_UPDATED will be raised.

The **PeerCollabUpdateContact** function will timeout at 30 seconds.

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)