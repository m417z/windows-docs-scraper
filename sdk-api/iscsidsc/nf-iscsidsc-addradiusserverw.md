# AddRadiusServerW function

## Description

The **AddRadiusServer** function adds a new Remote Authentication Dial-In User Service (RADIUS) server to the list referenced by the iSCSI initiator service during authentication.

## Parameters

### `Address` [in]

A string that represents the IP address or DNS name associated with the RADIUS server.

## Return value

Returns ERROR_SUCCESS if the operation is successful. If the operation fails due to a socket connection error, this function will return a Winsock error code. Other possible error values include:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The supplied *Address* is invalid. |

## Remarks

When the iSCSI initiator service receives a request from the **AddRadiusServer** user-mode library function to add a RADIUS server, the initiator service saves data associated with the server in non-volatile storage. This allows the iSCSI initiator service to utilize the RADIUS server to authenticate targets or obtain authentication information.

> [!NOTE]
> The iscsidsc.h header defines AddRadiusServer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RemoveRadiusServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removeradiusservera)