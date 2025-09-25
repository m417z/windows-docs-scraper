# NdisMCmDeactivateVc function

## Description

**NdisMCmDeactivateVc** notifies NDIS that there will be no further transfers on a particular active
VC.

## Parameters

### `NdisVcHandle` [in]

Specifies the handle identifying the VC. This handle was supplied by NDIS to the MCM driver either
when it called
[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc) for an incoming call or
when its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function set up
the VC for a client-initiated outgoing call.

## Return value

**NdisMCmDeactivateVc** can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS marked the VC as inactive. |
| **NDIS_STATUS_NOT_ACCEPTED** | The VC is already deactivated, so this call is redundant. |

## Remarks

An MCM driver calls
**NdisMCmDeactivateVc** as an essential step in closing a call, usually after the packet exchange with
network components that tears down the connection.

A successful call to
**NdisMCmDeactivateVc** allows the MCM driver to discard the current call parameters for transfers on
the VC, possibly reinitializing them to miniport driver-determined default values. However, if the VC is
reactivated subsequently for another call, the client will supply new call parameters to the miniport
driver.

The
*NdisVcHandle* passed to
**NdisMCmDeactivateVc** remains valid after VC deactivation is completed. The deactivation of any VC
allows its creator to reinitialize the VC for reuse or to destroy it:

* Following VC deactivation and the closing of the call, a client can reuse a VC that it originally
  created to make another call with
  [NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall), or it can call
  [NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc), thereby causing a call
  to the MCM driver's
  [ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function.
* Following VC deactivation and the closing of the call, an MCM driver can reuse a VC that it
  originally created to indicate another incoming call to the same client with
  [NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall), or it can call
  [NdisMCmDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeletevc).

The driver writer determines whether an MCM driver has an (internal)
*MiniportCoDeactivateVc* function that the driver calls in the context of tearing down connections
for outgoing and incoming calls.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmDeactivateVc**. Stand-alone call managers, which register themselves with NDIS as protocol
drivers, call
**NdisCmDeactivateVc** instead.

## See also

[MiniportCoDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_deactivate_vc)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc)

[NdisMCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmactivatevc)

[NdisMCmDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeletevc)

[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall)

[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)