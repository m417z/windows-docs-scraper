# NdisMCmDeregisterSapComplete macro

## Description

**NdisMCmDeregisterSapComplete** returns the final status of a client's request, for which the MCM driver
previously returned NDIS_STATUS_PENDING, to deregister a SAP.

## Parameters

### `_S_`

Specifies NDIS_STATUS_SUCCESS.

### `_H_`

Specifies the handle identifying the SAP.

## Remarks

**NdisMCmDeregisterSapComplete** notifies both NDIS and the client that the MCM driver has completed
the SAP-deregistration request for which its
[ProtocolCmDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deregister_sap) function previously returned NDIS_STATUS_PENDING.

A call to
**NdisMCmDeregisterSapComplete** causes NDIS to call the client's
[ProtocolClDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_deregister_sap_complete) function.

The MCM driver should consider the
*NdisSapHandle* invalid when
**NdisMCmDeregisterSapComplete** returns control.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmDeregisterSapComplete**. Stand-alone call managers, which register themselves with NDIS as
protocol drivers, call
**NdisCmDeregisterSapComplete** instead.

## See also

[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap)

[NdisCmDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmderegistersapcomplete)

[ProtocolClDeregisterSapComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_deregister_sap_complete)

[ProtocolCmDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_deregister_sap)