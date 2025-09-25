# PROTOCOL_CM_INCOMING_CALL_COMPLETE callback function

## Description

The
*ProtocolCmIncomingCallComplete* function is required. When NDIS calls this function,
*ProtocolCmIncomingCallComplete* indicates to the call manager that the connection-oriented client has
finished processing of an incoming call offer that the call manager previously dispatched through
[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall).

**Note** You must declare the function by using the **PROTOCOL_CM_INCOMING_CALL_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `Status` [in]

Indicates the final status of the operation to dispatch an incoming call to a connection-oriented
client.

### `CallMgrVcContext` [in]

Specifies the handle to a call manager-allocated context area in which the call manager maintains
its per-VC state. The call manager supplied this handle from its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `CallParameters` [in]

Pointer to the call parameters as specified by the call manager in the call to
[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall).
The signaling protocol determines which call parameters, if any, the call manager can change.

## Remarks

When the connection-oriented client has completed processing of an incoming connection offer that the
call manager dispatched to it, this routine will be called if
**NdisCmDispatchIncomingCall** returned NDIS_STATUS_PENDING. The final status of the incoming call is
found in
*Status*. Possible values for
*Status* include, but are not limited to:

If the client accepts the incoming call, the call manager should send signaling message(s) to indicate
to the calling entity that the call has been accepted. If the client does not accept the call, the call
manager should send signaling message(s) to indicate that the call has been rejected.

### Examples

To define a *ProtocolCmIncomingCallComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmIncomingCallComplete* function that is named "MyCmIncomingCallComplete", use the **PROTOCOL_CM_INCOMING_CALL_COMPLETE** type as shown in this code example:

```
PROTOCOL_CM_INCOMING_CALL_COMPLETE MyCmIncomingCallComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCmIncomingCallComplete(
    NDIS_STATUS  Status,
    NDIS_HANDLE  CallMgrVcContext,
    PCO_CALL_PARAMETERS  CallParameters
    )
  {...}
```

The **PROTOCOL_CM_INCOMING_CALL_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_INCOMING_CALL_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call)

[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap)