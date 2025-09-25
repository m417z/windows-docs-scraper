# NdisClIncomingCallComplete function

## Description

**NdisClIncomingCallComplete** returns a client's acceptance or rejection of an offered incoming call,
for which the client's
[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call) function
previously returned NDIS_STATUS_PENDING.

## Parameters

### `Status` [in]

Is set to NDIS_STATUS_SUCCESS if the client accepts the offered call. Otherwise, this parameter
can be set to any NDIS_STATUS_*XXX* except NDIS_STATUS_PENDING to indicate the client-determined reason for rejecting the
call.

### `NdisVcHandle` [in]

Specifies the handle to the VC that was created by the call manager to represent the incoming
call. The client obtained this handle from it per-VC state designated by the
*ProtocolVcContext* passed as an input parameter to its
[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call) function.

### `CallParameters` [in]

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)), specifying the call
parameters for the incoming call.

## Remarks

If a client's
[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call) function
returns NDIS_STATUS_PENDING for an offered call incoming on a particular SAP, previously registered by
the client with
[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap), the client
subsequently must call
**NdisClIncomingCallComplete** to indicate whether it is accepting or rejecting the offered call.

Before it calls
**NdisClIncomingCallComplete**, such a client can negotiate with the call manager by calling
[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos) one or more times
until both drivers reach an agreement on an acceptable quality of service for the incoming call or the
client determines it should reject the offered call because its attempts to modify the QoS reach some
client-determined limit without resulting in an agreement.

If the client has changed the call parameters passed in to its
[ProtocolClIncomingCall](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) function, it must set
the
**Flags** member in the
**CO_CALL_PARAMETERS** structure with
CALL_PARAMETERS_CHANGED when it passes these changes to
**NdisClIncomingCallComplete**. Depending on whether the call manager accepts or rejects the client's
proposed changes to the call parameters, NDIS subsequently calls either the client's
[ProtocolClCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_call_connected) function or its
[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call) function, respectively.

A call to
**NdisClIncomingCallComplete** causes NDIS to call the CM's
[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete) function. NDIS passes the client-supplied parameters of
**NdisClIncomingCallComplete** as input parameters to
*ProtocolCmIncomingCallComplete*.

If a client rejects an offered call by setting
*Status* to something other than NDIS_STATUS_SUCCESS, the client must consider the
*CallParameters* pointer invalid as soon as its call to
**NdisClIncomingCallComplete** occurs.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos)

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[ProtocolClCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_call_connected)

[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call)

[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call)

[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete)