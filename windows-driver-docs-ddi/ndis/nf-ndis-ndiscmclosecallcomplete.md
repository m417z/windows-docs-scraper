# NdisCmCloseCallComplete function

## Description

**NdisCmCloseCallComplete** returns the final status of a client's request, for which the call manager
previously returned NDIS_STATUS_PENDING, to tear down a call.

## Parameters

### `Status` [in]

Specifies the final status of the client's request that the CM close the connection, either
NDIS_STATUS_SUCCESS or any CM-determined NDIS_STATUS_*XXX* except NDIS_STATUS_PENDING.

### `NdisVcHandle` [in]

Specifies the handle to the VC for the call. This handle was supplied by NDIS when the VC was
originally created, whether by the call manager or client, with
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc). More recently, the call
manager obtained this handle from its per-VC state designated by the
*CallMgrVcContext* passed as an input parameter to its
[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call) function.

### `NdisPartyHandle` [in, optional]

Specifies either **NULL** if the
*NdisVcHandle* represents a point-to-point VC or the handle to the last remaining party on a
multipoint connection, which the CM obtained from its per-party state designated by the
*CallMgrPartyContext* passed as an input parameter to its
*ProtocolCmCloseCall* function.

## Remarks

If a stand-alone call manager's
*ProtocolCmCloseCall* function returns NDIS_STATUS_PENDING, the CM must call
**NdisCmCloseCallComplete** subsequently to notify the client and NDIS that its attempt to break the
connection has completed, whether successfully or with an error. A call to
**NdisCmCloseCallComplete** causes NDIS to call the client's
[ProtocolClCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_call_complete) function.

If it passes NDIS_STATUS_SUCCESS as the
*Status*, the call manager should consider the
*NdisVcHandle* (and
*NdisPartyHandle*, if any) unusable for transfers over the network as soon as it calls
**NdisCmCloseCallComplete**. If the call manager originally created the VC, it should call
[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc) with the same
*NdisVcHandle* that it just passed to
**NdisCmCloseCallComplete**. If the client created this VC, the call manager can expect a call to its
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function with the
*ProtocolVcContext*, where it has the same
*NdisVcHandle*, as an input parameter.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmCloseCallComplete**. Connection-oriented miniport drivers that provide integrated
call-management support call
**NdisMCmCloseCallComplete** instead.

## See also

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[NdisMCmCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmclosecallcomplete)

[ProtocolClCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_call_complete)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)