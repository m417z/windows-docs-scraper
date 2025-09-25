# PeerCollabDeleteContact function

## Description

The **PeerCollabDeleteContact** function deletes a contact from the local contact store associated with the caller.

## Parameters

### `pwzPeerName` [in]

Pointer to a zero-terminated Unicode string that contains the peer name of the contact to delete. This parameter must not be **NULL**. You cannot delete the 'Me' contact.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |

## Remarks

Once a contact is deleted using **PeerCollabDeleteContact**, the presence updates provided by a subscription will no longer be available for that contact. If the contact is being watched (*fWatch* is set to **TRUE**) than PEER_EVENT_WATCHLIST_CHANGED will be raised.

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)