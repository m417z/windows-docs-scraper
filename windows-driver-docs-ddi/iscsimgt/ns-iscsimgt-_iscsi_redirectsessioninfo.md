# _ISCSI_RedirectSessionInfo structure

## Description

This ISCSI_RedirectSessionInfo structure contains information about an iSCSI session and its portal information resulted from iSCSI target redirection.

## Members

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in their UniqueSessionId parameter. Do not confuse this value with the values in the ISID and TSID members.

### `TargetPortalGroupTag`

Target portal group tag for this session Id.

### `ConnectionCount`

Number of connections for each session.

### `RedirectPortalList`

This provides the redirection information, and it has as many entries as the number of connections for each session.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)