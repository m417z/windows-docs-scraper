# PROTOCOL_CL_OPEN_AF_COMPLETE_EX callback function

## Description

The
*ProtocolClOpenAfCompleteEx* function completes the opening of an address family (AF) that was started
when a CoNDIS client called the
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) function.

**Note** You must declare the function by using the **PROTOCOL_CL_OPEN_AF_COMPLETE_EX** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolAfContext` [in]

A client-supplied handle to its context area for an address AF. The client allocated this context
area and passed this handle to NDIS in its call to the
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) function.

### `NdisAfHandle` [in]

An NDIS-supplied handle to an AF, if
*Status* is NDIS_STATUS_SUCCESS. Otherwise, this parameter is **NULL**. This handle represents an
association that NDIS established between the client and a call manager that is bound to a CoNDIS
miniport adapter. If the handle is not **NULL**, the client must save the handle for use in subsequent calls
to
**NdisCl*Xxx*** and
**NdisCo*Xxx*** functions.

### `Status` [in]

The final status of the client's call to
**NdisClOpenAddressFamilyEx**, which can be any of the following:

#### NDIS_STATUS_SUCCESS

The AF has been opened, so the client can initialize its state at
*ProtocolAfContext* and use the returned handle from
*NdisAfHandle* in subsequent calls to
**NdisCl*Xxx*** and
**NdisCo*Xxx*** functions, such as
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest).

#### NDIS_STATUS_RESOURCES

The requested operation failed because NDIS or the call manager could not allocate sufficient
memory or initialize the state that one of them uses to track the client's open of the AF that
*ProtocolAfContext* specifies.

#### NDIS_STATUS_FAILURE

NDIS failed the call, possibly for one of the following reasons:

* The given AF does not match any AF that was registered for the underlying miniport driver to
  which the caller is bound.
* The caller's adapter binding is closing.
* The call manager that registered the specified AF is closing its binding to the underlying
  miniport adapter.

## Remarks

The
*ProtocolClOpenAfCompleteEx* function is required for CoNDIS clients. CoNDIS clients must provide
*ProtocolClOpenAfCompleteEx* to complete the asynchronous operations that the clients initiate by
calling the
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) function.

NDIS calls
*ProtocolClOpenAfCompleteEx* to indicate that some or all of the following have occurred:

* If all of the parameters that the client's
  [ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) function passed to the
  **NdisClOpenAddressFamilyEx** function were valid, NDIS called the
  [ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function of the
  call manager that just registered the specified AF with NDIS.
* The call manager has examined the specification that the client's
  *ProtocolCoAfRegisterNotify* function passed to
  **NdisClOpenAddressFamilyEx** at the
  *AddressFamily* parameter and returned whether it was valid for this call manager to NDIS.

If the client's attempt to open an AF fails, NDIS cleans up its saved state before calling
*ProtocolClOpenAfCompleteEx*. In this case,
*ProtocolClOpenAfCompleteEx* can release the resources that the client allocated for its call to
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) or
prepare them for reuse.

Otherwise,
*ProtocolClOpenAfCompleteEx* should set up whatever client-determined state the client will need for
subsequent operations on the newly opened AF. In particular, the client must save the handle from the
*NdisAfHandle* parameter, typically in the client's
*ProtocolAfContext* context area.

If the client accepts incoming calls, it might allocate a per-service access point (SAP) state area
and call the
[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap) function. If the
client makes outgoing calls, it might allocate a per-virtual connection (VC) state area and create a VC
with the
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) function to prepare for an
incoming request from one of the client's own clients to make an outgoing call to a remote node.

NDIS calls
*ProtocolClOpenAfCompleteEx* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *ProtocolClOpenAfCompleteEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClOpenAfCompleteEx* function that is named "MyClOpenAfCompleteEx", use the **PROTOCOL_CL_OPEN_AF_COMPLETE_EX** type as shown in this code example:

```
PROTOCOL_CL_OPEN_AF_COMPLETE_EX MyClOpenAfCompleteEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClOpenAfCompleteEx(
    NDIS_HANDLE  ProtocolAfContext,
    NDIS_HANDLE  NdisAfHandle,
    NDIS_STATUS  Status
    )
  {...}
```

The **PROTOCOL_CL_OPEN_AF_COMPLETE_EX** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_OPEN_AF_COMPLETE_EX** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)

[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify)