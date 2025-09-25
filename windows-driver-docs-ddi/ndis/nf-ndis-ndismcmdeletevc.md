# NdisMCmDeleteVc function

## Description

**NdisMCmDeleteVc** destroys a caller-created VC.

## Parameters

### `NdisVcHandle` [in]

Specifies the handle identifying the VC to be deleted. The caller originally obtained this handle
from
[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc).

## Return value

**NdisMCmDeleteVc** can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS deleted the VC. |
| **NDIS_STATUS_NOT_ACCEPTED** | The VC is still active, so it could not be deleted. |

## Remarks

When an MCM driver calls
**NdisMCmDeleteVc**, there must be no outstanding calls on the given VC and that VC must have been
deactivated. To meet these requirements implies that the MCM driver has already called
[NdisMCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeactivatevc) with the given
*NdisVcHandle* successfully.

Only the driver that created a particular VC can delete that VC. A call to
**NdisMCmDeleteVc** causes NDIS to call the
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function of the
client with which the caller shares the
*NdisVcHandle* .

When
**NdisMCmDeleteVc** returns control, the
*NdisVcHandle* is no longer valid. The MCM driver can release the resources it allocated to maintain
state about the deleted VC or prepare them for reuse in a subsequent incoming-call notification after it
calls
[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc).

The driver writer determines whether an MCM driver has an (internal)
[MiniportCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_delete_vc) function that the
driver calls in the context of tearing down connections for outgoing and incoming calls.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmDeleteVc**. Stand-alone call managers and clients, which register themselves with NDIS as
protocol drivers, call
**NdisCoDeleteVc** instead.

## See also

[MiniportCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_delete_vc)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc)

[NdisMCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeactivatevc)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)