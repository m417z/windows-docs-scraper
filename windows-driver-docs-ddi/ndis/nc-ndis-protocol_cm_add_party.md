# PROTOCOL_CM_ADD_PARTY callback function

## Description

The
*ProtocolCmAddParty* function is a required function.
*ProtocolCmAddParty* sets up the media-specific parameters to add a party to an existing multipoint
call, stores state data for the new party, and causes the party to be added to the call.

**Note** You must declare the function by using the **PROTOCOL_CM_ADD_PARTY** type.
For more information, see the following Examples section.

## Parameters

### `CallMgrVcContext` [in]

Specifies the handle to a call manager-allocated context area in which the call manager maintains
its per-VC state. The call manager supplied this handle to NDIS from its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `CallParameters` [in, out]

Pointer to a
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) structure that contains
the parameters, specified by a connection-oriented client, for the party that is being added to an
existing call.

### `NdisPartyHandle` [in]

Specifies a handle, supplied by NDIS, that uniquely identifies a multipoint party that is to be
added to an existing virtual connection. This handle is opaque to the call manager and reserved for NDIS
library use.

### `CallMgrPartyContext` [out]

Specifies, on return, a handle to a call manager-supplied context area in which the call manager
maintains state about this party for the multipoint call.

## Return value

*ProtocolCmAddParty* returns the status of its operation(s) as one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the call manager successfully allocated the necessary resources to maintain state about the party and successfully added the party to the call. |
| **NDIS_STATUS_PENDING** | Indicates that the call manager will complete the request to add a party asynchronously. When the call manager has completed all operations for adding the party, it must call [NdisCmAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmaddpartycomplete) to signal NDIS that this operation has been completed. |
| **NDIS_STATUS_RESOURCES** | Indicates that the call manager was unable to allocate and/or initialize its resources for adding a party to the connection. |
| **NDIS_STATUS_NOT_SUPPORTED** | Indicates that the call manager was unable to add the party to the multipoint call because the caller requested invalid or unavailable features in the call parameters at *CallParameters* or else that the media type supported by this call manager does not support multipoint calls. |

## Remarks

*ProtocolCmAddParty* performs any necessary allocations of dynamic resources and structures that the
call manager requires to maintain state information about the party, specified by
*NdisPartyHandle*, to be added to a multipoint call. Such resources could include, but are not
limited to, memory buffers, data structures, events, and other similar resources. Call managers should
also initialize relevant per-party structures in this function.

In the per-party state area that the call manager allocates, the call manager
must store the handle specified by
*NdisPartyHandle* for reference in future calls. After the call manager has allocated and finish
initializing its per-party state area, the address of the state buffer should be set as the
*CallMgrPartyContext* handle before returning control to NDIS. To do this, dereference the handle and
store a pointer to the state buffer as the value of the handle. For example:

```
*CallMgrPartyContext = SomeBuffer;
```

Call managers perform any necessary communication with their network hardware or other media-specific
actors, as necessary, to add the party specified by the call parameters at
*CallParameters* to an existing multipoint call.

### Examples

To define a *ProtocolCmAddParty* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmAddParty* function that is named "MyCmAddParty", use the **PROTOCOL_CM_ADD_PARTY** type as shown in this code example:

```
MINIPORT_ADD_DEVICE MyCmAddParty;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCmAddParty(
    NDIS_HANDLE  CallMgrVcContext,
    PCO_CALL_PARAMETERS  CallParameters,
    NDIS_HANDLE  NdisPartyHandle,
    PNDIS_HANDLE  CallMgrPartyContext
    )
  {...}
```

The **PROTOCOL_CM_ADD_PARTY** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_ADD_PARTY** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty)

[ProtocolClAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_add_party_complete)