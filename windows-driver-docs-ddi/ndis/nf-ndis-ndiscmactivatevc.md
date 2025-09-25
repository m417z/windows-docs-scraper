# NdisCmActivateVc function

## Description

**NdisCmActivateVc** passes CM-supplied call parameters, including media parameters, for a particular VC
down to the underlying miniport driver.

## Parameters

### `NdisVcHandle` [in]

Specifies the handle identifying the VC on which to set call parameters. The call manager either
obtained this handle from
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) for an incoming call or as
an input parameter to its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function for a
client-initiated outgoing call.

### `CallParameters` [in, out]

Pointer to a CM-allocated resident buffer, formatted as a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)), containing all the
media-specific parameters that the underlying miniport driver uses for VC activation.

## Return value

When
**NdisCmActivateVc** returns anything other than NDIS_STATUS_PENDING, the call manager should make an
internal call to its
[ProtocolCmActivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_activate_vc_complete) function. Otherwise, NDIS calls the CM's
*ProtocolCmActivateVcComplete* function when this operation is completed.

## Remarks

**NdisCmActivateVc** notifies the underlying miniport driver to set up call and media parameters on a
newly created VC or to change those of an established VC. NDIS forwards the given call parameters and VC
handle to the underlying miniport driver's
[MiniportCoActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_activate_vc) function, which
sets up all necessary resources to track the state of the VC and makes itself and a NIC ready for data
transfers on the VC.

A stand-alone CM always calls
**NdisCmActivateVc** after establishing a connection on a VC but before any data is sent or received on
that VC. For the duration of the connection, a CM can call
**NdisCmActivateVc** many times with the same
*NdisVcHandle* as conditions on the network change and/or whenever the client calls
[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos). At each such
call to
**NdisCmActivateVc**, the underlying miniport driver's
*MiniportCoActivateVc* function must do either of the following:

* Update the state that the miniport driver maintains about call parameters to the new values supplied
  by the call manager if the miniport driver can continue to make transfers on the VC according to the
  newly modified call parameters.
* Fail the call if the miniport driver cannot continue to make transfers under the constraints of the
  given call parameters.

When the underlying miniport driver fails a request to set or reset call parameters, the call manager
might modify its original specification at
*CallParameters* and call
**NdisCmActivateVc** again. The limit on the number of times any call manager makes repeated attempts
to activate a VC is implementation-dependent.

For a client-initiated outgoing call, a stand-alone CM usually calls
**NdisCmActivateVc** immediately following the packet exchange confirming a negotiated agreement with
the remote target of the call or successful call-setup at the switch, before it notifies NDIS (and the
client) of outgoing call completion with
[NdisCmMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmmakecallcomplete). For an
incoming call, a call manager usually calls
**NdisCmActivateVc** after it has called
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) successfully and before it
calls
[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall).

In the process of setting up an outgoing call and while any VC remains activated, the client can
request changes to the call parameters for that VC, for example, by calling
[NdisClModifyCallQos](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos). After verifying
the validity of the given call parameters for any such a request, the stand-alone call manager must call
**NdisCmActivateVc** to pass the modified call parameters down to the underlying miniport driver.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmActivateVc**. Connection-oriented miniport drivers that provide integrated call-management
support call
**NdisMCmActivateVc** instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[MiniportCoActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_activate_vc)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisClModifyCallQos](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos)

[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc)

[NdisCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingcall)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisMCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmactivatevc)

[ProtocolCmActivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_activate_vc_complete)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)