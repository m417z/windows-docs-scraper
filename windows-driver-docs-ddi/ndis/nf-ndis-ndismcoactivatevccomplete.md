# NdisMCoActivateVcComplete function

## Description

**NdisMCoActivateVcComplete** notifies NDIS and the call manager that the miniport driver has finished
processing a CM-initiated activate-VC request, for which the miniport driver previously returned
NDIS_STATUS_PENDING.

## Parameters

### `Status` [in]

Specifies the final status of the activate-VC operation, which can be NDIS_STATUS_SUCCESS or any
NDIS_STATUS_
*XXX except* NDIS_STATUS_PENDING.

### `NdisVcHandle` [in]

Specifies the handle identifying the VC. The caller obtained this handle from its per-VC state,
designated by the
*MiniportVcContext* passed as an input parameter to its
[MiniportCoActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_activate_vc) function.

### `CallParameters` [in]

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)), supplied by the call
manager, specifying the call and media parameters for the VC activation.

## Remarks

A connection-oriented miniport driver must call
**NdisMCoActivateVcComplete** if its
*MiniportCoActivateVc* function previously returned NDIS_STATUS_PENDING in response to a request to
activate or reactivate the VC identified by the given
*NdisVcHandle* . The call manager, which initiated the VC activation with a call to
[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc), cannot notify NDIS or
its client whether transfers on the VC can be made using the supplied call parameters until the miniport
driver calls
**NdisMCoActivateVcComplete**.

If the miniport driver finds the CM-supplied call parameters unacceptable, it fails the VC activation
when it calls
**NdisMCoActivateVcComplete**. Failing the initial activation of a VC can cause the protocol that
created the VC to tear it down. If the miniport driver fails a request to reactivate an established VC
with new call parameters, it must restore the original call parameters established for that VC. Depending
on the nature of the network medium, a miniport driver can modify the media parameters if the round-up
and/or round-down flag(s) are set before it calls
**NdisMCoActivateVcComplete**.

A call to
**NdisMCoActivateVcComplete** causes NDIS to call the
[ProtocolCmActivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_activate_vc_complete) function of the call manager that originally requested the VC
activation.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[MiniportCoActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_activate_vc)

[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc)

[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc)

[ProtocolCmActivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_activate_vc_complete)