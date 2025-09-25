# RemoveISNSServerW function

## Description

The **RemoveIsnsServer** function removes a server from the list of Internet Storage Name Service (iSNS) servers that the iSCSI initiator service uses to discover targets.

## Parameters

### `Address` [in]

The DNS or IP Address of the server to remove.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## Remarks

The **RemoveIsnsServer** function does not affect the list of discovered targets for the iSCSI initiator service. Targets previously discovered by the iSNS server that is being removed remain on the list of discovered targets. However, the iSNS server is also removed from the persistent list of iSNS servers.

> [!NOTE]
> The iscsidsc.h header defines RemoveISNSServer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AddIsnsServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addisnsservera)

[RefreshIsnsServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-refreshisnsservera)

[ReportIsnsServerList](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportisnsserverlista)