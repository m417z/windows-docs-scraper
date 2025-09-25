# AddISNSServerW function

## Description

The **AddIsnsServer** function adds a new server to the list of Internet Storage Name Service (iSNS) servers that the iSCSI initiator service uses to discover targets.

## Parameters

### `Address` [in]

IP address or the DNS name of the server.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. If the operation fails, because of a problem with a socket connection, **AddIsnsServer** returns a Winsock error code. If the Address parameter does not point to a valid iSNS server name, the **AddIsnsServer** routine returns ERROR_INVALID_PARAMETER.

## Remarks

When the iSCSI initiator service receives a request from the **AddIsnsServer** user-mode library function to add an iSNS server, the initiator service saves relevant data about the iSNS server in non-volatile storage. The iSCSI initiator service queries the newly added server for discovered targets immediately after adding it. From that point forward, the iSCSI initiator service automatically queries the iSNS server whenever the initiator service refreshes the target list of the iSNS server. The initiator service also refreshes the target list of the iSNS server at startup or whenever the iSNS server indicates a change.

If management software does not call **AddIsnsServer** to manually add the new iSNS servers to the service list of the iSCSI initiator service, the initiator service must rely on automatic discovery mechanisms, such as [DHCP](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/about-dynamic-host-configuration-protocol), to add new iSNS servers to the list.

> [!NOTE]
> The iscsidsc.h header defines AddISNSServer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RefreshIsnsServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-refreshisnsservera)

[RemoveIsnsServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removeisnsservera)

[ReportIsnsServerList](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportisnsserverlista)