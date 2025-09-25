# PROTOCOL_CO_AF_REGISTER_NOTIFY callback function

## Description

The
*ProtocolCoAfRegisterNotify* function is used by connection-oriented NDIS clients. All
connection-oriented NDIS clients must have fully functional
*ProtocolCoAfRegisterNotify* functions. Stand-alone connection-oriented call managers have registered
*ProtocolCoAfRegisterNotify* functions that simply return control.

**Note** You must declare the function by using the **PROTOCOL_CO_AF_REGISTER_NOTIFY** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolBindingContext` [in]

Specifies the handle to the client-allocated context area in which the client protocol maintains
per-binding run-time state. The client's
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function
supplied this handle when it called
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex).

### `AddressFamily` [in]

Pointer to a buffer describing the signaling-protocol support provided by a call manager that just
registered these services with NDIS by calling
[NdisCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregisteraddressfamilyex) or
[NdisMCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmregisteraddressfamilyex).

## Return value

None

## Remarks

A call to
*ProtocolCoAfRegisterNotify* advertises a particular call manager's or MCM driver's call-management
services on an underlying connection-oriented NIC to which the client is bound.

*ProtocolCoAfRegisterNotify* examines the data at
*AddressFamily* to determine whether the client can use the services of this particular call manager.
Whether the client can make modifications in the (M)CM-supplied data at
*AddressFamily* depends on the particular signaling-protocol support of the call manager.

If the client finds the offered call-management services unacceptable,
*ProtocolCoAfRegisterNotify* returns control, and NDIS might call
*ProtocolCoAfRegisterNotify* again with the same
*ProtocolBindingContext* handle and an AF specification supplied by this or another call manager also
bound to the same underlying miniport driver. Otherwise,
*ProtocolAfRegisterNotify* allocates a per-AF context area for the client and calls
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) with
the
*AddressFamily* pointer. If this call succeeds, the client has registered its
*ProtocolClXxx* functions with NDIS for subsequent connection-oriented operations using this call manager's
services.

For example,
*ProtocolCoAfRegisterNotify* or
*ProtocolClOpenAfCompleteEx* might call
[NdisInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializenpagedlookasidelist) one or more times in preparation for dynamic allocations and
releases of per-SAP, per-VC, and/or per-party context areas that the client will need subsequently.

If it accepts incoming calls, a client's
*ProtocolCoAfRegisterNotify* or
[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex) function usually registers one or more SAPs with the call manager. After
opening that call manager's AF, the client might proceed to allocate a per-SAP state area and call
[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap) one or more times with
the
*NdisAfHandle* it obtained from
**NdisClOpenAddressFamilyEx**. If it makes outgoing calls, the client might proceed to allocated a
per-VC state area and create a VC with
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) in anticipation of an
incoming request from one of its own clients to make an outgoing call to a remote node.

### Examples

To define a *ProtocolCoAfRegisterNotify* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCoAfRegisterNotify* function that is named "MyCoAfRegisterNotify", use the **PROTOCOL_CO_AF_REGISTER_NOTIFY** type as shown in this code example:

```
PROTOCOL_CO_AF_REGISTER_NOTIFY MyCoAfRegisterNotify;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCoAfRegisterNotify(
    NDIS_HANDLE  ProtocolBindingContext,
    PCO_ADDRESS_FAMILY  AddressFamily
    )
  {...}
```

The **PROTOCOL_CO_AF_REGISTER_NOTIFY** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CO_AF_REGISTER_NOTIFY** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CO_ADDRESS_FAMILY](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545368(v=vs.85))

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregisteraddressfamilyex)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializenpagedlookasidelist)

[NdisMCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmregisteraddressfamilyex)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex)