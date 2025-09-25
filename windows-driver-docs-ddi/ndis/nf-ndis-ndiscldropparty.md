# NdisClDropParty function

## Description

**NdisClDropParty** drops a party from the client's multipoint VC.

## Parameters

### `NdisPartyHandle` [in]

Specifies the handle identifying the party to be dropped on the multipoint connection. The client
obtained this handle from a preceding call to
[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty) or
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall).

### `Buffer` [in, optional]

Pointer to a caller-allocated buffer containing any data to be transmitted to close the multipoint
connection of the party on the remote node. Depending on the underlying medium, this pointer can be
**NULL**.

### `Size` [in, optional]

Specifies the size in bytes at
*Buffer*, zero if
*Buffer* is **NULL**.

## Return value

When
**NdisClDropParty** returns anything other than NDIS_STATUS_PENDING, the client should make an
internal call to its
[ProtocolClDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_drop_party_complete) function. Otherwise, NDIS calls the client's
*ProtocolClDropPartyComplete* function when this operation is completed.

## Remarks

Clients usually call
**NdisClDropParty** in either of the following circumstances:

* From the
  [ProtocolClIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_drop_party) function to remove the given party from a multipoint connection.

  This occurs when a party on a remote node closes its connection with
  [NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall). When NDIS calls the
  local client's
  *ProtocolClDropPartyComplete* function, it can release or reuse the context area at
  *ProtocolPartyContext* in which the client was maintaining state about this party.
* Before the client calls
  **NdisClCloseCall** with the last party on a multipoint connection that the client originally set up
  with
  [NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall).

  For such a client-initiated close of its own multipoint call, the client must call
  **NdisClDropParty** one or more times to drop every other remaining party on the multipoint VC.

A client's call to
**NdisClDropParty** causes NDIS to call the
[ProtocolCmDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_drop_party) function of the
call manager that shares the same
*NdisVcHandle* to the multipoint VC. The call manager is responsible for notifying its remote-node
peer that the party connection has been or should be closed, depending on which client initiated the
drop-party operation.

As a general guideline, a client must call
**NdisClDropParty** as many times as it called
[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty) with a particular
*NdisVcHandle* obtained from
**NdisClMakeCall**
before it closes its multipoint connection with
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall). Since remote parties can
initiate closes of their connections, thereby causing calls to the local client's
[ProtocolClIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_drop_party) function, the local client must keep track of the number of active
parties on its multipoint VCs in order to know how many calls it must make to
**NdisClDropParty** before it can call
**NdisClCloseCall**.

However, the client is not required to pass
**NdisClCloseCall** the same
*NdisPartyHandle* returned by
**NdisClMakeCall** when the client originally set up its multipoint connection. The client can release
parties on its multipoint VC in any order, as long as it releases every
*NdisPartyHandle* returned by
**NdisClAddParty** or
**NdisClMakeCall** in its calls to
**NdisClDropParty**, followed by a final call with the last party handle to
**NdisClCloseCall** for the same multipoint VC. After the client has closed its multipoint call, it can
release the VC that it originally created with
[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc).

The caller of
**NdisClDropParty** should consider the input
*NdisPartyHandle* invalid as soon as it makes this call. If it stored this handle in the party
context area it allocated, the client's
[ProtocolClDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_drop_party_complete) function should reset the handle variable to **NULL** if it reinitializes
its per-party context area for reuse when the party has been dropped.

## See also

[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[ProtocolClDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_drop_party_complete)

[ProtocolClIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_drop_party)

[ProtocolCmDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_drop_party)