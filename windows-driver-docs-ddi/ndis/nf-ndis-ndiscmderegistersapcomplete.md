# NdisCmDeregisterSapComplete function

## Description

**NdisCmDeregisterSapComplete** returns the final status of a client's request, for which the call
manager previously returned NDIS_STATUS_PENDING, to deregister a SAP.

## Parameters

### `Status` [in]

Specifies NDIS_STATUS_SUCCESS.

### `NdisSapHandle` [in]

Specifies the handle identifying the SAP.

## Remarks

**NdisCmDeregisterSapComplete** notifies both NDIS and the client that the call manager has completed
the SAP-deregistration request for which its
[ProtocolCmDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deregister_sap) function previously returned NDIS_STATUS_PENDING.

A call to
**NdisCmDeregisterSapComplete** causes NDIS to call the client's
[ProtocolClDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_deregister_sap_complete) function.

The call manager should consider the
*NdisSapHandle* invalid when
**NdisCmDeregisterSapComplete** returns control.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmDeregisterSapComplete**. Connection-oriented miniport drivers that provide integrated
call-management support call
**NdisMCmDeregisterSapComplete** instead.

## See also

[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap)

[NdisMCmDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmderegistersapcomplete)

[ProtocolClDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_deregister_sap_complete)

[ProtocolCmDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deregister_sap)