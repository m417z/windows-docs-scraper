# NdisCoDeleteVc function

## Description

**NdisCoDeleteVc** destroys a caller-created VC.

## Parameters

### `NdisVcHandle` [in]

Specifies the handle identifying the VC to be deleted. The caller originally obtained this handle
from
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc).

## Return value

**NdisCoDeleteVc** can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS deleted the VC. |
| **NDIS_STATUS_NOT_ACCEPTED** | The VC is still active, so it could not be deleted. |
| **NDIS_STATUS_CLOSING** | This call is redundant, but deactivation on the given VC is still pending. |

## Remarks

When a protocol calls
**NdisCoDeleteVc**, there must be no outstanding calls on the given VC and that VC already has been
deactivated. To meet these requirements implies that the following conditions hold:

* If the call tear-down was initiated by a local client, that client has already called
  [NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall) with the given
  *NdisVcHandle* and its close-call request has completed successfully.
* If the call tear-down was initiated by a remote client, the stand-alone call manager has already
  called
  [NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc) with the given
  *NdisVcHandle* and its deactivation request has completed successfully.

Only the protocol that created a particular VC can delete that VC. A call to
**NdisCoDeleteVc** causes NDIS to call both the underlying miniport driver's
[MiniportCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_delete_vc) function and the
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function of the
client or call manager with which the caller shares the
*NdisVcHandle* .

When
**NdisCoDeleteVc** returns control, the
*NdisVcHandle* is no longer valid.

Stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCoDeleteVc**. Connection-oriented miniport drivers that provide integrated call-management
support call
[NdisMCmDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeletevc) instead.

## See also

[MiniportCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_delete_vc)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisMCmDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeletevc)

[ProtocolClCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_call_complete)

[ProtocolClIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_close_call)

[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)