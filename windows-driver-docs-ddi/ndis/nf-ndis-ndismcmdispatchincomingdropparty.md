# NdisMCmDispatchIncomingDropParty macro

## Description

**NdisMCmDispatchIncomingDropParty** notifies a client that it should remove a particular party on a
multipoint VC.

## Parameters

### `_S_`

Indicates the reason this party is being dropped, usually NDIS_STATUS_SUCCESS if the remote party
simply requested that its connection be closed.

### `_H_`

Specifies the handle that identifies the party to be dropped from the multipoint VC, which must
have other parties that are still connected. The MCM driver originally obtained this handle as an input
parameter to its
[ProtocolCmAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_add_party) function.

### `_B_`

Pointer to a caller-allocated resident buffer containing additional protocol-specific data
received from the remote party, if any. Depending on the underlying medium, this pointer can be
**NULL**.

### `_Z_`

Specifies the size in bytes of the buffer, zero if
*Buffer* is **NULL**.

## Remarks

In the course of normal network operations, an MCM driver calls
**NdisMCmDispatchIncomingDropParty** with the
*CloseStatus* set to NDIS_STATUS_SUCCESS because a remote client on a multipoint connection has
called
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall).

However, an MCM driver also can call
**NdisMCmDispatchIncomingDropParty** with a driver-determined
*CloseStatus* at the behest of the network itself if abnormal network conditions occur, such as the
failure of a switch on the path between the local client and one or more client(s) on an established
multipoint connection.

A call to
**NdisMCmDispatchIncomingDropParty** causes NDIS to call the client's
[ProtocolClIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_drop_party) function.

If the
*NdisPartyHandle* identifies the last remaining party on the given VC, the MCM driver calls
[NdisMCmDispatchIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingclosecall), rather than
**NdisMCmDispatchIncomingDropParty**.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmDispatchIncomingDropParty**. Stand-alone call managers, which register themselves with NDIS
as protocol drivers, call
**NdisCmDispatchIncomingDropParty** instead.

## See also

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisCmDispatchIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingdropparty)

[NdisMCmDispatchIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingclosecall)

[ProtocolClIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_drop_party)