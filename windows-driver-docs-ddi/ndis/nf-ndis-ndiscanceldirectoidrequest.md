# NdisCancelDirectOidRequest function

## Description

Protocol drivers call the
**NdisCancelDirectOidRequest** function to cancel a previous direct OID request to the underlying
drivers.

## Parameters

### `NdisBindingHandle` [in]

The handle that the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function returned
that identifies the target miniport adapter on the binding.

### `RequestId` [in]

A cancellation identifier for the request. This identifier specifies the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structures that are being
canceled.

## Remarks

Protocol drivers call the
**NdisCancelDirectOidRequest** function to cancel a previously issued direct OID request. The request
ID that is passed at the
*RequestId* parameter must match the request ID in the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that was passed
in the call to the
[NdisDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdirectoidrequest) function.

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdirectoidrequest)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)