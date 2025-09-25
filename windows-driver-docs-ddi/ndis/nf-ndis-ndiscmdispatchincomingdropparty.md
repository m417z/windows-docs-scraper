# NdisCmDispatchIncomingDropParty function

## Description

**NdisCmDispatchIncomingDropParty** notifies a client that it should remove a particular party on a
multipoint VC, usually because the call manager has received a request over the network to close an active
multipoint connection.

## Parameters

### `DropStatus` [in]

Indicates the reason this party is being dropped, usually NDIS_STATUS_SUCCESS if the remote party
simply requested that its connection be closed.

### `NdisPartyHandle` [in]

Specifies the handle that identifies the party to be dropped from the multipoint VC, which must
have other parties that are still connected.

### `Buffer` [in, optional]

Pointer to a caller-allocated resident buffer containing additional protocol-specific data
received from the remote party, if any. Depending on the underlying medium, this pointer can be
**NULL**.

### `Size` [in]

Specifies the size in bytes of the buffer, zero if
*Buffer* is **NULL**.

## Remarks

In the course of normal network operations, a stand-alone call manager's
[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists) function calls
**NdisCmDispatchIncomingDropParty** with the
*CloseStatus* set to NDIS_STATUS_SUCCESS because a remote client on a multipoint connection has
called
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall).

However, a call manager also can call
**NdisCmDispatchIncomingDropParty** with a CM-determined
*CloseStatus* at the behest of the network itself if abnormal network conditions occur, such as the
failure of a switch on the path between the local client and one or more client(s) on an established
multipoint connection.

A call to
**NdisCmDispatchIncomingDropParty** causes NDIS to call the client's
[ProtocolClIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_drop_party) function.

If the
*NdisPartyHandle* identifies the last remaining party on the given VC, the CM calls
[NdisCmDispatchIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingclosecall), rather than
**NdisCmDispatchIncomingDropParty**.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmDispatchIncomingDropParty**. Connection-oriented miniport drivers that provide integrated
call-management support call
**NdisMCmDispatchIncomingDropParty** instead.

## See also

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisCmDispatchIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingclosecall)

[NdisMCmDispatchIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingdropparty)

[ProtocolClIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_drop_party)

[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists)