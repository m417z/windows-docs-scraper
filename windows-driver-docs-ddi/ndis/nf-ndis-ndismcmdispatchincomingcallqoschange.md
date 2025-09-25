# NdisMCmDispatchIncomingCallQoSChange macro

## Description

**NdisMCmDispatchIncomingCallQoSChange** notifies a client that a request to change the quality of
service on that client's active connection has been received over the network.

## Parameters

### `_H_`

Specifies the handle to the VC for which the change in QoS is being requested. The MCM driver
obtained this handle either when it called
[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc) to set up this connection
for an incoming call or as an input parameter to its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `_P_`

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) that specifies the new
QoS, requested by the client on the remote node, for this connection.

## Remarks

An MCM driver calls
**NdisMCmDispatchIncomingCallQoSChange** to notify the client that it has received a request to modify
the QoS on an active connection. Such an MCM driver supports dynamic QoS changes on active calls, which
is a feature like QoS itself that depends on the signaling protocol.

The MCM driver should call
[NdisMCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmactivatevc) whenever it makes
changes in the call parameters for an active VC.

A call to
**NdisMCmDispatchIncomingCallQoSChange** causes NDIS to call the client's
*ProtocolClIncomingQoSChange* function. The client accepts the proposed modifications to the call
parameters for the VC by doing nothing, except possibly updating any state it maintains about the QoS for
the VC, and returning control. Otherwise, the client rejects the proposed QoS change by tearing down the
call.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmDispatchIncomingCallQoSChange**. Stand-alone call managers, which register themselves with
NDIS as protocol drivers, call
**NdisCmDispatchIncomingCallQoSChange** instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos)

[NdisCmDispatchIncomingCallQoSChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcallqoschange)

[NdisMCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmactivatevc)

[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc)

[ProtocolClIncomingCallQosChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call_qos_change)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)