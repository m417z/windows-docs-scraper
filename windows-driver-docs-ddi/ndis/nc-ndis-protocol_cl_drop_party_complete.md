# PROTOCOL_CL_DROP_PARTY_COMPLETE callback function

## Description

The
*ProtocolClDropPartyComplete* function is used by connection-oriented NDIS clients that set up
multipoint connections. Such clients must have
*ProtocolClDropPartyComplete* functions to complete the asynchronous operations that they initiate with
[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty). Otherwise, such a protocol
driver's registered
*ProtocolClDropPartyComplete* function can simply return control.

**Note** You must declare the function by using the **PROTOCOL_CL_DROP_PARTY_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `Status` [in]

Specifies the final status of the client-initiated drop-party operation, which can be one of the
following:

#### NDIS_STATUS_SUCCESS

The party has been dropped. The
*NdisPartyHandle* that represented this party, which the client stored in its
*ProtocolPartyContext* area, is now invalid.

#### NDIS_STATUS_FAILURE

The given party was the last remaining on the client's multipoint VC. Therefore, the client
should call
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall) to drop this
party.

### `ProtocolPartyContext` [in]

Specifies the handle to the client's per-party context area, which the client originally supplied
to NDIS either when it called
[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty) or
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall).

## Remarks

A call to
*ProtocolClDropPartyComplete* indicates that the call manager has completed processing of the request
initiated by the client's previous call to
[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty).
*ProtocolClDropPartyComplete* can either release the client-allocated per-party context area or
prepare it for reuse in a subsequent call to
**NdisClAddParty**.

If the client is in the process of tearing down a multipoint VC that it created,
*ProtocolClDropPartyComplete* can call
**NdisClDropParty** with any valid
*NdisPartyHandle* to one of the remaining parties on the client's active multipoint VC. If only one
more party remains on its multipoint VC, the client should drop that party by passing its
*NdisPartyHandle* to
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall).

### Examples

To define a *ProtocolClDropPartyComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClDropPartyComplete* function that is named "MyClDropPartyComplete", use the **PROTOCOL_CL_DROP_PARTY_COMPLETE** type as shown in this code example:

```
PROTOCOL_CL_DROP_PARTY_COMPLETE MyClDropPartyComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClDropPartyComplete(
    NDIS_STATUS  Status,
    NDIS_HANDLE  ProtocolPartyContext
    )
  {...}
```

The **PROTOCOL_CL_DROP_PARTY_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_DROP_PARTY_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdroppartycomplete)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist)

[NdisMCmDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdroppartycomplete)

[ProtocolCmDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_drop_party)