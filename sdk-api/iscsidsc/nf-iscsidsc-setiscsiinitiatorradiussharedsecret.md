# SetIScsiInitiatorRADIUSSharedSecret function

## Description

The **SetIscsiInitiatorRADIUSSharedSecret** function establishes the Remote Authentication Dial-In User Service (RADIUS) shared secret.

## Parameters

### `SharedSecretLength` [in]

A **ULONG** value that represents the size, in bytes, of the shared secret contained by the buffer specified by SharedSecret. The shared secret must be at least 22 bytes, and less than, or equal to, 26 bytes in size.

### `SharedSecret` [in]

A string that specifies the buffer containing the shared secret.

## Return value

Returns **ERROR_SUCCESS** if the operation is successful. If the operation fails due to a socket connection error, this function will return a Winsock error code.

## Remarks

When an initiator attempts to log in to a target, the initiator can use the RADIUS server for authentication, or to authenticate a target. During this process the initiator uses the *SharedSecret* to communicate with the RADIUS server.

## See also

[LoginIscsiTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-loginiscsitargeta)