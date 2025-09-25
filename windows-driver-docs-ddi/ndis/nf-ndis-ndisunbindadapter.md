# NdisUnbindAdapter function

## Description

Protocol drivers call the
**NdisUnbindAdapter** function to request NDIS to close a binding to an underlying miniport
adapter.

## Parameters

### `NdisBindingHandle` [in]

A handle that the protocol driver obtained from a call to the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function. The handle
identifies the binding to close.

## Return value

**NdisUnbindAdapter** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | **NdisUnbindAdapter** successfully initiated the unbind operation. |
| **NDIS_STATUS_RESOURCES** | **NdisUnbindAdapter** failed due to insufficient resources. |

## Remarks

Protocol drivers call
**NdisUnbindAdapter** outside the context of the
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) or
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) functions.
NDIS schedules a work item to call the protocol driver's
*ProtocolUnbindAdapterEx* function and returns immediately.

Before the call to
**NdisUnbindAdapter** returns, NDIS can already have closed the binding. Therefore, after the call
returns, the caller must not assume that the handle it passed to the
*NdisBindingHandle* parameter is still valid.

**Note** NDIS might not call
*ProtocolUnbindAdapterEx* even if
**NdisUnbindAdapter** returns NDIS_STATUS_SUCCESS.

## See also

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)