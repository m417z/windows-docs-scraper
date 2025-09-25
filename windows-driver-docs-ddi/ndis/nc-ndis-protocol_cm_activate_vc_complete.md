# PROTOCOL_CM_ACTIVATE_VC_COMPLETE callback function

## Description

The
*ProtocolCmActivateVcComplete* function is required. This function indicates to the call manager that a
previous call to
**NdisCoActivateVc** has been completed by the miniport driver.

**Note** You must declare the function by using the **PROTOCOL_CM_ACTIVATE_VC_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `Status` [in]

Specifies the final status, as indicated by the miniport driver, of the request by the call
manager to activate a VC.

### `CallMgrVcContext` [in]

Specifies the handle to a call manager-allocated context area in which the call manager maintains
its per-VC state. The call manager supplied this handle from its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `CallParameters` [in]

Pointer to the call parameters as specified by the call manager in a call to
[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc).

## Remarks

When other network components have completed their operations for activating a virtual connection,
initiated when the call manager called
**NdisCmActivateVc**, NDIS notifies the call manager that the VC has been activated by calling its
*ProtocolCmActivateVcComplete* function. The status of the activation is found in
*Status* . Possible values for
*Status* include, but are not limited to:

*ProtocolCmActivateVcComplete* must check the status returned in
*Status* to ensure that the virtual connection has been activated successfully. The call manager
must not attempt to communicate over the virtual connection if
*Status* is not NDIS_STATUS_SUCCESS.

Call managers must complete any processing required by their network media to ensure that the virtual
connection is ready for data transmission before returning control to NDIS.

If the call manager specified either ROUND_UP_FLOW or ROUND_DOWN_FLOW in the
*CallParameters* ->
**MediaParameters->Flags**, the call parameters returned in
*CallParameters* can have been changed by the miniport driver. Call managers should examine the call
parameters that were returned to ensure proper operation. If the new call parameters are unsatisfactory,
the call manager should either call
[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc) again with new call
parameters or deactivate the VC with
[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc).

### Examples

To define a *ProtocolCmActivateVcComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmActivateVcComplete* function that is named "MyCmActivateVcComplete", use the **PROTOCOL_CM_ACTIVATE_VC_COMPLETE** type as shown in this code example:

```
PROTOCOL_CM_ACTIVATE_VC_COMPLETE MyCmActivateVcComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCmActivateVcComplete(
    NDIS_STATUS  Status,
    NDIS_HANDLE  CallMgrVcContext,
    PCO_CALL_PARAMETERS  CallParameters
    )
  {...}
```

The **PROTOCOL_CM_ACTIVATE_VC_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_ACTIVATE_VC_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc)

[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc)

[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call)