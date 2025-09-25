# NdisCmNotifyCloseAddressFamily function

## Description

The
**NdisCmNotifyCloseAddressFamily** function notifies NDIS that a call manager is unbinding from an
underlying miniport adapter and that any associated CoNDIS clients should close the specified address
family (AF).

## Parameters

### `NdisAfHandle` [in]

An NDIS handle that identifies the AF that NDIS should close. NDIS supplied this handle to the
call manager's
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function.

## Return value

**NdisCmNotifyCloseAddressFamily** can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS successfully closed the address family. |
| **NDIS_STATUS_PENDING** | NDIS is handling this request asynchronously, and it will call the call manager's [ProtocolCmNotifyCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_notify_close_af_complete) function when the close operation is complete. |
| **NDIS_STATUS_*XXX*** | NDIS failed the request for some NDIS or client driver-determined reason. |

## Remarks

Stand-alone CoNDIS call managers, which register as NDIS protocol drivers by calling the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function, can call the
**NdisCmNotifyCloseAddressFamily** function. Miniport call managers (MCMs) instead call the
[NdisMCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmnotifycloseaddressfamily) function.

To close an AF for a binding, the stand-alone call manager should call
**NdisCmNotifyCloseAddressFamily** from the
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function. NDIS then calls the
[ProtocolClNotifyCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_notify_close_af) function of the client that has the specified AF open.

If
**NdisCmNotifyCloseAddressFamily** returns NDIS_STATUS_PENDING, NDIS calls the call manager's
[ProtocolCmNotifyCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_notify_close_af_complete) function after the client completes the AF close operation.

## See also

[NdisMCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmnotifycloseaddressfamily)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[ProtocolClNotifyCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_notify_close_af)

[ProtocolCmNotifyCloseAfComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_notify_close_af_complete)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)