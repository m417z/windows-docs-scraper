# PROTOCOL_CL_INCOMING_CALL callback function

## Description

The
*ProtocolClIncomingCall* function is used by connection-oriented clients that accept incoming calls.
Such clients must have
*ProtocolClIncomingCall* functions. Otherwise, such a protocol driver's registered
*ProtocolClIncomingCall* function can simply return NDIS_STATUS_NOT_SUPPORTED.

**Note** You must declare the function by using the **PROTOCOL_CL_INCOMING_CALL** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolSapContext` [in]

Specifies the handle that the client originally supplied when it registered the SAP, which the
call manager matched to this incoming call offer.

### `ProtocolVcContext` [in]

Specifies the handle to the client's per-VC context area, previously returned to NDIS by its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `CallParameters` [in, out]

Pointer to a buffer, formatted as a
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) structure, that contains
the call parameters for this offered call.

## Return value

*ProtocolClIncomingCall* can return one of the following status codes:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The client accepted the incoming call offer. |
| **NDIS_STATUS_PENDING** | The client is handling this request asynchronously, and it will call the [NdisClIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclincomingcallcomplete) function when the close operation is complete. |
| **NDIS_STATUS_*XXX*** | The client rejected the incoming call offer for some driver-determined reason. |

## Remarks

A call to
*ProtocolClIncomingCall* indicates that the call manager has received a request over the network from
a signaling peer to establish a connection with this client. That is, the request to set up such a
connection was directed to a SAP previously registered with the call manager by this client.

Depending on the signaling protocol supported by the call manager,
*ProtocolClIncomingCall* can modify the traffic parameters as part of the process of negotiating
acceptance of an incoming call offer and/or, if the call manager supports QoS, the quality of service
specification at
*CallParameters* . The client should copy any information it will need subsequently from this
buffered structure if it accepts the offered call.

Assuming the call manager finds the client's modifications, if any, acceptable, NDIS next calls the
client's
*ProtocolClIncomingCallConnected* function when it becomes possible for transfers to occur on the
active VC representing the connection to the client on the remote node that originally initiated the call
offer. If the client returns modified call parameters that are unacceptable, the call manager can tear
down the VC it created for this offer, thereby causing calls to the client's
[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call) and then
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) functions
instead.

### Examples

To define a *ProtocolClIncomingCall* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClIncomingCall* function that is named "MyClIncomingCall", use the **PROTOCOL_CL_INCOMING_CALL** type as shown in this code example:

```
PROTOCOL_CL_INCOMING_CALL MyClIncomingCall;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyClIncomingCall(
    NDIS_HANDLE  ProtocolSapContext,
    NDIS_HANDLE  ProtocolVcContext,
    PCO_CALL_PARAMETERS  CallParameters
    )
  {...}
```

The **PROTOCOL_CL_INCOMING_CALL** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_INCOMING_CALL** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisClIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclincomingcallcomplete)

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall)

[ProtocolClCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_call_connected)

[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)