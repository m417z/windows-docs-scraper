# WDF_IO_TARGET_OPEN_PARAMS_INIT_REOPEN function

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_TARGET_OPEN_PARAMS_INIT_REOPEN** function initializes a driver's [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure so the driver can reopen a remote I/O target.

## Parameters

### `Params` [out]

A pointer to a driver-allocated [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure, which the function initializes.

## Remarks

The [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure is used as input to the [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) method. Your driver should call **WDF_IO_TARGET_OPEN_PARAMS_INIT_REOPEN** to initialize a **WDF_IO_TARGET_OPEN_PARAMS** structure if the driver is calling **WdfIoTargetOpen** from within an [EvtIoTargetRemoveCanceled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_canceled) callback function.

The **WDF_IO_TARGET_OPEN_PARAMS_INIT_REOPEN** function zeros the specified [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure and sets the structure's **Size** member. Then, the function sets the **Type** member to [WdfIoTargetOpenReopen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_open_type).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example is a segment of an [EvtIoTargetRemoveCanceled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_canceled) callback function that reopens a remote I/O target.

```cpp
VOID
MyEvtIoTargetRemoveCanceled(
    WDFIOTARGET IoTarget
    )
{
    WDF_IO_TARGET_OPEN_PARAMS openParams;
    NTSTATUS status;

...
    WDF_IO_TARGET_OPEN_PARAMS_INIT_REOPEN(&openParams);
    status = WdfIoTargetOpen(
                             IoTarget,
                             &openParams
                             );
...
}
```

## See also

[EvtIoTargetRemoveCanceled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_canceled)

[WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params)

[WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen)

[WdfIoTargetOpenReopen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_open_type)