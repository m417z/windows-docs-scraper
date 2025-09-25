# PEER_INVITATION_RESPONSE structure

## Description

The **PEER_INVITATION_RESPONSE** structure contains a response to an invitation to join a peer collaboration activity.

## Members

### `action`

[PEER_INVITATION_RESPONSE_TYPE](https://learn.microsoft.com/windows/win32/api/p2p/ne-p2p-peer_invitation_response_type) enumeration value that specifies the action the peer takes in response to the invitation.

### `pwzMessage`

Reserved. This member must be set to **NULL**, and is set exclusively by the Peer Collaboration infrastructure.

### `hrExtendedInfo`

Any extended information that is part of the response. This can include an error code corresponding to the failure on the recipient of the invitation.

## See also

[PEER_INVITATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_invitation)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)