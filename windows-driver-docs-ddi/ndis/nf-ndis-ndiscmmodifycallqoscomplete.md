# NdisCmModifyCallQoSComplete function

## Description

**NdisCmModifyCallQoSComplete** indicates the completion of the client's request, for which the call
manager previously returned NDIS_STATUS_PENDING, to modify the quality of service on a VC.

## Parameters

### `Status` [in]

Specifies the final status of the client's request to modify the QoS on this VC, either
NDIS_STATUS_SUCCESS or any CM-determined NDIS_STATUS_
*XXX* except NDIS_STATUS_PENDING.

### `NdisVcHandle` [in]

Specifies the handle to the VC, obtained from the
*CallMgrVcContext* passed in to the CM's
[ProtocolCmModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_modify_qos_call) function for this request.

### `CallParameters` [in]

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) specifying a QoS
acceptable to the call manager and underlying miniport driver if
*Status* is set to NDIS_STATUS_SUCCESS.

## Remarks

A call to
**NdisCmModifyCallQoSComplete** causes NDIS to call the client's
[ProtocolClModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_modify_call_qos_complete) function.

Because the CM can modify the client-supplied call parameters that were input to its
[ProtocolCmModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_modify_qos_call) function before it calls
**NdisCmModifyCallQoSComplete**, the client's
*ProtocolClModifyCallQoSComplete* function examines the QoS to determine whether it is acceptable to
the client.
*ProtocolClModifyCallQoSComplete* simply returns control if the client accepts the given call
parameters. Otherwise, the client tears down the call.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmModifyCallQoSComplete**. Connection-oriented miniport drivers that provide integrated
call-management support call
**NdisMCmModifyCallQoSComplete** instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos)

[NdisMCmModifyCallQosComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmmodifycallqoscomplete)

[ProtocolClModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_modify_call_qos_complete)

[ProtocolCmModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_modify_qos_call)