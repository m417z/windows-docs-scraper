# GetIScsiIKEInfoA function

## Description

The **GetIscsiIKEInfo** function retrieves the IPsec policy and any established pre-shared key values associated with an initiator Host-Bus Adapter (HBA).

## Parameters

### `InitiatorName` [in, optional]

A string that represents the name of the initiator HBA for which the IPsec policy is established.

### `InitiatorPortNumber` [in]

A **ULONG** value that represents the port on the initiator HBA with which to associate the key. If this parameter specifies a value of **ISCSI_ALL_INITIATOR_PORTS**, all ports on the initiator are associated with the key.

### `Reserved` [in]

This value is reserved.

### `AuthInfo` [in]

A pointer to an [IKE_AUTHENTICATION_INFORMATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-ike_authentication_information) structure that contains data specifying the authentication method. Currently, only the **IKE_AUTHENTICATION_PRESHARED_KEY_METHOD** is supported.

## Return value

Returns ERROR_SUCCESS if the operation is successful. If the operation fails due to a socket connection error, this function will return a Winsock error code.

## Remarks

> [!NOTE]
> The iscsidsc.h header defines GetIScsiIKEInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).