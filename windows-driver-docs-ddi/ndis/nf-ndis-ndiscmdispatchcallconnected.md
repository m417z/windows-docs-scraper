# NdisCmDispatchCallConnected function

## Description

**NdisCmDispatchCallConnected** notifies NDIS and the client that data transfers can begin on a VC that
the call manager created for an
*incoming* call initiated on a remote node.

## Parameters

### `NdisVcHandle` [in]

Specifies the handle to the VC that represents the connection, which was created with
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) when the call manager's
[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists) function was notified of the incoming call.

## Remarks

A stand-alone CM's
[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete) function calls
**NdisCmDispatchCallConnected** to complete the final handshake for an incoming call from a remote
node, which the client has already accepted.

A call to
**NdisCmDispatchCallConnected** causes NDIS to call the client's
[ProtocolClCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_call_connected) function.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmDispatchCallConnected**. Connection-oriented miniport drivers that provide integrated
call-management support call
**NdisMCmDispatchCallConnected** instead.

## See also

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[NdisMCmDispatchCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchcallconnected)

[ProtocolClCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_call_connected)

[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete)

[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists)