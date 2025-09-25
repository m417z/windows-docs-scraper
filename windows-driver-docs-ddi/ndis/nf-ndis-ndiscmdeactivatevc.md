# NdisCmDeactivateVc function

## Description

**NdisCmDeactivateVc** notifies NDIS and the underlying miniport driver that there will be no further
transfers on a particular active VC.

## Parameters

### `NdisVcHandle` [in]

Specifies the handle identifying the VC. This handle was supplied by NDIS to the call manager
either when it called
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) for an incoming call or
when its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function set up
the VC for a client-initiated outgoing call.

## Return value

When
**NdisCmDeactivateVc** returns anything other than NDIS_STATUS_PENDING, the call manager should make
an internal call to its
[ProtocolCmDeactivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deactivate_vc_complete) function. Otherwise, NDIS calls the CM's
*ProtocolCmDeactivateVcComplete* function when this operation is completed.

## Remarks

A stand-alone call manager calls
**NdisCmDeactivateVc** as an essential step in closing a call, usually after the packet exchange with
network components that tears down the call.

A call to
**NdisCmDeactivateVc** causes NDIS to call the underlying miniport driver's
[MiniportCoDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_deactivate_vc) function,
which can discard the current call parameters for transfers on the VC, possibly reinitializing them to
miniport driver-determined default values. If the VC is reactivated subsequently for another call, the
client or call manager will supply new call parameters to the miniport driver.

The
*NdisVcHandle* passed to
**NdisCmDeactivateVc** remains valid after VC deactivation is completed. The deactivation of any VC
allows its creator to reinitialize the VC for reuse:

* Following VC deactivation and the closing of the call, a client can reuse a VC that it originally
  created to make another call with
  [NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall).
* Following VC deactivation and the closing of the call, a CM can reuse a VC that it originally
  created to indicate another incoming call to the same client with
  [NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall).

The creator of a particular VC that will not be reused calls
[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc) to destroy that VC.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmDeactivateVc**. Connection-oriented miniport drivers that provide integrated call-management
support call
**NdisMCmDeactivateVc** instead.

## See also

[MiniportCoDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_deactivate_vc)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc)

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[NdisMCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeactivatevc)

[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call)

[ProtocolCmDeactivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deactivate_vc_complete)