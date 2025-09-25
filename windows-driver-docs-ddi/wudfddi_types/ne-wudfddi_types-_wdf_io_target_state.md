# _WDF_IO_TARGET_STATE enumeration (wudfddi_types.h)

## Description

**[Applies to KMDF and UMDF]**

The **WDF_IO_TARGET_STATE** enumeration specifies the states that an I/O target can be in.

## Constants

### `WdfIoTargetStateUndefined`

Reserved for internal use.

### `WdfIoTargetStarted`

The I/O target is started and can process I/O requests.

### `WdfIoTargetStopped`

The I/O target is temporarily stopped and cannot process I/O requests.

### `WdfIoTargetClosedForQueryRemove`

The I/O target's underlying device might be removed in the near future.

### `WdfIoTargetClosed`

The I/O target is permanently stopped and cannot process I/O requests.

### `WdfIoTargetDeleted`

The I/O target's underlying device has been removed.

### `WdfIoTargetStateMaximum`

## Remarks

To obtain an I/O target's current state, call [WdfIoTargetGetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetgetstate).

For more information about states for I/O targets, see [Controlling a General I/O Target's State](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state).

## See also

[WdfIoTargetGetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetgetstate)