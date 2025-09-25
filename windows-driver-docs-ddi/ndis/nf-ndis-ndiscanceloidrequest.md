# NdisCancelOidRequest function

## Description

Protocol drivers call the
**NdisCancelOidRequest** function to cancel a previous request to the underlying drivers.

## Parameters

### `NdisBindingHandle` [in]

The handle returned by the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function that
identifies the target adapter on the binding.

### `RequestId` [in]

A cancellation identifier for the request. This identifier specifies the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structures that are being
canceled.

## Remarks

Protocol drivers call this function to cancel a previously issued request. The request ID that is
passed at the
*RequestId* parameter must match the request ID in the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that was passed
in the call to the
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function.

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)