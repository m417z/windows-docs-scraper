# NdisCloseAdapterEx function

## Description

A protocol driver calls the
**NdisCloseAdapterEx** function to release the binding and the resources that were allocated when the
driver called the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

## Parameters

### `NdisBindingHandle` [in]

The handle that NDIS provided at the
*NdisBindingHandle* parameter of
**NdisOpenAdapterEx**. This handle identifies the binding that NDIS should close.

## Return value

**NdisCloseAdapterEx** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | **NdisCloseAdapterEx** successfully closed the binding to the underlying miniport adapter. |
| **NDIS_STATUS_PENDING** | **NdisCloseAdapterEx** did not complete the close operation and the operation will be completed asynchronously. NDIS calls the protocol driver's [ProtocolCloseAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_close_adapter_complete_ex) function when the operation is complete. |

## Remarks

A protocol driver typically calls
**NdisCloseAdapterEx** from its
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function. The driver can also call
**NdisCloseAdapterEx** from its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.
For example, if the driver failed to set an OID value after it called
**NdisOpenAdapterEx**, it can call
**NdisCloseAdapterEx** from its
*ProtocolBindAdapterEx* function.

If a protocol driver must close a miniport adapter outside the context of
*ProtocolUnbindAdapterEx* or
*ProtocolBindAdapterEx*, it must call the
[NdisUnbindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunbindadapter) function.

Protocol drivers should wait for all send requests and OID requests that they originated to complete
before calling
**NdisCloseAdapterEx**.

As soon as the driver calls
**NdisCloseAdapterEx**, the handle obtained from the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function at the
*NdisBindingHandle* parameter becomes invalid.

## See also

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisUnbindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunbindadapter)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolCloseAdapterCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_close_adapter_complete_ex)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)