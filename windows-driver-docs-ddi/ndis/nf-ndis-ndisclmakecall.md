# NdisClMakeCall function

## Description

**NdisClMakeCall** sets up an outgoing call on a client-created VC.

## Parameters

### `NdisVcHandle` [in]

Specifies the handle returned by a preceding call to
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc).

### `CallParameters` [in, out]

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) in which the caller has
specified the attributes for this connection, such as the address of the target for the call, latency,
bandwidth, and quality of service if the network medium and address family supported by the call manager
permits QoS specifications.

### `ProtocolPartyContext` [in, optional]

Optionally specifies a caller-supplied handle to a resident context area in which the client will
maintain per-party state for the initial party on its multipoint VC. This parameter is **NULL** if the given
VC does not represent a multipoint connection. For a multipoint VC, NDIS passes this handle back to the
client's ProtocolCl*Xxx* functions in all subsequent calls that affect this particular party.

### `NdisPartyHandle` [out, optional]

Pointer to a caller-supplied variable, usually in the caller-allocated party context area, in
which NDIS returns a handle representing the initial party to the multipoint connection if the request
to set up an outgoing call is successful. If
*ProtocolPartyContext* is **NULL**, this variable, usually in the client's VC context area, also is set
to **NULL** on completion of outgoing-call setup.

## Return value

When
**NdisClMakeCall** returns anything other than NDIS_STATUS_PENDING, the client should make an internal
call to its
[ProtocolClMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_make_call_complete) function. Otherwise, NDIS calls the client's
*ProtocolClMakeCallComplete* function when this operation is completed.

## Remarks

**NdisClMakeCall** sets up the attributes of a client-created VC for a client-initiated outgoing call.
The client must set up the VC with
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) before it attempts to make
an outgoing call.

A call to
**NdisClMakeCall** causes NDIS to forward this request to the
[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call) function of the
call manager with which the client shares the given
[NdisVcHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_make_call_complete). The CM is
responsible for validating the given data at
*CallParameters* . It can modify this client-supplied data while negotiating with relevant network
components and can return different traffic parameters than the client originally gave to
**NdisClMakeCall**. The client's
*ProtocolClMakeCallComplete* function is responsible for accepting the modified call parameters if
this occurs or for tearing down the call if the CM's proposed call parameters are unacceptable.

Consequently, the data at
*CallParameters* must remain available to the call manager at least for the duration of call setup.
The client cannot free this buffer when
**NdisClMakeCall** returns NDIS_STATUS_PENDING. It must defer releasing this client-allocated resource
until its
*ProtocolClMakeCallComplete* function is called.

If
**NdisClMakeCall** sets up a multipoint connection, the client is establishing the traffic parameters
globally for the given VC, unless the underlying network medium supports per-party traffic
parameters.

The client's
*ProtocolClMakeCallComplete* function should check the input
*Status* for NDIS_STATUS_SUCCESS before it uses any returned handle at
*NdisPartyHandle* . If the call manager fails the request to set up a call on a multipoint
connection, the value of this client-supplied variable is invalid.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClAddParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscladdparty)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos)

[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc)

[NdisCmMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmmakecallcomplete)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[ProtocolClMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_make_call_complete)

[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call)