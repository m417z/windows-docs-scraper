# ReportRadiusServerListA function

## Description

The **ReportRadiusServerList** function retrieves the list of Remote Authentication Dial-In Service (RADIUS) servers the iSCSI initiator service uses during authentication.

## Parameters

### `BufferSizeInChar` [in, out]

A **ULONG** value that specifies the number of list elements contained by the *Buffer* parameter.

### `Buffer` [out, optional]

Pointer to a buffer that receives the list of Remote Authentication Dial-In Service (RADIUS) servers on output. Each server name is null terminated, except for the last server name, which is double null-terminated.

## Return value

Returns **ERROR_SUCCESS** if the operation is successful. If the operation fails due to a socket connection error, this function will return a Winsock error code.

## See also

[AddRadiusServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addradiusservera)

[RemoveRadiusServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removeradiusservera)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ReportRadiusServerList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).