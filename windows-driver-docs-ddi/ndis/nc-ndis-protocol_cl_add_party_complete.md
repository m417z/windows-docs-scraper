# PROTOCOL_CL_ADD_PARTY_COMPLETE callback function

## Description

The
*ProtocolClAddPartyComplete* function is required for connection-oriented NDIS clients that set up
multipoint connections. Such clients must have
*ProtocolClAddPartyComplete* functions to complete the asynchronous operations that they initiate with
[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty). Otherwise, such a protocol
driver's registered
*ProtocolClAddPartyComplete* function can simply return control.

**Note** You must declare the function by using the **PROTOCOL_CL_ADD_PARTY_COMPLETE** type. For more
information, see the following Examples section.

## Parameters

### `Status` [in]

Specifies final status of the client-initiated add-party operation, which can be one of the
following:

#### NDIS_STATUS_SUCCESS

The given party was added on the client's active multipoint VC.

#### NDIS_STATUS_RESOURCES

NDIS could not allocate sufficient resources to track the new party.

#### NDIS_STATUS_FAILURE

The client passed an invalid
*NdisVcHandle* to
**NdisClAddParty**.

#### NDIS_STATUS_XXX

The call manager's
[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party) function
returned a CM-determined value to indicate why it could not add the party to the VC.

### `ProtocolPartyContext` [in]

Specifies the client-supplied handle originally passed to
**NdisClAddParty**.

### `NdisPartyHandle` [in]

If
*Status* is NDIS_STATUS_SUCCESS, this NDIS-supplied handle represents the association between the
call manager and client regarding this party. Otherwise, the attempt to add a party failed and the
client should consider this parameter an invalid handle.

### `CallParameters` [in]

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)), originally set up by
the client for its call to
**NdisClAddParty** but possibly modified subsequently by the call manager.

## Remarks

A call to
*ProtocolClAddPartyComplete* indicates completion of the asynchronous operation initiated when the
client called
[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty). If the input
*Status* is set to anything other than NDIS_STATUS_SUCCESS,
*ProtocolClAddPartyComplete* can release or reuse the client-allocated buffers at
*ProtocolPartyContext* and at
*CallParameters* .

If the attempt to add a party succeeded,
*ProtocolClAddPartyComplete* should save the input
*NdisPartyHandle* for subsequent calls to NDIS library functions concerning this party in the
client's
*ProtocolPartyContext* area. For example, the client must pass this handle in a subsequent call to
[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty) eventually unless the
remote party that it represents closes its connection first.

The structure at
*CallParameters* originally was allocated and initialized by the client, which passed this pointer to
**NdisClAddParty**. However, the call manager might have modified the client-supplied values to
reflect the results of the CM's negotiation with the network or with a signaling peer while processing
the client's add-party request. To determine whether the call manager made any modifications,
*ProtocolClAddPartyComplete* can check the
**Flags** member of this structure for whether CALL_PARAMETERS_CHANGED is set. If so,
*ProtocolClAddPartyComplete* must update the per-party state that the client maintains for this call
at
*ProtocolPartyContext* unless it finds the CM's modifications unacceptable. The particular signaling
protocol determines what the client can do in this case. Usually, a client calls
**NdisClDropParty** if it finds the CM-modified call parameters unacceptable.

Depending on the signaling protocol of the call manager, the traffic parameters at
*CallParameters* can be identical for all parties on any particular multipoint connection. That is,
as the client of such a call manager adds parties on a multipoint connection that the client originally
set up with
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall), it can supply only the
target address of each party and leave the traffic parameters as originally set up for the multipoint VC
each time it calls
**NdisClAddParty**.

### Examples

To define a *ProtocolClAddPartyComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClAddPartyComplete* function that is named "MyClAddPartyComplete", use the **PROTOCOL_CL_ADD_PARTY_COMPLETE** type as shown in this code example:

```
PROTOCOL_CL_ADD_PARTY_COMPLETE MyClAddPartyComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClAddPartyComplete(
    NDIS_STATUS  Status,
    NDIS_HANDLE  ProtocolPartyContext,
    NDIS_HANDLE  NdisPartyHandle,
    PCO_CALL_PARAMETERS  CallParameters
    )
  {...}
```

The **PROTOCOL_CL_ADD_PARTY_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_ADD_PARTY_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty)

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmaddpartycomplete)

[NdisMCmAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmaddpartycomplete)

[ProtocolClIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_drop_party)

[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party)