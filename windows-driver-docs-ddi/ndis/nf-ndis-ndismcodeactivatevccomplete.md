# NdisMCoDeactivateVcComplete function

## Description

**NdisMCoDeactivateVcComplete** notifies NDIS and the call manager that the miniport driver has finished
processing a CM-initiated deactivate-VC request, for which the miniport driver previously returned
NDIS_STATUS_PENDING.

## Parameters

### `Status` [in]

Specifies the final status of the deactivate-VC operation, which can be NDIS_STATUS_SUCCESS or any
NDIS_STATUS_
*XXX except* NDIS_STATUS_PENDING.

### `NdisVcHandle` [in]

Specifies the handle identifying the VC. The caller obtained this handle from its per-VC state,
designated by the
*MiniportVcContext* passed as an input parameter to its
[MiniportCoDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_deactivate_vc) function.

## Remarks

A connection-oriented miniport driver must call
**NdisMCoDeactivateVcComplete** if its
*MiniportCoDeactivateVc* function previously returned NDIS_STATUS_PENDING in response to a request to
deactivate the VC identified by the given
*NdisVcHandle* . The call manager, which initiated the VC deactivation with a call to
[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc), cannot notify NDIS
or its client whether transfers have been disabled on the VC until the miniport driver calls
**NdisMCoDeactivateVcComplete**.

Before it deactivates a VC, the miniport driver must complete any pending transfers on the VC. That
is, the miniport driver must indicate all outstanding receives and transmit all outstanding sends before
calling
**NdisMCoDeactivateVcComplete**.

A call to
**NdisMCoDeactivateVcComplete** causes NDIS to call the
[ProtocolCmDeactivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deactivate_vc_complete) function of the call manager that originally requested the VC
deactivation. Following its call to
**NdisMCoDeactivateVcComplete**, the miniport driver can neither indicate receives nor transmit sends
on the VC.

## See also

[MiniportCoDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_deactivate_vc)

[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc)

[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc)

[ProtocolCmDeactivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deactivate_vc_complete)