# NdisClCloseAddressFamily function

## Description

**NdisClCloseAddressFamily** releases
the association between a client protocol and a call manager's or MCM driver's registered AF for a
particular NIC to which the client is bound.

## Parameters

### `NdisAfHandle` [in]

Specifies the NDIS-supplied handle returned by
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex).

## Return value

When
**NdisClCloseAddressFamily** returns anything other than NDIS_STATUS_PENDING, the client should make
an internal call to its
[ProtocolClCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_af_complete) function. Otherwise, NDIS calls the client's
*ProtocolClCloseAfComplete* function when this operation is completed.

If
**NdisClCloseAddressFamily** returns NDIS_STATUS_PENDING, a client that is waiting for its
[ProtocolClCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_af_complete) function to be called should not block the current thread since this
could cause a deadlock. This is particularly important when a client calls
**NdisClCloseAddressFamily** in the
context of handling an
[NdisCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmnotifycloseaddressfamily) request. In this case, the call manager may not close the address
family until after the client has returned from handling the
**NdisCmNotifyCloseAddressFamily** request. If the client blocks the
current thread, the client will never complete the handling of the
**NdisCmNotifyCloseAddressFamily** request, thus causing a deadlock.

## Remarks

A client commonly calls
**NdisClCloseAddressFamily** from its
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function, after it closes all the client's open VCs on the binding with
calls to
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall) and/or
[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap). A client can
also call
**NdisClCloseAddressFamily** in the
context of processing an
[NdisCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmnotifycloseaddressfamily) request.

NDIS calls a client's
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function whenever an underlying NIC to which that client is bound is being
removed from the machine or is being reconfigured. A PnP reconfiguration of the underlying miniport
driver causes the call manager or MCM driver to reregister the address family it supports over that NIC.
This, in turn, causes a subsequent call to the client's
[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) function. In either scenario, the client's
*ProtocolUnbindAdapterEx* function must call
**NdisClCloseAddressFamily** with any
outstanding
*NdisAfHandle* it is currently using that depends on the underlying miniport
driver.

As a general guideline, a client should release all the resources it allocated for connection-oriented
communications through the miniport driver before its
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function calls
[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex).

The
*NdisAfHandle* passed to
**NdisClCloseAddressFamily** becomes
invalid for the client as soon as this call occurs.

Before a call to
**NdisClCloseAddressFamily**, the
client may use the
*NdisAfHandle* while the AF is open or while a
[ProtocolClNotifyCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_notify_close_af) operation is pending. If the
*ProtocolClNotifyCloseAf* function returns NDIS_STATUS_PENDING, use the handle in the
[NdisClNotifyCloseAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclnotifycloseaddressfamilycomplete) call after the close operation completes.

## See also

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap)

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[ProtocolClCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_af_complete)

[ProtocolCmCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_af)

[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)