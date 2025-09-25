# NdisMCmActivateVc function

## Description

**NdisMCmActivateVc** notifies NDIS that an MCM driver is ready to make transfers on a particular
VC.

## Parameters

### `NdisVcHandle` [in]

Specifies the handle identifying the VC.

### `CallParameters` [in]

Pointer to a caller-allocated buffer, formatted as a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)), containing all the
media-specific parameters that the miniport driver uses for the activated VC.

## Return value

When
**NdisMCmActivateVc** returns anything other than NDIS_STATUS_PENDING, the MCM driver should make an
internal call to its
[ProtocolCmActivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_activate_vc_complete) function. Otherwise, NDIS calls the MCM driver's
*ProtocolCmActivateVcComplete* function when this operation is completed.

## Remarks

**NdisMCmActivateVc** informs NDIS that an MCM driver has set up call and media parameters on a newly
created VC or changed the call parameters on an established VC.

An MCM driver must call
**NdisMCmActivateVc** after establishing a connection on a VC but before any data is sent or received
on that VC. This call notifies NDIS that the miniport driver has made a NIC ready for transfers on the
VC.

For a client-initiated outgoing call, an MCM driver usually calls
**NdisMCmActivateVc** following the handshake denoting a negotiated agreement with the remote node or
successful call-setup at the switch, before it notifies NDIS (and the client) of outgoing call completion
with
[NdisMCmMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmmakecallcomplete). For an
incoming call, an MCM driver usually calls
**NdisMCmActivateVc** after it has called
[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc) successfully and before it
calls
[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall).

The driver writer determines whether an MCM driver has an (internal)
*MiniportCoActivateVc* function that the driver calls in the context of setting up connections for
outgoing and incoming calls.

For the duration of the connection, an MCM driver can modify the call parameters as conditions on the
network change and/or whenever the client calls
[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos). The MCM driver
must update the state that it maintains about call parameters to the new values if it can continue to
make transfers on the VC according to the newly modified call parameters. It must call
**NdisMCmActivateVc** to notify NDIS of any changes in the call parameters for the active VC.
Otherwise, the MCM driver can do either of the following:

* Call
  **NdisMCmDeactivateVc** after failing the client's request to modify QoS or other call parameters for
  the VC to such a state that the miniport driver cannot continue to make transfers on the VC.
* Restore the call parameters to a previously accepted state, notify the client that requested the
  change, and remain ready to continue transferring data on the VC. In this case, the client has the
  option of accepting the restored call parameters or rejecting them and initiating a close of the
  VC.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmActivateVc**. Stand-alone call managers, which register themselves with NDIS as protocol
drivers, call
**NdisCmActivateVc** instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[MiniportCoActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_activate_vc)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos)

[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc)

[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc)

[NdisMCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeactivatevc)

[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)