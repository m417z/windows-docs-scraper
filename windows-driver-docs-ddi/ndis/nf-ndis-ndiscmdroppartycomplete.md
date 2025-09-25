# NdisCmDropPartyComplete function

## Description

**NdisCmDropPartyComplete** returns the final status of a client's request, for which the call manager
previously returned NDIS_STATUS_PENDING, to remove a party from a multipoint VC.

## Parameters

### `Status` [in]

Specifies the final status of the requested operation, either NDIS_STATUS_SUCCESS or any
CM-determined NDIS_STATUS_
*XXX* except NDIS_STATUS_PENDING.

### `NdisPartyHandle` [in]

Specifies the handle to the party that the client requested to be dropped. The call manager
obtained this handle from the state area designated by
*CallMgrPartyContext* that was passed as an input parameter to its
[ProtocolCmDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_drop_party) function.

## Remarks

A stand-alone call manager must call
**NdisCmDropPartyComplete** if its
*ProtocolCmDropParty* function previously returned NDIS_STATUS_PENDING for the given
*NdisPartyHandle* . Neither NDIS nor the client, which initiated the pended drop-party operation with
a call to
[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty), can release the
resources they allocated to maintain per-party state until the CM's call to
**NdisCmDropPartyComplete** causes a call to that client's
[ProtocolClDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_drop_party_complete) function.

If it passes NDIS_STATUS_SUCCESS for the
*Status*, the call manager should consider the
*NdisPartyHandle* invalid as soon as it calls
**NdisCmDropPartyComplete**. The CM can release (or reinitialize for reuse) any resources that it
allocated to maintain state for this party when
**NdisCmDropPartyComplete** returns control.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmDropPartyComplete**. Connection-oriented miniport drivers that provide integrated
call-management support call
**NdisMCmDropPartyComplete** instead.

## See also

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisMCmDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdroppartycomplete)

[ProtocolClDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_drop_party_complete)

[ProtocolCmDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_drop_party)