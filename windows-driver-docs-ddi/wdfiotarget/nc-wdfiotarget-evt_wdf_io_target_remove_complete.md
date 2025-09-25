# EVT_WDF_IO_TARGET_REMOVE_COMPLETE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtIoTargetRemoveComplete* event callback function performs operations when the removal of a specified remote I/O target is complete.

## Parameters

### `IoTarget` [in]

A handle to an I/O target object.

## Remarks

To register an *EvtIoTargetRemoveComplete* callback function, place the callback function's address in the I/O target's [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

The framework calls your driver's *EvtIoTargetRemoveComplete* callback function after the driver's [EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove) callback function returns STATUS_SUCCESS, or after the device has been removed unexpectedly (surprise-removed).

A driver's *EvtIoTargetRemoveComplete* callback function must permanently close the remote I/O target by calling [WdfIoTargetClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetclose). Because the target device has been removed, the *EvtIoTargetRemoveComplete* callback function should also perform any additional target-removal operations that might be necessary, such as releasing system resources that the driver might have allocated when it opened the target.

The *EvtIoTargetRemoveComplete* callback function is optional. If the driver does not supply this callback function, the framework permanently closes the I/O target.

For more information about the *EvtIoTargetRemoveComplete* callback function, see [Controlling a General I/O Target's State](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state).

## See also

[EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove)

[EvtIoTargetRemoveCanceled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_canceled)

[WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params)

[WdfIoTargetClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetclose)