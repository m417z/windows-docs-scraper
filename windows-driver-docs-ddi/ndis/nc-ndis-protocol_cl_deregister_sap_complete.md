# PROTOCOL_CL_DEREGISTER_SAP_COMPLETE callback function

## Description

The
*ProtocolClDeregisterSapComplete* function is used by connection-oriented NDIS clients.
Connection-oriented NDIS clients that accept incoming calls must have
*ProtocolClDeregisterSapComplete* functions to complete the asynchronous operations that they initiate
with
[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap). Otherwise, such a
protocol driver's registered
*ProtocolClDeregisterSapComplete* function can simply return control.

**Note** You must declare the function by using the **PROTOCOL_CL_DEREGISTER_SAP_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `Status` [in]

Specifies the final status of the client's request to deregister its SAP, which can be one of the
following:

#### NDIS_STATUS_SUCCESS

The SAP was closed. The
*NdisSapHandle* that represented the client's previously registered SAP, which the client stored
in its
*ProtocolSapContext* area, is now invalid.

#### NDIS_STATUS_FAILURE

NDIS had marked the state of the AF as "closing," so the associated SAP represented by the
*NdisSapHandle* was already released when the client's call to
[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap) occurred.

#### NDIS_STATUS_XXX

The call manager failed the request to close the SAP for some CM-determined reason, and NDIS
propagated the status returned by its
[ProtocolCmDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deregister_sap) function to the client.

### `ProtocolSapContext` [in]

Specifies the client-supplied handle to its per-SAP context area, originally passed to NDIS with
**NdisClRegisterSap**. After the call manager has successfully deregistered this SAP, the client can
release its context area or prepare this context area for reuse.

## Remarks

A call to
*ProtocolClDeregisterSapComplete* indicates that the client's preceding call to
[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap) has been processed
by the call manager.

Unless the call manager failed the deregistration for some CM-determined reason, the client should
consider the
*NdisSapHandle* invalid when
*ProtocolClDeregisterSapComplete* is called. Consequently,
*ProtocolClDeregisterSapComplete* can release the per-SAP context area that the client allocated or
prepare it for reuse in a subsequent call to
[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap).

### Examples

To define a *ProtocolClDeregisterSapComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClDeregisterSapComplete* function that is named "MyClDeregisterSapComplete", use the **PROTOCOL_CL_DEREGISTER_SAP_COMPLETE** type as shown in this code example:

```
PROTOCOL_CL_DEREGISTER_SAP_COMPLETE MyClDeregisterSapComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClDeregisterSapComplete(
    NDIS_STATUS  Status,
    NDIS_HANDLE  ProtocolSapContext
    )
  {...}
```

The **PROTOCOL_CL_DEREGISTER_SAP_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_DEREGISTER_SAP_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap)

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisCmDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmderegistersapcomplete)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist)

[NdisMCmDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmderegistersapcomplete)

[ProtocolCmDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deregister_sap)