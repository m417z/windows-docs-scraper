# PROTOCOL_CM_REG_SAP callback function

## Description

The
*ProtocolCmRegisterSap* function is a required function that is called by NDIS to request that a call
manager register a SAP (service access point) on behalf of a connection-oriented client.

**Note** You must declare the function by using the **PROTOCOL_CM_REG_SAP** type.
For more information, see the following Examples section.

## Parameters

### `CallMgrAfContext` [in]

Specifies the handle to a call manager-allocated context area in which the call manager maintains
its per-open AF state. The call manager supplied this handle to NDIS from its
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function.

### `Sap` [in]

Pointer to a media-specific CO_SAP structure that contains the specific SAP that a
connection-oriented client is registering.

### `NdisSapHandle` [in]

Specifies a handle, supplied by NDIS, that uniquely identifies this SAP. This handle is opaque to
the call manager and reserved for NDIS library use.

### `CallMgrSapContext` [out]

On return, specifies the handle to a call manager-supplied context area in which the call manager
maintains state about this SAP.

## Return value

*ProtocolCmRegisterSap* returns the status of its operation(s) as one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the call manager successfully allocated and/or initialized any necessary resources to register and maintain the SAP. In addition, it also indicates that the SAP was registered successfully as required by the network media that the call manager supports. |
| **NDIS_STATUS_PENDING** | Indicates that the call manager will complete the processing of this request asynchronously. Call managers must call [NdisCmRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregistersapcomplete) when all processing has been completed to signal NDIS that the registration is finished. |
| **NDIS_STATUS_RESOURCES** | Indicates that the call manager was unable to allocated and/or initialize its resources required to register the SAP on behalf of the connection-oriented client. |
| **NDIS_STATUS_INVALID_DATA** | Indicates that the specification provided at *Sap* is invalid or cannot be supported. |
| **NDIS_STATUS_*XXX*** | Indicates that the call manager encountered an error in attempting to register the SAP for the connection-oriented client. The return code is appropriate to the error and could be a return code propagated from another NDIS library function. |

## Remarks

*ProtocolCmMakeCall* communicates with network control devices or other media-specific agents, as
necessary, to register the SAP, as specified at
*Sap*, on the network for a connection-oriented client. Such actions could include, but are not
limited to communicating with switching hardware, communicating with a network control station, or other
actions that are appropriate to the network medium.

If a call manager is required to communicate with networking control agents (in other words, a network
switch) it should use a virtual connection to the network control agent that it established in its
*ProtocolBindAdapterEx* function. Stand-alone call managers communicate through the underlying
miniport driver by calling
[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists).
Miniport drivers with integrated call-management support never call
**NdisCoSendNetBufferLists**. Instead, they transmit the data directly across the network.

In addition,
*ProtocolCmRegisterSap* should perform any necessary allocations of dynamic resources and structures
that the call manager needs to maintain state information about the SAP on behalf of the
connection-oriented client. Such resources include, but are not limited to, memory buffers, data
structures, events, and other such similar resources. A call manager must also initialize any resources
it allocates before returning control to NDIS. Call managers must store the NDIS-supplied handle
identifying the SAP, provided at
*NdisSapHandle*, in their context area for future use.

If
*ProtocolCmRegisterSap* will return NDIS_STATUS_SUCCESS, it should, after allocating the per-SAP
state area, set the address of this state area in
*CallMgrSapContext* before returning control to NDIS. To do this, dereference
*CallMgrSapContext* and store a pointer to the data area as the value of the handle. For example:

```
*CallMgrSapContext = SomeBuffer ;
```

If the given SAP that is already registered by another connection-oriented client, the call manager
must fail the request and return NDIS_STATUS_INVALID_DATA.

After a call manager has registered a SAP on behalf of a connection-oriented client, it notifies that
client of an incoming call offer directed to that SAP by calling
[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall).

### Examples

To define a *ProtocolCmRegisterSap* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmRegisterSap* function that is named "MyCmRegisterSap", use the **PROTOCOL_CM_REG_SAP** type as shown in this code example:

```
PROTOCOL_CM_REG_SAP MyCmRegisterSap;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCmRegisterSap(
    NDIS_HANDLE  CallMgrAfContext,
    PCO_SAP  Sap,
    NDIS_HANDLE  NdisSapHandle,
    PNDIS_HANDLE  CallMgrSapContext
    )
  {...}
```

The **PROTOCOL_CM_REG_SAP** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_REG_SAP** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[NdisCmRegisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmregistersapcomplete)

[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists)

[ProtocolCmDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deregister_sap)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)