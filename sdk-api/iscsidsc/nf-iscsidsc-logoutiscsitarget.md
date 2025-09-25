# LogoutIScsiTarget function

## Description

The **LogoutIscsiTarget** routine closes the specified login session.

## Parameters

### `UniqueSessionId` [in]

A pointer to a structure of type [ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id) that contains a unique session identifier for the login session end.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## Remarks

If the login session is not for informational purposes, the iSCSI initiator service ensures that all devices associated with the session can be safely removed from the device stack before allowing the initiator to close the session. If the session is an informational session, the iSCSI initiator service closes the session immediately.

## See also

[ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id)

[LoginIscsiTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-loginiscsitargeta)