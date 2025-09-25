# PROTOCOL_CM_OPEN_AF callback function

## Description

The
*ProtocolCmOpenAf* function is required. This function allocates per-open resources for a call manager
to interact with a connection-oriented NDIS client that is opening the address family.

**Note** You must declare the function by using the **PROTOCOL_CM_OPEN_AF** type.
For more information, see the following Examples section.

## Parameters

### `CallMgrBindingContext` [in]

For a non-integrated call manager, *CallMgrBindingContext* specifies the handle to a call manager-allocated context area in which the call managers maintains
its per-binding state information. The call manager supplied this handle when it called
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex).

For an integrated call manager (MCM), *CallMgrBindingContext* specifies the handle to a miniport-allocated context area in which the miniport maintains its per-adapter state information. The miniport supplied this handle in its [NdisMSetAttributesEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetattributesex) call (for 5.x drivers) or its [NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) call (for 6.x drivers).

### `AddressFamily` [in]

Specifies the address family that a client is opening. This address family was registered by the
call manager when it called
[NdisCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregisteraddressfamilyex).

### `NdisAfHandle` [in]

Specifies a handle, supplied by NDIS, that uniquely identifies this address family instance. This
handle is opaque to the call manager and reserved for system use.

### `CallMgrAfContext` [out]

Specifies the handle to a call manager-supplied context area in which the call manager maintains
state about this open of an address family it provides.

## Return value

*ProtocolCmOpenAf* returns the status of its operation(s) as one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the call manager has successfully allocated and initialized any resources necessary to accept requests from the client to this address family. |
| **NDIS_STATUS_PENDING** | Indicates that the requested operation is being handled asynchronously. The call manager must call [NdisCmOpenAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmopenaddressfamilycomplete) when it has completed all its open-AF operations to indicate to NDIS (and the client) that the operation(s) has been completed. |
| **NDIS_STATUS_RESOURCES** | Indicates that the call manager could not complete its necessary operation(s) because of a lack of available system resources, such as memory. |
| **NDIS_STATUS_*XXX*** | Indicates that the call manager could not set itself into a state where it can accept requests from the client to operate on this address family. This could be an error status propagated from another NDIS library function or any error status determined appropriate by the driver writer. |

## Remarks

*ProtocolCmOpenAf* performs any required allocations of dynamic resources and structures that the
call manager writer deems necessary to perform operations on behalf of the client that is opening an
instance of this address family. Such resources include, but are not limited to, memory buffers, data
structures, events, and other such similar resources. A call manager should also initialize any relevant
per-open data before returning control to NDIS.

When a call manager has allocated its per-open state area, the address of the state area should be set
in the
*CallMgrAfContext* handle before returning control to NDIS. To do this, dereference
*CallMgrAfContext* and store a pointer to the data area as the value of the handle. For example:

```
*CallMgrAfContext = SomeBuffer;
```

If
*ProtocolCmOpenAf* cannot allocate the per-open resources it needs to carry out subsequent requests
on behalf of the client opening this address family, it should free all resources that it allocated for
the open and return control to the NDIS with NDIS_STATUS_RESOURCES.

If
*ProtocolCmOpenAf* has completed its required operations and the CM is ready to accept requests from
the client,
*ProtocolCmOpenAf* should return control as quickly as possible with a status of
NDIS_STATUS_SUCCESS.

### Examples

To define a *ProtocolCmOpenAf* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmOpenAf* function that is named "MyCmOpenAf", use the **PROTOCOL_CM_OPEN_AF** type as shown in this code example:

```
PROTOCOL_CM_OPEN_AF MyCmOpenAf;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCmOpenAf(
    NDIS_HANDLE  CallMgrBindingContext,
    PCO_ADDRESS_FAMILY  AddressFamily,
    NDIS_HANDLE  NdisAfHandle,
    PNDIS_HANDLE  CallMgrAfContext
    )
  {...}
```

The **PROTOCOL_CM_OPEN_AF** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_OPEN_AF** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[NdisCmOpenAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmopenaddressfamilycomplete)

[NdisCmRegisterAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregisteraddressfamilyex)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)