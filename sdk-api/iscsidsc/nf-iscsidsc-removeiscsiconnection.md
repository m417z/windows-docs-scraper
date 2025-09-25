# RemoveIScsiConnection function

## Description

The **RemoveIscsiConnection** function removes a connection from an active session.

## Parameters

### `UniqueSessionId` [in]

A pointer to a structure of type [ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id) that specifies the unique session identifier of the session that the connection belongs to.

### `ConnectionId` [in]

A pointer to a structure of type [ISCSI_UNIQUE_CONNECTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb870817(v=vs.85)) that specifies the connection to remove.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## Remarks

The **RemoveIscsiConnection** function will not remove the last connection of a session or the leading connection of a session. The caller must close the session by calling [LogoutIscsiTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-logoutiscsitarget) to remove the last connection.

## See also

[LogoutIscsiTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-logoutiscsitarget)