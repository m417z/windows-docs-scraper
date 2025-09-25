# NdisMCmDispatchCallConnected macro

## Description

**NdisMCmDispatchCallConnected** notifies NDIS and the client that data transfers can begin on a VC that
the MCM driver created for an
*incoming* call initiated on a remote node.

## Parameters

### `_H_`

Specifies the handle to the VC that represents the connection, created with
[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc) when the MCM driver set
up the VC for the incoming call.

## Remarks

An MCM driver's
[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete) function calls
**NdisMCmDispatchCallConnected** to complete the final handshake for an incoming call from a remote
node, which the local client has already accepted.

A call to
**NdisMCmDispatchCallConnected** causes NDIS to call the client's
[ProtocolClCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_call_connected) function.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmDispatchCallConnected**. Stand-alone call managers, which register themselves with NDIS as
protocol drivers, call
**NdisCmDispatchCallConnected** instead.

## See also

[NdisCmDispatchCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchcallconnected)

[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc)

[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall)

[ProtocolClCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_call_connected)

[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete)