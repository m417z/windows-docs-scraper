# NdisCmAddPartyComplete function

## Description

**NdisCmAddPartyComplete** returns the final status of a client's request, for which the call manager
previously returned NDIS_STATUS_PENDING, to add a party on an established multipoint VC.

## Parameters

### `Status` [in]

Specifies the final status of the call manager's add-party operation, either NDIS_STATUS_SUCCESS
or any NDIS_STATUS_*XXX* except NDIS_STATUS_PENDING.

### `NdisPartyHandle` [in]

Specifies the handle identifying the party. This handle was input to the call manager's
[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party) function.

### `CallMgrPartyContext` [in, optional]

Specifies the handle to a caller-allocated resident context area in which the call manager will
maintain party-specific state information if the add-party operation succeeded. Otherwise, this
parameter can be **NULL** because it is ignored.

### `CallParameters` [in]

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) that contains the call
parameters, originally supplied by the client, for the party to be added.

## Remarks

If a stand-alone call manager's
[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party) function returns
NDIS_STATUS_PENDING, the CM subsequently must call
**NdisCmAddPartyComplete** to notify the client and NDIS that its attempt to add a party on the
multipoint VC has completed, whether successfully or with an error.

If the client passed in traffic parameters at
*CallParameters* that did not match those already established for the multipoint VC, the designer of
the call manager must determine how to handle this condition, subject to any constraints imposed by the
network medium. Possibilities include the following:

* Set up the per-party traffic parameters if the underlying network medium supports this feature on
  multipoint VCs.
* Reset the client-supplied traffic parameters to those established for the VC when the original
  outgoing call was made before the CM calls
  **NdisCmAddPartyComplete** with NDIS_STATUS_SUCCESS as the
  *Status* .
* Change the traffic parameters for the VC and, for every party currently connected on it, to the
  client-supplied values before the CM calls
  **NdisCmAddPartyComplete** with NDIS_STATUS_SUCCESS as the
  *Status* .
* Fail the client's attempt to add a party. (This alternative implicitly forces clients to set up
  their traffic parameters for a multipoint VC with
  [NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall) and to specify the same
  traffic parameters at each subsequent call to
  [NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty) for the given multipoint
  VC.)

For some connection-oriented media , traffic parameters are per-VC in nature and, consequently,
identical for all parties on a multipoint VC.

If the CM sets
*Status* to NDIS_STATUS_SUCCESS, it must supply an explicit handle, which is usually a pointer to the
CM-allocated per-party state area, as
*CallMgrPartyContext* when it calls
**NdisCmAddPartyComplete**.

A call to
**NdisCmAddPartyComplete** causes NDIS to call the client's
[ProtocolClAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_add_party_complete) function.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmAddPartyComplete**. Connection-oriented miniport drivers that provide integrated
call-management support call
**NdisMCmAddPartyComplete** instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty)

[NdisMCmAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmaddpartycomplete)

[ProtocolClAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_add_party_complete)

[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party)