# NdisClModifyCallQoS function

## Description

**NdisClModifyCallQoS** requests a change in the quality of service on a connection.

## Parameters

### `NdisVcHandle` [in]

Specifies the handle to the VC for which the client wants to modify the QoS. The client originally
obtained this handle by calling
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc), and, more recently,
retrieved this handle from its per-VC state area.

### `CallParameters` [in]

Pointer to a structure of type CO_CALL_PARAMETERS that specifies the new QoS requested by the
caller.

## Return value

When
**NdisClModifyCallQoS** returns anything other than NDIS_STATUS_PENDING, the client should make an
internal call to its
[ProtocolClModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_modify_call_qos_complete) function. Otherwise, NDIS calls the client's
*ProtocolClModifyCallQoSComplete* function when this operation is completed.

## Remarks

A call to
**NdisClModifyCallQoS** causes NDIS to call the CM's
[ProtocolCmModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_modify_qos_call) function, which, in turn, calls
[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc) to notify the underlying
miniport driver to change the call parameters if the requested QoS change can be made.

If the call manager does not accept the client's proposed QoS change, the client either can continue
using the unchanged QoS for the call or can tear down the call. If the client and call manager cannot
agree on the QoS for a particular call, the creator of the VC is responsible for initiating the teardown
of the VC.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[MiniportCoActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_activate_vc)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisCmModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmmodifycallqoscomplete)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[ProtocolClModifyCallQoSComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_modify_call_qos_complete)

[ProtocolCmModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_modify_qos_call)