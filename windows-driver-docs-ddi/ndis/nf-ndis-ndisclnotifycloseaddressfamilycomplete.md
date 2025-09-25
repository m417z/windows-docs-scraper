# NdisClNotifyCloseAddressFamilyComplete function

## Description

The
**NdisClNotifyCloseAddressFamilyComplete** function returns the final status of an address family (AF)
close operation for which the caller's
[ProtocolClNotifyCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_notify_close_af) function
returned NDIS_STATUS_PENDING.

## Parameters

### `NdisAfHandle` [in]

An AF handle that NDIS supplied to the caller's
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) function.

### `Status` [in]

The completion status for close AF notification.

*Status* can be one of the following:

#### NDIS_STATUS_SUCCESS

The client successfully closed its address family.

#### NDIS_STATUS_XXX

The client failed the request for some driver-determined reason.

## Remarks

CoNDIS clients call the
**NdisClNotifyCloseAddressFamilyComplete** function to complete a close AF notification. A client must
call
**NdisClNotifyCloseAddressFamilyComplete** after its
[ProtocolClNotifyCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_notify_close_af) function returns NDIS_STATUS_PENDING.

After the client calls
**NdisClNotifyCloseAddressFamilyComplete**, NDIS calls the call manager's
[ProtocolCmNotifyCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_notify_close_af_complete) function to complete operation for the call manager.

## See also

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[ProtocolClNotifyCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_notify_close_af)

[ProtocolCmNotifyCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_notify_close_af_complete)