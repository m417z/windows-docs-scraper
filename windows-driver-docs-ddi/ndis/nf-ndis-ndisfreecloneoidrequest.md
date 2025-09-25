# NdisFreeCloneOidRequest function

## Description

The
**NdisFreeCloneOidRequest** function frees a cloned
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure.

## Parameters

### `SourceHandle` [in]

An NDIS handle that identifies a filter module or an intermediate driver's protocol
binding.

### `Request` [in]

A pointer to the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that is to be
freed.

## Remarks

An NDIS intermediate driver or filter driver calls
**NdisFreeCloneOidRequest** to free an NDIS_OID_REQUEST structure that was allocated by calling the
[NdisAllocateCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatecloneoidrequest) function.

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisAllocateCloneOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatecloneoidrequest)