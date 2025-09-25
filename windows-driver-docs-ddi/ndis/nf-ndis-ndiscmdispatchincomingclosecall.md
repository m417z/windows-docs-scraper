# NdisCmDispatchIncomingCloseCall function

## Description

**NdisCmDispatchIncomingCloseCall** tells a client to tear down an active or offered call, usually
because the call manager has received a request from the network to close the connection.

## Parameters

### `CloseStatus` [in]

Specifies a CM-determined NDIS_STATUS_*XXX*, indicating the reason for the disconnect request. During normal network operations, a call
manager passes NDIS_STATUS_SUCCESS to indicate that it has received a request, initiated by the remote
party, to close an active call.

### `NdisVcHandle` [in]

Specifies the handle to the VC of the call being disconnected. This handle was supplied by NDIS
when the VC was originally created, whether by the call manager or client, with
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc).

### `Buffer` [in, optional]

Pointer to a caller-allocated resident buffer containing additional protocol-specific disconnect
data, if any. Depending on the underlying medium, this pointer can be **NULL**

### `Size` [in]

Specifies the size in bytes of the buffer, zero if
*Buffer* is **NULL**.

## Remarks

In the course of normal network operations, a stand-alone CM calls
**NdisCmDispatchIncomingCloseCall** with the
*CloseStatus* set to NDIS_STATUS_SUCCESS because the corresponding client on the remote node has
called
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall).

However, a call manager also can call
**NdisCmDispatchIncomingCloseCall** if either of the following occurs:

* The call manager has notified a client of an incoming call offer. When the CM's
  [ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete) function is called with the client's acceptance, it validates the
  input call parameters, which that client has modified.
  *ProtocolCmIncomingCallComplete* determines that the client is proposing unsupportable call
  parameters for the connection, so it calls
  **NdisCmDispatchIncomingCloseCall**.
* Abnormal network conditions force the call manager to tear down active calls. For example, if the
  call manager is notified when any link on the connection between this client and the remote party to
  the connection goes down, the CM would call
  **NdisCmDispatchIncomingCloseCall** to prevent the client from attempting (or expecting) further data
  transfers on such a broken connection.

After tearing down any call, the original creator of the VC is responsible for calling
[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc) after releasing any
additional resources it had associated with the VC.

A call to
**NdisCmDispatchIncomingCloseCall** causes NDIS to call the client's
[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call) function.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmDispatchIncomingCloseCall**. Connection-oriented miniport drivers that provide call-management
support call
[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall) instead.

## See also

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisCmDispatchIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingdropparty)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[NdisMCmDispatchIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingclosecall)

[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call)

[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists)

[ProtocolCoStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_status_ex)