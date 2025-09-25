# PROTOCOL_CM_MAKE_CALL callback function

## Description

The
*ProtocolCmMakeCall* function is a required function that sets up media specific parameters for a
virtual connection (VC) and activates the virtual connection.

**Note** You must declare the function by using the **PROTOCOL_CM_MAKE_CALL** type.
For more information, see the following Examples section.

## Parameters

### `CallMgrVcContext` [in]

Specifies the handle to a call manager-allocated context area in which the call managers maintains
its per-VC state. The call manager supplied this handle to NDIS from its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `CallParameters` [in, out]

Pointer to a
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) structure that contains
the parameters, specified by a connection-oriented client, for this outgoing call.

### `NdisPartyHandle` [in, optional]

Specifies a handle, supplied by NDIS, that uniquely identifies the initial party on the multipoint
virtual connection. This handle is opaque to the call manager and reserved for NDIS library use. This
handle is **NULL** if the client is not setting up an outgoing multipoint call.

### `CallMgrPartyContext` [out, optional]

On return, specifies a handle to a call manager-supplied context area in which the call manager
maintains state about the initial party on the multipoint call. If
*NdisPartyHandle* is **NULL**, this handle must be set to **NULL**.

## Return value

*ProtocolCmMakeCall* returns the status of its operation(s) as one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the call manager successfully allocated the necessary resources to make the call and was able to activate the virtual connection with the miniport driver. |
| **NDIS_STATUS_PENDING** | Indicates that the call manager will complete the request to make a call asynchronously. When the call manager has completed all operations for making a call, it must call [NdisCmMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmmakecallcomplete) to signal NDIS that this call has been completed. |
| **NDIS_STATUS_RESOURCES** | Indicates that the call manager was unable to allocate and/or initialize its resources for activating the virtual connection as requested by the client. |
| **NDIS_STATUS_NOT_SUPPORTED** | Indicates that the call manager was unable to activate a virtual connection because the caller requested invalid or unavailable features in the call parameters specified at *CallParameters* . |

## Remarks

If
*ProtocolCmMakeCall* is given an explicit
*NdisPartyHandle*, this VC was created by the client for a multipoint call. The call manager must
allocate and initialize any necessary resources required to maintain state information and control a
multipoint call. Such resources include, but are not limited to, memory buffers, data structures, events,
and other similar resources. If the call manager cannot allocate or initialize the needed resources for
its state area(s), it should return control to NDIS with NDIS_STATUS_RESOURCES.

*ProtocolCmMakeCall* communicates with network control devices or other media-specific actors, as
necessary, to make a connection between the local node and a remote node based on the call parameters
specified at
*CallParameters* . Such actions could include, but are not limited to, communication with switching
hardware, communications with a network control station, or other actions as appropriate to the network
medium.

If a call manager is required to communication with networking hardware (such as a networking switch)
it should use a virtual connection to the network control device that it established in its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.
Call managers communicate with their network hardware through the miniport driver by calling
[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists).
Miniport drivers with integrated call-management support will not call
**NdisCoSendNetBufferLists**, but rather will transmit the data themselves.

After a call manager has done all necessary communication with its networking hardware as required by
its medium, call managers must call
[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc).

If this call was a multipoint call, after the call manager has communicated with the networking
hardware, verified call parameters, and allocated and initialized its per-party state data, the address
of its state block should be set in the handle
*CallMgrPartyContext* before returning control to NDIS. The handle is set by dereferencing the handle
and storing a pointer to the state block as the value of the handle. For example:

```
*CallMgrPartyContext = SomeBuffer ;
```

If
*ProtocolCmMakeCall* has completed the required operations for its network and the VC has been
successfully activated through
**NdisCmActivateVc**,
*ProtocolCmMakeCall* should return control as quickly as possible with a status of
STATUS_SUCCESS.

After
*ProtocolCmMakeCall* returns control to NDIS, the call manager should expect to take no further
actions on this call to set it up.
*ProtocolCmMakeCall* is responsible for establishing the connection so that the client can make data
transfers over the network on this VC. However, the call manager can be called subsequently to modify the
call's quality of service, to add or drop parties if this is a multipoint VC, and eventually to terminate
this call.

### Examples

To define a *ProtocolCmMakeCall* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmMakeCall* function that is named "MyCmMakeCall", use the **PROTOCOL_CM_MAKE_CALL** type as shown in this code example:

```
PROTOCOL_CM_MAKE_CALL MyCmMakeCall;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCmMakeCall(
    NDIS_HANDLE  CallMgrVcContext,
    PCO_CALL_PARAMETERS  CallParameters,
    NDIS_HANDLE  NdisPartyHandle,
    PNDIS_HANDLE  CallMgrPartyContext
    )
  {...}
```

The **PROTOCOL_CM_MAKE_CALL** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_MAKE_CALL** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc)

[NdisCmMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmmakecallcomplete)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)