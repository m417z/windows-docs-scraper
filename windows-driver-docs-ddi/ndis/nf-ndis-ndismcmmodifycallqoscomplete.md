# NdisMCmModifyCallQoSComplete macro

## Description

**NdisMCmModifyCallQoSComplete** indicates the completion of the client's request, for which the MCM
driver previously returned NDIS_STATUS_PENDING, to modify the quality of service on a VC.

## Parameters

### `_S_`

Specifies the final status of the client's request to modify the QoS on this VC, either
NDIS_STATUS_SUCCESS or any caller-determined NDIS_STATUS_*XXX*except NDIS_STATUS_PENDING.

### `_H_`

Specifies the handle to the VC, obtained from the per-VC state designated by the
*CallMgrVcContext* passed in to the MCM driver's
[ProtocolCmModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_modify_qos_call) function for this request.

### `_P_`

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) specifying a QoS
acceptable to the MCM driver if
*Status* is set to NDIS_STATUS_SUCCESS.

## Remarks

A call to
**NdisMCmModifyCallQoSComplete** causes NDIS to call the client's
[ProtocolClModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_modify_call_qos_complete) function.

The MCM driver should call
**NdisMCmActivateVc** whenever it makes changes in the call parameters on an active VC.

Because the MCM driver can modify the client-supplied call parameters that were input to its
*ProtocolCmModifyCallQoS* function before it calls
**NdisMCmModifyCallQoSComplete**, the client's
*ProtocolClModifyCallQoSComplete* function examines the QoS to determine whether it is acceptable to
the client.
*ProtocolClModifyCallQoSComplete* simply returns control if the client accepts the given call
parameters. Otherwise, the client tears down the call.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmModifyCallQoSComplete**. Stand-alone call managers, which register themselves with NDIS as
protocol drivers, call
**NdisCmModifyCallQoSComplete** instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos)

[NdisCmModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmmodifycallqoscomplete)

[NdisMCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmactivatevc)

[ProtocolClModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_modify_call_qos_complete)

[ProtocolCmModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_modify_qos_call)