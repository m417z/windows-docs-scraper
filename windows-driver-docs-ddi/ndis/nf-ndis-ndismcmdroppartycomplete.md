# NdisMCmDropPartyComplete macro

## Description

**NdisMCmDropPartyComplete** returns the final status of a client's request, for which the MCM driver
previously returned NDIS_STATUS_PENDING, to remove a party from a multipoint VC.

## Parameters

### `_S_`

Specifies the final status of the requested operation, either NDIS_STATUS_SUCCESS or any
caller-determined NDIS_STATUS_
*XXX* except NDIS_STATUS_PENDING.

### `_H_`

Specifies the handle to the party that the client requested be dropped. The MCM driver obtained
this handle from its per-party state area designated by
*CallMgrPartyContext* that was passed as an input parameter to its
[ProtocolCmDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_drop_party) function.

## Remarks

An MCM driver must call
**NdisMCmDropPartyComplete** if its
*ProtocolCmDropParty* function previously returned NDIS_STATUS_PENDING for the given
*NdisPartyHandle* . Neither NDIS nor the client, which initiated the pended drop-party operation with
a call to
[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty), can release the
resources they allocated to maintain per-party state until the MCM driver's call to
**NdisMCmDropPartyComplete** causes a call to that client's
[ProtocolClDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_drop_party_complete) function.

If it passes NDIS_STATUS_SUCCESS for the
*Status*, the MCM driver must consider the
*NdisPartyHandle* invalid when
**NdisMCmDropPartyComplete** returns control. The MCM driver can release (or reinitialize for reuse)
any resources that it allocated to maintain state for this party after
**NdisMCmDropPartyComplete** returns control.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmDropPartyComplete**. Stand-alone call managers, which register themselves with NDIS as
protocol drivers, call
**NdisCmDropPartyComplete** instead.

## See also

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisCmDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdroppartycomplete)

[ProtocolClDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_drop_party_complete)

[ProtocolCmDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_drop_party)