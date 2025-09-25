# PROTOCOL_CM_DEREGISTER_SAP callback function

## Description

The
*ProtocolCmDeregisterSap* function is required. This function is called by NDIS to request that a call
manager deregister a SAP on behalf of a connection-oriented client.

**Note** You must declare the function by using the **PROTOCOL_CM_DEREGISTER_SAP** type.
For more information, see the following Examples section.

## Parameters

### `CallMgrSapContext` [in]

Specifies the handle to a call manager-allocated context area in which the call manager maintains
its per-SAP state information. The call manager supplied this handle to NDIS from its
[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap) function.

## Return value

*ProtocolCmDeregisterSap* returns the status of its operation(s) as one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the call manager successfully removed the SAP registration and freed any resources allocated to maintain per-SAP information. |
| **NDIS_STATUS_PENDING** | Indicates that the call manager will complete the request to deregister the SAP asynchronously. The call manager must call [NdisCmDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmderegistersapcomplete) to signal NDIS when the operation is complete. |

## Remarks

*ProtocolCmDeregisterSap* communicates with network control devices or other media-specific agents,
as necessary, to deregister the SAP on the network. Such actions could include, but are not limited
to:

* Communicating with a switching hardware
* Communicating with a network control station
* Communicating with other media-specific network agents

If a call manager is required to communicate with networking control agents, such as a network switch,
it should use a virtual connection to the network control agent that it established in its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.
Stand-alone call managers communicate through the underlying miniport driver by calling
[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists).
Miniport drivers that provide integrated call-management support never call
**NdisCoSendNetBufferLists**. Instead, they transmit the data directly across the network.

In addition,
*ProtocolCmDeregisterSap* must free any dynamically-allocated resources in its per-SAP area, provided
at
*CallMgrSapContext*, as well as freeing the state area itself before returning control to NDIS.

### Examples

To define a *ProtocolCmDeregisterSap* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmDeregisterSap* function that is named "MyCmDeregisterSap", use the **PROTOCOL_CM_DEREGISTER_SAP** type as shown in this code example:

```
PROTOCOL_CM_DEREGISTER_SAP MyCmDeregisterSap;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCmDeregisterSap(
    NDIS_HANDLE  CallMgrSapContext
    )
  {...}
```

The **PROTOCOL_CM_DEREGISTER_SAP** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_DEREGISTER_SAP** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCmDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmderegistersapcomplete)

[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap)