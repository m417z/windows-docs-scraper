# EVT_WDF_IO_TARGET_QUERY_REMOVE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtIoTargetQueryRemove* event callback function indicates whether the framework can safely remove a specified remote I/O target's device.

## Parameters

### `IoTarget` [in]

A handle to an I/O target object.

## Return value

The*EvtIoTargetQueryRemove* callback function must return STATUS_SUCCESS if the driver determines that the framework can safely remove the specified I/O target's device. Otherwise, this callback function must return STATUS_UNSUCCESSFUL.

## Remarks

If a driver's *EvtIoTargetQueryRemove* callback function returns STATUS_SUCCESS, the system allows the I/O target's device to be removed, unless another driver returns STATUS_UNSUCCESSFUL.

To register an *EvtIoTargetQueryRemove* callback function, place the callback function's address in the I/O target's [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure. The *EvtIoTargetQueryRemove* callback function is optional. Not supplying this callback function is equivalent to returning STATUS_SUCCESS.

The *EvtIoTargetQueryRemove* callback function must call [WdfIoTargetCloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcloseforqueryremove), if the driver determines that the PnP manager can safely remove the target device.

The callback function must disable the driver's ability to send additional I/O requests to the I/O target.

For more information about the *EvtIoTargetQueryRemove* callback function, see [Controlling a General I/O Target's State](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state).

## See also

[EvtIoTargetRemoveCanceled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_canceled)

[EvtIoTargetRemoveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_complete)

[WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params)

[WdfIoTargetCloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcloseforqueryremove)