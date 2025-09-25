# PROTOCOL_CM_MODIFY_QOS_CALL callback function

## Description

The
*ProtocolCmModifyCallQoS* function is required.
*ProtocolCmModifyCallQoS* is called by NDIS when a connection-oriented client requests that the call
parameters be changed for an existing virtual connection (VC). If the underlying network medium does not
support QoS,
*ProtocolCmModifyQoS* should simply return NDIS_STATUS_NOT_SUPPORTED.

**Note** You must declare the function by using the **PROTOCOL_CM_MODIFY_QOS_CALL** type.
For more information, see the following Examples section.

## Parameters

### `CallMgrVcContext` [in]

Specifies the handle to a call manager-allocated context area in which the call manager maintains
its per-VC state. The call manager supplied this handle to NDIS for its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `CallParameters` [in]

Pointer to a
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) structure that contains
the new call parameters, as specified by a connection-oriented client, for the VC.

## Return value

*ProtocolCmModifyQoS* returns the status of its operation(s) as one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the call manager successfully changed the parameters of the call with the network to the call parameters specified at *CallParameters* . |
| **NDIS_STATUS_PENDING** | Indicates that the call manager will complete the request to modify the call parameters asynchronously. When the call manager has completed all operations necessary to modify the call parameters, it must call [NdisCmModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmmodifycallqoscomplete). |
| **NDIS_STATUS_RESOURCES** | Indicates that the call manager could not change the call parameters of the VC because dynamically allocated resources were not available. |
| **NDIS_STATUS_INVALID_DATA** | Indicates that the call manager was unable to change the call parameters of the VC because the call parameters provided at *CallParameters* were illegal or invalid. |
| **NDIS_STATUS_FAILURE** | Indicates that the call parameters could not be set to the call parameters provided because of a failure in the network or in another connection-oriented network component. |

## Remarks

*ProtocolCmModifyQoS* communicates with network control devices or other media-specific agents, as
necessitated by its media, to modify the media-specific call parameters for an established virtual
connection. If the call manager is required to communicate with network control agents (in other words, a
networking switch) it should use a virtual connection to the network control agents that it established
in its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.
Stand-alone call managers communicated to the network agents by calling
[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists).
Miniport drivers with integrated call-management support never call
**NdisCoSendNetBufferLists**. Instead, such a driver simply transfers the data over the network to the
target network agent.

After communicating with the network and if the changes were successful, the call manager must then
call
[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc) with the new call
parameters. This notifies NDIS and/or the connection-oriented miniport driver that the call parameters
have changed and provides the miniport driver with an opportunity to validate those parameters.

If either the network cannot accept the new call parameters or the underlying miniport driver cannot
accept the parameters, the call manager must restore the virtual connection to the state that existed
before any modifications were attempted, and return NDIS_STATUS_FAILURE.

### Examples

To define a *ProtocolCmModifyCallQoS* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmModifyCallQoS* function that is named "MyCmModifyCallQoS", use the **PROTOCOL_CM_MODIFY_QOS_CALL** type as shown in this code example:

```
PROTOCOL_CM_MODIFY_QOS_CALL MyCmModifyCallQoS;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCmModifyCallQoS(
    NDIS_HANDLE  CallMgrVcContext,
    PCO_CALL_PARAMETERS  CallParameters
    )
  {...}
```

The **PROTOCOL_CM_MODIFY_QOS_CALL** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_MODIFY_QOS_CALL** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc)

[NdisCmModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmmodifycallqoscomplete)

[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)