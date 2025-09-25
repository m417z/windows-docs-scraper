# EVT_WDF_IO_TARGET_REMOVE_CANCELED callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtIoTargetRemoveCanceled* event callback function performs operations when the removal of a specified remote I/O target is canceled.

## Parameters

### `IoTarget` [in]

A handle to an I/O target object.

## Remarks

To register an *EvtIoTargetRemoveCanceled* callback function, place the callback function's address in the I/O target's [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

If the driver's [EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove) callback function called [WdfIoTargetCloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcloseforqueryremove), the driver's *EvtIoTargetRemoveCanceled* callback function must call [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) to re-enable sending I/O requests to the I/O target. When the driver calls **WdfIoTargetOpen**, it can specify **WdfIoTargetOpenReopen** for the **Type** member of the [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

If the driver did not provide an [EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove) callback function, the driver's *EvtIoTargetRemoveCanceled* callback function can optionally call [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) and specify **WdfIoTargetOpenReopen**.

The optional *EvtIoTargetRemoveCanceled* callback function should perform any additional operations that might be necessary before the driver resumes sending I/O requests to the I/O target.

For more information about the *EvtIoTargetRemoveCanceled* callback function, see [Controlling a General I/O Target's State](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state).

## See also

[EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove)

[EvtIoTargetRemoveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_complete)

[WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params)

[WdfIoTargetCloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcloseforqueryremove)

[WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen)