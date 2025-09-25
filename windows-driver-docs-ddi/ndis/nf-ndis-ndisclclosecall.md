# NdisClCloseCall function

## Description

**NdisClCloseCall** requests that a call on the specified VC be torn down.

## Parameters

### `NdisVcHandle` [in]

Handle to the VC of the call being closed or disconnected. This handle was supplied by NDIS when
the VC was originally created with
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc), whether by the client in
preparation for making an outgoing call or by the call manager in preparation for dispatching an
incoming call to the client.

### `NdisPartyHandle` [in, optional]

Handle to the last party to be dropped on a multipoint VC or **NULL**. If this is a multipoint VC, the
client obtained this handle either from a preceding call to
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall) or
[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty).

### `Buffer` [in, optional]

Pointer to a caller-allocated buffer containing any data to be transmitted to the party on the
remote node when the connection is closed. Depending on the underlying medium, this pointer can be
**NULL**.

### `Size` [in]

Specifies the size, in bytes, at
*Buffer*, zero if
*Buffer* is **NULL**.

## Return value

When
**NdisClCloseCall** returns anything other than NDIS_STATUS_PENDING, the client should make an
internal call to its
[ProtocolClCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_call_complete) function. Otherwise, NDIS calls the client's
*ProtocolClCloseCallComplete* function when this operation is completed.

## Remarks

Clients usually call
**NdisClCloseCall** in any one of the following circumstances:

* To close an established call, whether the call was initiated by the client with
  [NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall) or was offered by a remote
  peer and accepted by the client's
  [ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call) function.
* From the
  [ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call) function to tear down an established call.

  This occurs when the remote party closes an incoming call that the remote party originally initiated
  and that the client accepted. For client-initiated outgoing calls, this occurs either when the remote
  party closes the point-to-point connection on the remote node or when the last remaining party on a
  multipoint VC closes the call on the remote node.
* From the
  [ProtocolClMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_make_call_complete) function to tear down a client-initiated attempt to make an outgoing
  call.

  This occurs if the call manager has modified the client-specified call parameters passed to
  [NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall) and the client finds these
  modifications unacceptable.
* From the
  *ProtocolClIncomingQoSChange* function to tear down an established call.

  This occurs if a QoS change proposed by the other party on the VC is unacceptable to the client.
* From the
  [ProtocolClModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_modify_call_qos_complete) function to tear down an established call.

  This occurs if a client-proposed QoS change on the VC is not accepted and the CM-modified QoS
  returned to
  *ProtocolClModifyCallQoSComplete* is unacceptable to the client.

Before calling
**NdisClCloseCall**, a protocol must ensure that all its outstanding send packets have been returned
to its
[ProtocolCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_send_net_buffer_lists_complete) function. (Packets sent via
[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists) are
always returned asynchronously to
*ProtocolCoSendNetBufferListsComplete*.) After calling
**NdisClCloseCall**, a protocol must not call
**NdisCoSendNetBufferLists** to send
packets on the VC referenced by
**NdisClCloseCall**.

A client's call to
**NdisClCloseCall** causes NDIS to mark the
*NdisVcHandle* as closing and to call the CM's
[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call) function.

To tear down an established call on a client-created multipoint VC, the client must call
[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty) one or more times to
release all but the last party on the VC
before it calls
**NdisClCloseCall**. The call manager will fail any client's request to close a multipoint call if the
given VC still has more than one party connected. The
*NdisPartyHandle* passed to
**NdisClCloseCall** can be any valid handle that the client obtained from its preceding calls to
[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty) or
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall) with the given
*NdisVcHandle* .

As remote parties to a client-initiated multipoint call request that their connections be closed, NDIS
calls that client's
*ProtocolClDropParty* function as long as more than one outstanding party exists on the
client-created multipoint VC. When the last remaining remote party closes its connection, NDIS calls the
client's
[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call) function instead. Consequently, the
*ProtocolClIncomingCloseCall* function of any client that sets up multipoint connections must
identify the last remaining party on its multipoint VCs and pass the appropriate
*NdisPartyHandle* to
**NdisClCloseCall**.

After the client releases an
*NdisPartyHandle* with
**NdisClCloseCall**, it can release (or reinitialize for reuse) the resources for the per-party state
it was maintaining. However, the client cannot release or reuse its per-VC resources in a similar manner
on completion of the operation it initiated with
**NdisClCloseCall** because the
*NdisVcHandle*, which cannot be reused to make another call because it is marked as closing, is
still valid until the VC is destroyed. Either the client must call
[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc) if it created the VC for an
outgoing call before it releases or reinitializes its per-VC resources, or the client must defer the
release or reinitialization of these resources until its
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function is
called.

## See also

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists)

[ProtocolClCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_call_complete)

[ProtocolClIncomingCallQoSChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call_qos_change)

[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call)

[ProtocolClIncomingDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_drop_party)

[ProtocolClMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_make_call_complete)

[ProtocolClModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_modify_call_qos_complete)

[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call)

[ProtocolCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_send_net_buffer_lists_complete)