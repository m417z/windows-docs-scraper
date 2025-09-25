# NdisMCmCloseCallComplete macro

## Description

**NdisMCmCloseCallComplete** returns the final status of a client's request, for which the MCM driver
previously returned NDIS_STATUS_PENDING, to tear down a call.

## Parameters

### `_S_`

Specifies the final status of the client's request that the MCM driver close the connection,
either NDIS_STATUS_SUCCESS or any caller-determined NDIS_STATUS_*XXX* except NDIS_STATUS_PENDING.

### `_VH_`

Specifies the handle to the VC for the call. This handle was supplied by NDIS when the VC was
originally created, whether by the MCM driver with
[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc) or as an input parameter
to its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `_PH_`

Specifies either **NULL** if the
*NdisVcHandle* represents a point-to-point VC or the handle to the last remaining party on a
multipoint connection, which the MCM driver obtained from its per-party state designated by the
*CallMgrPartyContext* passed as an input parameter to its
[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call) function.

## Remarks

If an MCM driver's
*ProtocolCmCloseCall* function returns NDIS_STATUS_PENDING, it must call
**NdisMCmCloseCallComplete** subsequently to notify the client and NDIS that its attempt to break the
connection has completed, whether successfully or with an error. A call to
**NdisMCmCloseCallComplete** causes NDIS to call the client's
*ProtocolClCloseCallComplete* function.

If it passes NDIS_STATUS_SUCCESS as the
*Status*, the MCM driver should consider the
*NdisVcHandle* (and
*NdisPartyHandle*, if any) unusable for transfers over the network as soon as it calls
**NdisMCmCloseCallComplete**. If the MCM driver originally created the VC, it should call
[NdisMCmDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeletevc) with the same
*NdisVcHandle* that it just passed to
**NdisMCmCloseCallComplete**. If the client created this VC, the MCM driver can expect a call to its
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function with the
*ProtocolVcContext*, designating its per-VC state in which it has stored the same
*NdisVcHandle*, as an input parameter.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmCloseCallComplete**. Stand-alone call managers, which register themselves with NDIS as
protocol drivers, call
**NdisCmCloseCallComplete** instead.

## See also

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisCmCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmclosecallcomplete)

[NdisMCmCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcreatevc)

[NdisMCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeactivatevc)

[NdisMCmDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdeletevc)

[ProtocolClCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_call_complete)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)