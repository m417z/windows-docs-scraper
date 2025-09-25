# NdisAllocateCloneOidRequest function

## Description

The
**NdisAllocateCloneOidRequest** function allocates memory for a new
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure and copies all the
information from an existing NDIS_OID_REQUEST structure to the newly allocated structure.

## Parameters

### `SourceHandle` [in]

An NDIS handle that identifies a filter module or an intermediate driver's protocol
binding.

### `OidRequest`

A pointer to an existing
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure from which NDIS
copies the information to the newly allocated structure.

### `PoolTag` [in]

A kernel pool tag. The tag is a string, delimited by single quotation marks, with as many as four
characters, usually specified in reverse order.

### `ClonedOidRequest`

A pointer to a pointer to an NDIS_OID_REQUEST structure. If NDIS returns NDIS_STATUS_SUCCESS, NDIS
provides a pointer to the new, cloned NDIS_OID_REQUEST structure; otherwise, NDIS sets the pointer value
to **NULL**.

## Return value

**NdisAllocateClonedRequest** can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS successfully allocated an NDIS_OID_REQUEST structure. The *CloneRequest* parameter contains a pointer to the NDIS_OID_REQUEST structure. |
| **NDIS_STATUS_INVALID_PARAMETER** | The allocation request failed because the NDIS handle specified at *SourceHandle* is not valid. |
| **NDIS_STATUS_RESOURCES** | The allocation request failed because NDIS did not have sufficient resources to complete the allocation request. |
| **NDIS_STATUS_FAILURE** | The driver failed to allocate the cloned structure for reasons other than those in the preceding list. |

## Remarks

To forward a request down to the underlying drivers, an NDIS intermediate driver or filter driver must
call
**NdisAllocateCloneOidRequest** to allocate a cloned
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure. A filter driver
or intermediate driver should not forward the original NDIS_OID_REQUEST structure to underlying
drivers.

**NdisAllocateCloneOidRequest** allocates new memory and copies the data from an existing
NDIS_OID_REQUEST structure to the new structure.

The driver must subsequently call the
[NdisFreeCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreecloneoidrequest) function
to free the NDIS_OID_REQUEST structure.

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisFreeCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreecloneoidrequest)