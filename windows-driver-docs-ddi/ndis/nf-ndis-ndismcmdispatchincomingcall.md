# NdisMCmDispatchIncomingCall macro

## Description

**NdisMCmDispatchIncomingCall** informs the client of an incoming call on a SAP previously registered by
that client with the MCM driver.

## Parameters

### `_SH_`

Specifies the handle identifying the SAP. NDIS set up this handle when the client originally
called
[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap), and the MCM driver
obtained this handle as an input parameter to its
[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap) function.

### `_VH_`

Specifies the handle identifying the VC, created with
[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc) when the MCM driver
processes the incoming call offer directed to this registered SAP.

### `_CP_`

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) that specifies the call
and media parameters for the VC.

## Remarks

Before calling
**NdisMCmDispatchIncomingCall**, an MCM driver has already done the following:

* Identified the target SAP, previously registered by a particular client, for the call (actually, a
  request to make a connection) that it received over the network
* Created a VC for the incoming call with
  [NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc)
* Possibly negotiated about acceptable call parameters over the network, or accepted the call
  parameters sent from the remote node
* Activated the VC with
  [NdisMCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmactivatevc) to notify NDIS that
  it is ready for transfers on the VC in accord with the negotiated or accepted call parameters

The MCM driver's call to
**NdisMCmDispatchIncomingCall** causes NDIS to call the client's
*ProtocolClIncomingCall* function, within which the client either accepts or rejects the requested
connection. After deciding whether to accept the connection, the client calls
[NdisClIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclincomingcallcomplete),
which, in turn, calls the MCM driver's
*ProtocolCmIncomingCallComplete* function. If the client accepted the call, the MCM driver next calls
[NdisMCmDispatchCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchcallconnected). Otherwise, it deactivates (and possibly deletes) the VC it created,
after notifying the remote node that the offered call was rejected.

Only connection-oriented miniport drivers that provide integrated call-management support call
**NdisMCmDispatchIncomingCall**. Stand-alone call managers, which register themselves with NDIS as
protocol drivers, call
**NdisCmDispatchIncomingCall** instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[NdisClIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclincomingcallcomplete)

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[NdisMCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmactivatevc)

[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc)

[NdisMCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeactivatevc)

[NdisMCmDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeletevc)

[NdisMCmDispatchCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchcallconnected)

[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call)

[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete)

[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap)