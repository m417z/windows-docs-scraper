# PROTOCOL_CM_DEACTIVATE_VC_COMPLETE callback function

## Description

The
*ProtocolCmDeactivateVcComplete* function is a required function.
*ProtocolCmDeactivateVcComplete* completes the processing of a call manager-initiated request that the
underlying miniport driver (and NDIS) deactivate a VC for which
[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc) previously returned
NDIS_STATUS_PENDING.

**Note** You must declare the function by using the **PROTOCOL_CM_DEACTIVATE_VC_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `Status` [in]

Specifies the final status of the deactivation.

### `CallMgrVcContext` [in]

Specifies the handle to a call manager-allocated context area in which the call manager maintains
its per-VC state. The call manager supplied this handle to NDIS from its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

## Remarks

NDIS usually calls
*ProtocolCmDeactivateVcComplete* in the context of the call manager's closing down a call on behalf
of a connection-oriented client. The call manager typically calls
[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc) from its
[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call) function.
Whenever
**NdisCmDeactivateVc** returns NDIS_STATUS_PENDING, NDIS subsequently calls its
*ProtocolCmDeactivateVcComplete* function.

That is, when the underlying connection-oriented miniport driver has deactivated the VC, NDIS calls
*ProtocolCmDeactivateVcComplete*. The final status of the deactivation is found in
*Status* . Possible values for the final status include, but are not limited to:

*ProtocolCmDeactivateVcComplete* performs whatever postprocessing is necessary to complete the
deactivation of a virtual connection, such as setting flags in its state area to indicate that the
connection is inactive or releasing dynamically allocated resources used while the VC is active.

Completion of the deactivation means that all call parameters for the VC used on activation are no
longer valid. Any further use of the VC is prohibited except to reactivate it with a new set of call
parameters.

Call managers should release any resources that were allocated for the VC activation and return
control as quickly as possible. If the call manager previously returned NDIS_STATUS_PENDING from its
[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call) function and
all operations to close the call have been completed,
*ProtocolCmDeactivateVcComplete* should now call
**NdisCmCloseCallComplete**.

### Examples

To define a *ProtocolCmDeactivateVcComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmDeactivateVcComplete* function that is named "MyCmDeactivateVcComplete", use the **PROTOCOL_CM_DEACTIVATE_VC_COMPLETE** type as shown in this code example:

```
PROTOCOL_CM_DEACTIVATE_VC_COMPLETE MyCmDeactivateVcComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCmDeactivateVcComplete(
    NDIS_STATUS  Status,
    NDIS_HANDLE  CallMgrVcContext
    )
  {...}
```

The **PROTOCOL_CM_DEACTIVATE_VC_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_DEACTIVATE_VC_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportCoDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_deactivate_vc)

[NdisCmCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmclosecallcomplete)

[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc)

[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call)