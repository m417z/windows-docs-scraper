# RemoveRadiusServerA function

## Description

The **RemoveRadiusServer** function removes a Remote Authentication Dial-In User Service (RADIUS) server entry from the RADIUS server list with which an iSCSI initiator is configured.

## Parameters

### `Address` [in]

A string that represents the IP address or RADIUS server name.

## Return value

Returns **ERROR_SUCCESS** if the operation is successful. If the operation fails due to a socket connection error, this function will return a Winsock error code.

## See also

[AddRadiusServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addradiusservera)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines RemoveRadiusServer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).