# NdisMCmAddPartyComplete macro

## Description

**NdisMCmAddPartyComplete** returns the final status of a client's request, for which the MCM driver
previously returned NDIS_STATUS_PENDING, to add a party on an established multipoint VC.

## Parameters

### `_S_`

Specifies the final status of the MCM driver's add-party operation, either NDIS_STATUS_SUCCESS or
any NDIS_STATUS_*XXX*except NDIS_STATUS_PENDING.

### `_H_`

Specifies the handle identifying the party. The MCM driver obtained this handle as input parameter
to its
[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party) function.

### `_C_`

Specifies the handle to a caller-allocated resident context area in which the MCM driver will
maintain party-specific state information if the add-party operation succeeded. Otherwise, this
parameter can be **NULL** because it is ignored by NDIS if
*Status* is anything other than NDIS_STATUS_SUCCESS.

### `_P_`

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) that contains the call
parameters, originally supplied by the client, for the party to be added.

## Remarks

If an MCM driver's
[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party) function returns
NDIS_STATUS_PENDING, the driver must call
**NdisMCmAddPartyComplete** subsequently to notify the client and NDIS that its attempt to add a party
on the multipoint VC has completed, whether successfully or with an MCM driver-determined error
status.

The underlying network medium determines whether a client can specify per-party traffic parameters on
a multipoint VC.

If the underlying network medium does not support per-party traffic parameters on multipoint VCs, an
MCM driver can do one of the following whenever a client attempts to add a party with a specification at
*CallParameters* that does not match the already established traffic parameters for that VC:

* Reset the traffic parameters to those already established for the multipoint VC when it successfully
  adds the party on that VC.
* Change the traffic parameters for every party already on the VC when it successfully adds the new
  party.
* Reject the request to add a new party. (This alternative implicitly forces clients to set up their
  traffic parameters for a multipoint VC with
  [NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall) and to specify the same
  traffic parameters at each subsequent call to
  [NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty) for the given multipoint
  VC.)

If the MCM driver sets
*Status* to NDIS_STATUS_SUCCESS, it must supply an explicit handle, which is usually a pointer to the
driver-allocated per-party state area, as
*CallMgrPartyContext* when it calls
**NdisMCmAddPartyComplete**.

A call to
**NdisMCmAddPartyComplete** causes NDIS to call the client's
[ProtocolClAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_add_party_complete) function.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmAddPartyComplete**. Stand-alone call managers, which register themselves with NDIS as
protocol drivers, call
**NdisCmAddPartyComplete** instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty)

[NdisCmAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmaddpartycomplete)

[NdisMCmDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdroppartycomplete)

[ProtocolClAddPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_add_party_complete)

[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party)