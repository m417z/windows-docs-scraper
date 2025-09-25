# PROTOCOL_CM_DROP_PARTY callback function

## Description

The
*ProtocolCmDropParty* function is required. NDIS calls
*ProtocolCmDropParty* to request that the call manager remove a party from an existing multipoint
call.

**Note** You must declare the function by using the **PROTOCOL_CM_DROP_PARTY** type.
For more information, see the following Examples section.

## Parameters

### `CallMgrPartyContext` [in]

Specifies the handle to a call manager-allocated context area in which the call manager maintains
its per-party state. This handle was provided to NDIS in the call managers
[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party) function.

### `CloseData` [in, optional]

Pointer to a buffer containing connection-oriented client-specific data that should be sent across
the connection before the party is dropped. This parameter is **NULL** if the underlying network medium does
not support transfers of data when closing a connection.

### `Size` [in, optional]

Specifies the length, in bytes, of the buffer at
*CloseData*, zero if
*CloseData* is **NULL**.

## Return value

*ProtocolCmDropParty* returns the status of its operation(s) as one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the call manager has successfully dropped the party, sent any close data, and free the resources that were allocated for its context area. |
| **NDIS_STATUS_PENDING** | Indicates that the call manager will complete the request to drop the party asynchronously. The call manager must call [NdisCmDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdroppartycomplete) when all processing has been finished to notify NDIS and the requesting actor that the party has been dropped. |
| **NDIS_STATUS_INVALID_DATA** | Indicates that *CloseData* was specified to the call manager, but the media type does not support sending data concurrent with connection termination. |

## Remarks

*ProtocolCmDropParty* communicates with network control devices or other media-specific agents, as
necessary for its media, to drop a party from an existing multipoint call. If the call manager is
required to communicated with network control agents (such as, a networking switch) it should use a
virtual connection to the network control agents that it established in its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.

If
*CloseData* is non-**NULL** and sending data at connection termination is supported by its media type,
the call manager should transmit the data specified at
*CloseData* before completing termination. If sending data concurrent with connection termination is
not supported by the media type, the call manager should return control with
NDIS_STATUS_INVALID_DATA.

Call managers must also free any per-party resources that it allocated and stored at
*CallMgrPartyContext* . In addition, the call manager must free the buffer stored
*CallMgrPartyContext* itself. Failure to do so will result in a memory leak condition.

### Examples

To define a *ProtocolCmDropParty* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmDropParty* function that is named "MyCmDropParty", use the **PROTOCOL_CM_DROP_PARTY** type as shown in this code example:

```
PROTOCOL_CM_DROP_PARTY MyCmDropParty;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCmDropParty(
    NDIS_HANDLE  CallMgrPartyContext,
    PVOID  CloseData,
    UINT  Size
    )
  {...}
```

The **PROTOCOL_CM_DROP_PARTY** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_DROP_PARTY** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCmDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdroppartycomplete)

[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party)