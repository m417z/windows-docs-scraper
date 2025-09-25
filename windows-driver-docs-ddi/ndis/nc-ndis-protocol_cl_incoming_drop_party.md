# PROTOCOL_CL_INCOMING_DROP_PARTY callback function

## Description

The
*ProtocolClIncomingDropParty* function is used by connection-oriented NDIS clients that set up
multipoint connections. Such clients must have
*ProtocolClIncomingDropParty* functions. Otherwise, such a protocol driver's registered
*ProtocolClIncomingDropParty* function can simply return control.

**Note** You must declare the function by using the **PROTOCOL_CL_INCOMING_DROP_PARTY** type.
For more information, see the following Examples section.

## Parameters

### `DropStatus` [in]

Indicates the reason for the party to be dropped. Usually, this is NDIS_STATUS_SUCCESS if the
party on the remote note initiated a close of its connection, but it could be any CM-determined status
if the call manager initiated this drop-party operation due to network problems that it
discovered.

### `ProtocolPartyContext` [in]

Specifies the handle to the client's per-party context area for the party to be dropped. The
client originally supplied this handle to NDIS when it called
[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty) or
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall).

### `CloseData` [in]

Pointer to a buffer containing a protocol-specific close message, possibly one supplied by the
remote client that the call manager received over the network, or this parameter can be **NULL**.

When
*DropStatus* is NDIS_STATUS_SUCCESS, this parameter is **NULL** if the underlying network medium does
not support transfers of data when closing a connection. However, any particular call manager might
define a structure to pass additional diagnostic information to its clients on drop-party operations
caused by problems on the network.

### `Size` [in]

Specifies the length, in bytes, of the buffer at
*CloseData*, zero if
*CloseData* is **NULL**.

## Remarks

A call to
*ProtocolClIncomingDropParty* indicates that the one of the following has occurred:

* The call manager has received a request over the network to close an established connection,
  identified by the
  *NdisPartyHandle* that the client stored in its per-party context area at
  *ProtocolPartyContext* .
* The call manager has detected that network problems will prevent further data transfers on the
  established connection.

In either case,
*ProtocolClIncomingDropParty* should carry out any protocol-determined operations for dropping the
party from the client's multipoint VC.
*ProtocolClIncomingDropParty* must call
[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty) or, if this is the last
remaining party on the client's multipoint VC,
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall).

*ProtocolClIncomingDropParty* should consider the
*NdisPartyHandle* that the client obtained from
[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty) or
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall) invalid.
*ProtocolClIncomingDropParty* can either release the client's per-party context area or prepare it
for reuse in a subsequent call to
**NdisClAddParty**.

### Examples

To define a *ProtocolClIncomingDropParty* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClIncomingDropParty* function that is named "MyClIncomingDropParty", use the **PROTOCOL_CL_INCOMING_DROP_PARTY** type as shown in this code example:

```
PROTOCOL_CL_INCOMING_DROP_PARTY MyClIncomingDropParty;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClIncomingDropParty(
    NDIS_STATUS  DropStatus,
    NDIS_HANDLE  ProtocolPartyContext,
    PVOID  CloseData,
    UINT  Size
    )
  {...}
```

The **PROTOCOL_CL_INCOMING_DROP_PARTY** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_INCOMING_DROP_PARTY** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmDispatchIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingdropparty)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist)

[NdisMCmDispatchIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingdropparty)