# FwpsAleEndpointEnum0 function

## Description

The
**FwpsAleEndpointEnum0** function enumerates application layer enforcement (ALE) endpoints.

**Note** **FwpsAleEndpointEnum0** is a specific version of **FwpsAleEndpointEnum**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `engineHandle` [in]

The handle for an open session with the filter engine. This handle is obtained when a session is
opened by calling
[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0).

### `enumHandle` [in]

The enumeration handle created by a previous call to
[FwpsAleEndpointDestroyEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointdestroyenumhandle0).

### `numEntriesRequested` [in]

The maximum number of endpoint property entries to return. The actual number of entries enumerated
is returned in
*numEntriesReturned*. The actual number is less than the requested number only if fewer endpoints
than the requested are present.

### `entries` [out]

A pointer to an array of
[FWPS_ALE_ENDPOINT_PROPERTIES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_ale_endpoint_properties0) structure pointers. Each structure contains the properties of a
single endpoint. The array contains as many elements as the value returned in
*numEntriesReturned*.

### `numEntriesReturned` [out]

On return, the number of elements in the array of endpoint property structures pointed to by
*entries*.

## Return value

The
**FwpsAleEndpointEnum0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function succeeded. |
| **Other status codes** | An error occurred. |

## Remarks

To enumerate ALE endpoints, the callout driver must first obtain an enumeration handle by calling
[FwpsAleEndpointCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointcreateenumhandle0). The handle returned is associated with any parameters specified
in the optional
*enumTemplate* parameter of
**FwpsAleEndpointCreateEnumHandle0**.

After obtaining a handle, the callout driver can call
**FwpsAleEndpointEnum0** to get information about the endpoints that match the enumeration parameters
of the handle.

Note that the localV4Address field from the returned FWPS_ALE_ENDPOINT_PROPERTIES0 is in host-byte order, while the localV6Address is in network-byte order. To use the IPv4 address
from the localV4Address field, you must call htonl() on the localV4Address to store it in an in_addr structure and ensure the sockaddr is correctly formatted.

When finished examining endpoint properties, the callout driver must call
[FwpsAleEndpointDestroyEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointdestroyenumhandle0) to release the system resources associated with the enumeration
handle.

## See also

[FwpsAleEndpointCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointcreateenumhandle0)

[FwpsAleEndpointDestroyEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointdestroyenumhandle0)

[FwpsAleEndpointGetById0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointgetbyid0)

[FwpsAleEndpointGetSecurityInfo0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointgetsecurityinfo0)

[FwpsAleEndpointSetSecurityInfo0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointsetsecurityinfo0)