# SetIScsiInitiatorCHAPSharedSecret function

## Description

The **SetIscsiInitiatorCHAPSharedSecret** function establishes the default Challenge Handshake Authentication Protocol (CHAP) shared secret for all initiators on the computer.

## Parameters

### `SharedSecretLength` [in]

The size, in bytes, of the shared secret contained by the buffer specified by *SharedSecret*. The shared secret must be at least 96 bits (12 bytes) for non-IPsec connections, at least 8 bits (1 byte) for IPsec connections, and less than 128 bits (16 bytes) for all connection types.

### `SharedSecret` [in]

The buffer that contains the shared secret.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## Remarks

When an initiator attempts to log in to a target, the initiator can issue a challenge if mutual CHAP is used. The target must respond to the challenge with the initiator CHAP shared secret.

The **SetIscsiInitiatorCHAPSharedSecret** function specifies the default CHAP secret that all initiators on the computer use to authenticate a target when performing mutual CHAP. Management software can specify the CHAP secret for the initiator to provide when challenged by the target when the initiator calls the [LoginIscsiTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-loginiscsitargeta) or [AddIscsiStaticTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addiscsistatictargeta) function.

## See also

[AddIscsiStaticTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addiscsistatictargeta)

[LoginIscsiTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-loginiscsitargeta)