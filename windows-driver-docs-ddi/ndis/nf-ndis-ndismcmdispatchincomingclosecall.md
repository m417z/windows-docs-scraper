# NdisMCmDispatchIncomingCloseCall macro

## Description

**NdisMCmDispatchIncomingCloseCall** tells a client to tear down an active or offered call, usually
because the MCM driver has received a request from the network to close the connection.

## Parameters

### `_S_`

Specifies a caller-determined NDIS_STATUS_*XXX*, indicating the reason for the disconnect request. During normal network operations, an MCM
driver passes NDIS_STATUS_SUCCESS to indicate that it has received a request, initiated by the remote
party, to close an active call.

### `_H_`

Specifies the handle to the VC of the call being disconnected. This handle was supplied by NDIS
when the VC was originally created, whether by the MCM driver with
[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc) or as an input parameter
to its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `_B_`

Pointer to a caller-allocated resident buffer containing additional protocol-specific disconnect
data, if any. Depending on the underlying medium, this pointer can be **NULL**.

### `_Z_`

Specifies the size in bytes of the buffer, zero if
*Buffer* is **NULL**.

## Remarks

In the course of normal network operations, an MCM driver calls
**NdisMCmDispatchIncomingCloseCall** with the
*CloseStatus* set to NDIS_STATUS_SUCCESS because the corresponding client on the remote node has
called
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall).

However, an MCM driver also can call
**NdisMCmDispatchIncomingCloseCall** if either of the following occur:

* The MCM driver has notified a client of an incoming call offer. When the miniport driver's
  [ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete) function is called with the client's acceptance, it validates the
  input call parameters, which that client has modified.
  *ProtocolCmIncomingCallComplete* determines that the client is proposing unsupportable call
  parameters for the connection, so it calls
  **NdisMCmDispatchIncomingCloseCall**.
* Abnormal network conditions force the MCM driver to tear down active calls. For example, if the MCM
  driver is notified when any link on the connection between this client and the remote party to the
  connection goes down, the miniport driver would call
  **NdisCmDispatchIncomingCloseCall** to prevent the client from attempting (or expecting) further data
  transfers on such a broken connection.

After the client calls
**NdisClCloseCall** thereby causing the deactivation of the VC, the original creator of the VC is
responsible for destroying the VC. Either the client calls
[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc), which causes NDIS to call
the MCM driver's
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function, or the
MCM driver calls
**NdisMCmDeleteVc** after calling
[NdisMCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeactivatevc) and releasing any
additional resources it had associated with the VC that it created.

A call to
**NdisMCmDispatchIncomingCloseCall** causes NDIS to call the client's
[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call) function.

Only connection-oriented miniport drivers that provide call-management support can call
**NdisMCmDispatchIncomingCall**. Stand-alone call managers, which register themselves with NDIS as
protocol drivers, call
**NdisCmDispatchIncomingCloseCall** instead.

## See also

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisMCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeactivatevc)

[NdisMCmDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeletevc)

[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall)

[NdisMCmDispatchIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingdropparty)

[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)