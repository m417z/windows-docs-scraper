# RefreshISNSServerA function

## Description

The **RefreshIsnsServer** function instructs the iSCSI initiator service to query the indicated Internet Storage Name Service (iSNS) server to refresh the list of discovered targets for the iSCSI initiator service.

## Parameters

### `Address` [in]

The DNS or IP Address of the iSNS server.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## Remarks

If the refresh succeeds, the iSCSI initiator service replaces the previous list of targets discovered by the indicated iSNS server with the updated list.

If the iSNS server supports State Change Notifications (SCN), the iSCSI initiator can keep the iSNS target list up to date, without requiring calls of the **RefreshIsnsServer** function.

> [!NOTE]
> The iscsidsc.h header defines RefreshISNSServer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AddIsnsServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addisnsservera)

[RemoveIsnsServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removeisnsservera)

[ReportIsnsServerList](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportisnsserverlista)