# IoAdjustPagingPathCount macro

## Description

The **IoAdjustPagingPathCount** routine increments or decrements a caller-supplied page-file counter as an atomic operation.

## Parameters

### `_count_` [in]

Pointer to a caller-supplied variable that contains a counter. A driver typically stores a page-file counter in the device extension for the device.

### `_paging_` [in]

Specifies whether the counter is to be incremented or decremented. A value of **TRUE** specifies an increment operation.

## Remarks

This routine is useful for maintaining a count of paging files on a device. The operating system notifies a driver that a paging file has been created on, or removed from, one of the driver's devices by sending an IRP. The IRP has the major code [IRP_MJ_PNP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-pnp) and the minor code [IRP_MN_DEVICE_USAGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-device-usage-notification).

This routine can be used for other counters, such as counters for hibernation files or crash-dump files.

## See also

[IRP_MJ_PNP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-pnp)

[IRP_MN_DEVICE_USAGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-device-usage-notification)