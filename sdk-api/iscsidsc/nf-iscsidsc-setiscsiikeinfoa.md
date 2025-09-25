# SetIScsiIKEInfoA function

## Description

The **SetIscsiIKEInfo** function establishes the IPsec policy and preshared key for the indicated initiator to use when performing iSCSI connections.

## Parameters

### `InitiatorName` [in]

The name of the initiator HBA for which the IPsec policy is established.

### `InitiatorPortNumber` [in]

The port on the initiator HBA with which to associate the key. If this parameter contains a value of **ISCSI_ALL_INITIATOR_PORTS**, all ports on the initiator are associated with the key.

### `AuthInfo` [in]

A pointer to a [IKE_AUTHENTICATION_INFORMATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-ike_authentication_information) structure that contains the authentication method. Currently, only the IKE_AUTHENTICATION_PRESHARED_KEY_METHOD is supported.

### `Persist` [in]

If **true**, this parameter indicates that the preshared key information will be stored in non-volatile memory and will persist across restarts of the computer or the iSCSI initiator service.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## See also

[GetIscsiIKEInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-getiscsiikeinfoa)

[IKE_AUTHENTICATION_INFORMATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-ike_authentication_information)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines SetIScsiIKEInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).