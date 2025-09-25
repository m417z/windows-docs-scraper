# PROTOCOL_CO_CREATE_VC callback function

## Description

The
*ProtocolCoCreateVc* function is a required function that allocates resources necessary for a call
manager or client to activate and maintain a virtual connection (VC).

**Note** You must declare the function by using the **PROTOCOL_CO_CREATE_VC** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolAfContext` [in]

Specifies the handle to a protocol-allocated context area in which the call manager or client
maintains its per-open state. The call manager supplied this handle from its
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function. The client
supplied this handle when it called
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) from
its
*ProtocolCoAfRegisterNotify* function.

### `NdisVcHandle` [in]

Specifies a handle, supplied by NDIS, that uniquely identifies this virtual connection. This
handle is opaque to the protocol driver and reserved for NDIS library use. However, the call manager and
client must save this handle to pass in subsequent calls to
**NdisCo/Cl/Cm/MCm*Xxx*** functions that concern this VC.

### `ProtocolVcContext` [out]

Specifies the handle to a protocol-supplied context area in which the call manager or client
maintains state about this virtual connection.

## Return value

*ProtocolCoCreateVc* returns the status of its operation(s) as one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the call manager or client successfully allocated and/or initialized any necessary resources that were needed to establish and maintain a virtual connection. |
| **NDIS_STATUS_RESOURCES** | Indicates that the call manager or client was unable to allocate and/or initialize its resources for establishing and maintaining a virtual connection. |
| **NDIS_STATUS_*XXX*** | Indicates that the call manager or client could not set itself into a state where it could establish a virtual connection. This can could be an error return value propagated from another NDIS library routine.<br><br>**Note** Call managers or clients cannot return NDIS_STATUS_PENDING from their *ProtocolCoCreateVc* functions. Returning pending will render this virtual connection unusable and the NDIS library will call the client or call manager to delete it. |

## Remarks

The
*ProtocolCoCreateVc* function of a call manager or client is called whenever the corresponding client
or call manager, respectively, calls
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc). Clients initiate the
creation of VCs in the process of setting up their outgoing calls before they call
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall). A call manager initiates
the creation of a VC in the process of notifying its client that the CM received an incoming call offer
from a remote node that is directed to a SAP already registered with the CM by that client before the CM
calls
[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall).

*ProtocolCoCreateVc* performs any necessary allocations of dynamic resources and structures that the
call manager or client requires to perform subsequent operations on a VC that will be activated. Such
resources include, but are not limited to, memory buffers, data structures, events, and other such
similar resources. Call managers and clients should also initialize any relevant per-VC structures that
they will need when a call is established.

Connection-oriented protocol drivers must store the handle for the VC, specified in
*NdisVcHandle*, in their per-VC state area to be used in future operations on this virtual
connection. The
*NdisVcHandle* is as required parameter to the
**NdisCo*Xxx***,
**NdisCm*Xxx***, and/or
**NdisCl*Xxx*** that such a connection-oriented protocol subsequently calls.

When a call manager or client has allocated memory for its own per-VC data and initialized its state,
the address of this data structure should be set in the handle before returning control to NDIS. To do
this, dereference the handle and store a pointer to the protocol-allocated data area as the value of the
handle. For example:

```
*ProtocolVcContext = SomeBuffer;
```

If
*ProtocolCoCreateVc* cannot allocate the resource it needs to carry out subsequent network I/O
operations, it should free all resources that were allocated for this VC and return control with a status
of NDIS_STATUS_RESOURCES.

If
*ProtocolCoCreateVc* has completed its required operations and has made the call manager or client
ready to carry out call initialization for this virtual connection,
*ProtocolCoCreateVc* should return control as quickly as possible with a status of
NDIS_STATUS_SUCCESS.

Calls to
*ProtocolCoCreateVc* are inherently synchronous in nature. That is,
*ProtocolCoCreateVc*cannot return NDIS_STATUS_PENDING.

After a call manager's
*ProtocolCoCreateVc* function returns control, the call manager's
[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call) function will be
called to establish a connection to a remote node. Call managers should not take any action in
*ProtocolCmMakeCall* that actually establishes a call because it is possible the VC will be destroyed
before a call is established due to an error condition in another component of connection-oriented
NDIS.

After a client's
*ProtocolCoCreateVc* function returns control, the client's
[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call) function
will be notified when a remote-initiated request to connect on a SAP previously registered by the client
comes in over the network.

### Examples

To define a *ProtocolCoCreateVc* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCoCreateVc* function that is named "MyCoCreateVc", use the **PROTOCOL_CO_CREATE_VC** type as shown in this code example:

```
PROTOCOL_CO_CREATE_VC MyCoCreateVc;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCoCreateVc(
    NDIS_HANDLE  ProtocolAfContext,
    NDIS_HANDLE  NdisVcHandle,
    PNDIS_HANDLE  ProtocolVcContext
    )
  {...}
```

The **PROTOCOL_CO_CREATE_VC** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CO_CREATE_VC** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call)

[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)

[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify)