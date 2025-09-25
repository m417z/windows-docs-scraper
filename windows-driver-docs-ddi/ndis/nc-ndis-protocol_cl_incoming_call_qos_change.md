# PROTOCOL_CL_INCOMING_CALL_QOS_CHANGE callback function

## Description

The
*ProtocolClIncomingCallQoSChange* function is used by connection-oriented clients on networks that
support dynamic quality-of-service. Such clients must have
*ProtocolClIncomingCallQoSChange* functions. Otherwise, such a protocol driver's registered
*ProtocolClIncomingCallQoSChange* function can simply return control.

**Note** You must declare the function by using the **PROTOCOL_CL_INCOMING_CALL_QOS_CHANGE** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolVcContext` [in]

Specifies the handle to the client's per-VC context area for the VC on which a request to modify
the quality of service has come in over the network.

### `CallParameters` [in]

Pointer to a buffer, formatted as a
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) structure, that contains
the new QoS specification.

## Remarks

A call to
*ProtocolClIncomingCallQoSChange* indicates to the client that a remote peer has requested a change
in the quality of service on this call. The new quality of service is described at
*CallParameters* . The client can accept the requested change by simply returning control. Otherwise,
*ProtocolClIncomingCallQoSChange* should tear down the call with
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall).

### Examples

To define a *ProtocolClIncomingCallQoSChange* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClIncomingCallQoSChange* function that is named "MyClIncomingCallQoSChange", use the **PROTOCOL_CL_INCOMING_CALL_QOS_CHANGE** type as shown in this code example:

```
PROTOCOL_CL_INCOMING_CALL_QOS_CHANGE MyClIncomingCallQoSChange;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClIncomingCallQoSChange(
    NDIS_HANDLE  ProtocolVcContext,
    PCO_CALL_PARAMETERS  CallParameters
    )
  {...}
```

The **PROTOCOL_CL_INCOMING_CALL_QOS_CHANGE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_INCOMING_CALL_QOS_CHANGE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos)

[ProtocolCmModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_modify_qos_call)