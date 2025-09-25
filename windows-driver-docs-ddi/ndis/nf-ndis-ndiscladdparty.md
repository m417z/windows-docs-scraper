# NdisClAddParty function

## Description

**NdisClAddParty** adds a party on the client's multipoint VC.

## Parameters

### `NdisVcHandle` [in]

Pointer to the VC handle returned by
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc).

### `ProtocolPartyContext` [in]

Specifies the handle to a caller-allocated resident context area in which the client will maintain
per-party state if its call succeeds.

### `CallParameters` [in, out]

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) in which the caller has
specified the addressing information for the party to be added on its multipoint VC.

### `NdisPartyHandle` [out]

Pointer to a variable to be set by NDIS if the add-party operation succeeds.

## Return value

When
**NdisClAddParty** returns anything other than NDIS_STATUS_PENDING, the client should make an internal
call to its
[ProtocolClAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_add_party_complete) function. Otherwise, NDIS calls the client's
*ProtocolClAddPartyComplete* function when this operation is completed.

## Remarks

Before it calls
**NdisClAddParty**, a client must set up a multipoint connection on its VC with
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall), as well as allocating and
initializing its context area for the party to be added. Clients commonly pass a pointer to such a
context area as the
*ProtocolPartyContext* and a pointer to a variable within that context area as the
*NdisPartyHandle* parameters when they call
**NdisClAddParty**.

A call to
**NdisClAddParty** causes NDIS to forward this request to the
[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party) function of the
call manager with which the client shares the given
*NdisVcHandle* . The call manager either returns an error status immediately or, more commonly,
NDIS_STATUS_PENDING if it attempts to satisfy this request. If its attempt is rejected on the remote
endpoint or by the underlying miniport driver, the call manager returns a final error status, such as
NDIS_STATUS_FAILURE, when it calls
[NdisCmAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmaddpartycomplete) or
[NdisMCmAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmaddpartycomplete). The
client's
[ProtocolClAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_add_party_complete) function should check the input
*Status* argument for NDIS_STATUS_SUCCESS before proceeding further.

The underlying network medium determines whether a client can specify per-party traffic parameters on
a multipoint VC.

If the underlying network medium does not support per-party traffic parameters on multipoint VCs, a
call manager can do one of the following whenever a client attempts to add a party with a specification
at
*CallParameters* that does not match the already established traffic parameters for that VC:

* Reject the request to add a new party.
* Reset the traffic parameters to those already established for the multipoint VC when it successfully
  adds the party on that VC.
* Change the traffic parameters for every party already on the VC when it successfully adds the new
  party.

If the add-party operation succeeds, the variable at
*NdisPartyHandle* has been set by NDIS to a valid handle shared among NDIS, the client, and the call
manager. The client must treat this NDIS-supplied handle as an opaque variable to be passed, unmodified
and uninterpreted, in subsequent calls to
**NdisCl/Co*Xxx*** functions concerning the newly added party.

In turn, NDIS passes the client-supplied
*ProtocolPartyContext* handle in subsequent calls to the client's ProtocolCl*Xxx* functions that concern this newly added party, including the call to
[ProtocolClAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_add_party_complete).

Whether a multipoint call permits transfers in both directions and/or per-party transfers with
per-party traffic parameters depends on the medium of the underlying miniport driver to which the client
is bound. The
*NdisPartyHandle* represents only the specific party added by a successful call to
**NdisClAddParty**, rather than the multipoint VC. Consequently, the client can use its
*ProtocolPartyContext* area only for subsequent party-specific call-management requests. For data
transfers over network media that do not support per-party transfers or traffic parameters, the client
must use the
*NdisVcHandle* instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmaddpartycomplete)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest)

[NdisCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequestcomplete)

[NdisMCmAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmaddpartycomplete)

[ProtocolClAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_add_party_complete)

[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party)