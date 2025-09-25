# PROTOCOL_CL_MODIFY_CALL_QOS_COMPLETE callback function

## Description

The
*ProtocolClModifyCallQoSComplete* function is used by connection-oriented NDIS clients that can modify
the quality of service on a connection dynamically. Such clients must have
*ProtocolClModifyCallQoSComplete* functions to complete the asynchronous operations that they initiate
with
[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos). Otherwise, such a
protocol driver's registered
*ProtocolClModifyCallQoSComplete* function can simply return control.

**Note** You must declare the function by using the **PROTOCOL_CL_MODIFY_CALL_QOS_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `Status` [in]

Specifies the final status of the client's asynchronous request to modify the call parameters for
this VC as one of the following:

#### NDIS_STATUS_SUCCESS

The QoS was modified as requested by the client.

#### NDIS_STATUS_RESOURCES

NDIS or the call manager could not modify the QoS because one of them could not allocate
sufficient resources dynamically.

#### NDIS_STATUS_INVALID_DATA

The call parameters that the client supplied to
**NdisClModifyCallQoS** were invalid.

#### NDIS_STATUS_FAILURE

The call manager could not change the QoS because of a failure on the network or in another
connection-oriented network component.

#### NDIS_STATUS_XXX

The call manager failed to change the QoS, and NDIS propagated the CM-determined failure status
to the client.

### `ProtocolVcContext` [in]

Specifies the handle to the client's per-VC context area, which the client originally supplied to
NDIS when it called
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) to set up the VC for its
outgoing call request or from its
*ProtocolCoCreateVc* function if the client accepted an incoming call on this VC.

### `CallParameters` [in]

Pointer to a buffered CO_CALL_PARAMETERS structure containing the client-specified QoS change it
requested, or, possibly, the original QoS for this VC established when the connection was activated,
which the call manager has restored.

## Remarks

A call to
*ProtocolClModifyCallQoSComplete* indicates that the call manager has completed processing of a
client-initiated request to change the quality of service on an active VC. For example, if the underlying
network medium supports dynamic QoS changes, a client can request modifications at any time on an active
VC.

If the client's call to
[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos) succeeds,
*ProtocolClModifyCallQoSComplete* can accept the QoS change by simply returning control. Otherwise,
*ProtocolClModifyCallQoSComplete* can engage in further negotiation with the call manager as long as
the client's developer places some reasonable limit on the number of possible renegotiations.
Alternatively,
*ProtocolClModifyCallQoSComplete* can simply tear down the call with
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall) whenever the call manager
rejects a request to change the QoS and the previously established QoS has become unacceptable to the
client.

### Examples

To define a *ProtocolClModifyCallQoSComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClModifyCallQoSComplete* function that is named "MyClModifyCallQoSComplete", use the **PROTOCOL_CL_MODIFY_CALL_QOS_COMPLETE** type as shown in this code example:

```
PROTOCOL_CL_MODIFY_CALL_QOS_COMPLETE MyClModifyCallQoSComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClModifyCallQoSComplete(
    NDIS_STATUS  Status,
    NDIS_HANDLE  ProtocolVcContext,
    PCO_CALL_PARAMETERS  CallParameters
    )
  {...}
```

The **PROTOCOL_CL_MODIFY_CALL_QOS_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_MODIFY_CALL_QOS_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos)

[NdisCmModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmmodifycallqoscomplete)

[NdisMCmModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmmodifycallqoscomplete)

[ProtocolCmModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_modify_qos_call)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)