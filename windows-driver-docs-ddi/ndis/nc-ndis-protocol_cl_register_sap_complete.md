# PROTOCOL_CL_REGISTER_SAP_COMPLETE callback function

## Description

A connection-oriented NDIS client that accepts incoming calls must have
a *ProtocolClRegisterSapComplete* function to complete the asynchronous operations that it initiates
with
[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap). Otherwise, such a
protocol driver's registered
*ProtocolClRegisterSapComplete* function can simply return control.

**Note** You must declare the function by using the **PROTOCOL_CL_REGISTER_SAP_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `Status` [in]

Specifies the final status of the client's call to
**NdisClRegisterSap**, which can be one of the following:

#### NDIS_STATUS_SUCCESS

The SAP has been registered both with NDIS and the call manager, which will subsequently call
[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall) whenever it receives an incoming call offer directed to the given
SAP, thereby causing NDIS to call the client's
[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call) function.

#### NDIS_STATUS_RESOURCES

NDIS or the call manager could not allocate and/or initialize necessary resources to register
and maintain the SAP.

#### NDIS_STATUS_INVALID_DATA

The client supplied an invalid specification at
*Sap* to NDIS, which it forwarded to the call manager's
[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap) function
for validation.

#### NDIS_STATUS_XXX

The call manager encountered an error in attempting to register the given SAP and NDIS
propagated this CM-determined failure status to the client.

### `ProtocolSapContext` [in]

Specifies the handle to the client's per-SAP context area, which the client originally supplied to
NDIS when it called
[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap). If the registration
is successful, NDIS retains this context handle and uses it subsequently in calls to the client's
*ProtocolClIncomingCall* function pertaining to this SAP.

### `Sap` [in]

Pointer to the client-allocated buffer containing the specification for the SAP to be opened. The
client originally passed this pointer to
**NdisClRegisterSap**.

### `NdisSapHandle` [in]

If
*Status* is NDIS_STATUS_SUCCESS, specifies an NDIS-supplied valid handle to this registered SAP,
effectively an association established with NDIS between the client and a particular call manager for
the client-specified SAP. Otherwise, this parameter is **NULL**. The client must save a valid handle,
preferably in its
*ProtocolSapContext* area, for an eventual call to
[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap).

## Remarks

NDIS calls
*ProtocolClRegisterSapComplete* to indicate that the client's previous call to
**NdisClRegisterSap** has been processed by NDIS and, if NDIS did not fail the call, by the call
manager with which the client shares the
*NdisAfHandle* that it passed to
**NdisClRegisterSap**.

To receive incoming calls through a connection-oriented NIC, a client's
[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) or
[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex) function usually registers one or more SAPs with the call manager.

To register each SAP, the client calls
**NdisClRegisterSap**, passing in the
*NdisAfHandle* that identifies the call manager from which the client wants to receive notifications
of incoming calls, and NDIS returns the client an
*NdisSapHandle* to the registered SAP if the client's call to
**NdisClRegisterSap** succeeds.
*ProtocolClRegisterSapComplete* must save each valid
*NdisSapHandle*, usually in the client's per-SAP
*ProtocolSapContext* area so it can release the SAP later with
[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap).

The format of a SAP is specific to the call manager. If the call manager does not recognize the SAP
that the client is attempting to register or if the specified SAP is already in use, the call manager can
fail the SAP registration.
*ProtocolClRegisterSapComplete* should check the input
*Status* for NDIS_STATUS_SUCCESS before proceeding further. If the attempt to register the SAP failed,
*ProtocolClRegisterSapComplete* can either release the per-SAP context area and buffer at
*Sap* that the client allocated or prepare them for reuse in another call to
**NdisClRegisterSap**.

A client can receive incoming calls on a SAP even while SAP registration is still pending, that is,
before its
*ProtocolClRegisterSapComplete* function is called.

### Examples

To define a *ProtocolClRegisterSapComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClRegisterSapComplete* function that is named "MyClRegisterSapComplete", use the **PROTOCOL_CL_REGISTER_SAP_COMPLETE** type as shown in this code example:

```
PROTOCOL_CL_REGISTER_SAP_COMPLETE MyClRegisterSapComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClRegisterSapComplete(
    NDIS_STATUS  Status,
    NDIS_HANDLE  ProtocolSapContext,
    PCO_SAP  Sap,
    NDIS_HANDLE  NdisSapHandle
    )
  {...}
```

The **PROTOCOL_CL_REGISTER_SAP_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_REGISTER_SAP_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap)

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[NdisCmRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregistersapcomplete)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist)

[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall)

[NdisMCmRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmregistersapcomplete)

[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call)

[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex)

[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap)

[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify)