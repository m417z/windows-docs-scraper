# NdisOidRequest function

## Description

The
**NdisOidRequest** function forwards a request to the underlying drivers to query the capabilities or
status of an adapter or set the state of an adapter.

## Parameters

### `NdisBindingHandle` [in]

The handle returned by the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function that
identifies the target adapter on the binding.

### `OidRequest` [in]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that specifies
the operation requested with a given OID_*XXX* code to either query the status of an adapter or to set the state of an adapter.

## Return value

The underlying driver determines which NDIS_STATUS_*XXX* code
**NdisOidRequest** returns, but it is usually one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The request operation completed successfully. |
| **NDIS_STATUS_PENDING** | The request is being handled asynchronously, and NDIS will call the caller's [ProtocolOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_oid_request_complete) function when the request is completed. |
| **NDIS_STATUS_INVALID_OID** | The OID_*XXX* code specified in the **Oid** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)-structured buffer at *OidRequest* is invalid or unsupported by the underlying driver. |
| **NDIS_STATUS_INVALID_LENGTH or NDIS_STATUS_BUFFER_TOO_SHORT** | The value specified in the **InformationBufferLength** member of the NDIS_OID_REQUEST-structured buffer at *OidRequest* does not match the requirements for the given OID_*XXX* code. If the information buffer is too small, the **BytesNeeded** member contains the correct value for **InformationBufferLength** on return from **NdisOidRequest**. |
| **NDIS_STATUS_INVALID_DATA** | The data supplied at **InformationBuffer** in the given NDIS_OID_REQUEST structure is invalid for the given OID_*XXX* code. |
| **NDIS_STATUS_NOT_SUPPORTED or NDIS_STATUS_NOT_RECOGNIZED** | The underlying driver does not support the requested operation. |
| **NDIS_STATUS_RESOURCES** | The request could not be satisfied due to a resource shortage. Usually, this return value indicates that an attempt to allocate memory was unsuccessful, but it does not necessarily indicate that the same request, submitted later, will be failed for the same reason. |
| **NDIS_STATUS_NOT_ACCEPTED** | The underlying driver attempted the requested operation, usually a set on a NIC, but it failed. For example, an attempt to set too many multicast addresses might cause the return of this value. |
| **NDIS_STATUS_CLOSING or NDIS_STATUS_CLOSING_INDICATING** | The underlying driver failed the requested operation because a close operation is in progress. |
| **NDIS_STATUS_RESET_IN_PROGRESS** | The underlying miniport driver cannot satisfy the request at this time because it is currently resetting the affected NIC. The caller's [ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex) function was or will be called with NDIS_STATUS_RESET_START to indicate that a reset is in progress. This return value does not necessarily indicate that the same request, submitted later, will be failed for the same reason. |
| **NDIS_STATUS_FAILURE** | This value usually is a nonspecific default, returned when none of the more specific NDIS_STATUS_*XXX* caused the underlying driver to fail the request. |

## Remarks

A protocol driver must allocate sufficient memory to hold the information buffer that is associated
with the specified OID. The driver must also allocate and set up the buffer at
*OidRequest* before it calls
**NdisOidRequest**. Both buffers must be allocated from nonpaged pool because the underlying driver
runs at raised IRQL while processing the request.

**NdisOidRequest** forwards a request to underlying drivers or handles the request itself.. If the
next-lower driver is an NDIS intermediate driver, it can call
**NdisOidRequest** with an OID-specific request of its own before completing the request originally
submitted by the higher-level driver.

Some errors returned are recoverable, including the following:

That is, a driver can modify the packet at
*OidRequest* appropriately to correct the OID_*XXX* code or the size or contents of the buffer at
**InformationBuffer** and resubmit the request packet to
**NdisOidRequest**. The same packet might be satisfied on resubmission to
**NdisOidRequest** if the original call indicated a reset in progress or that a resource shortage,
which might be temporary, prevented that request from being carried out.

The NDIS library maintains bindings for underlying miniport drivers. NDIS can return information for
binding-specific queries if a given OID is associated with a system-defined medium type for which the
system provides a filter library.

For more information about the general and media-specific OIDs and their respective associated
information buffers, see
[NDIS OIDs](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_oid_request_complete)

[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex)