# BatteryClassIoctl function

## Description

**BatteryClassIoctl** handles system-defined battery IOCTLs.

## Parameters

### `ClassData` [in]

Pointer to a battery class handle that was previously returned by [BatteryClassInitializeDevice](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassinitializedevice).

### `Irp` [in, out]

Pointer to the IRP containing the IOCTL to be handled.

## Return value

**BatteryClassIoctl** returns STATUS_SUCCESS when it satisfies the request and completes the IRP. It returns STATUS_NOT_SUPPORTED for all IRPs other than device control IRPs that specify battery IOCTLs.

## Remarks

**BatteryClassIoctl** handles and completes device control IRPs intended for the battery. Such IRPs have one of the following I/O control codes:

* IOCTL_BATTERY_QUERY_INFORMATION
* IOCTL_BATTERY_QUERY_STATUS
* IOCTL_BATTERY_QUERY_TAG
* IOCTL_BATTERY_SET_INFORMATION

The standard battery IOCTLs correspond to [battery miniclass driver routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_battery/) (BatteryMini*Xxx* routines).

When the miniclass driver is called with an [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control) request, it should determine whether the IRP contains any private IOCTL defined by the miniclass driver. If so, the miniclass driver should satisfy the request, complete the IRP, and return.

If the IRP contains a public IOCTL, the driver should pass the IRP to the class driver's **BatteryClassIoctl** routine. This routine examines the IRP, determines whether it applies to the caller's battery device, and if so, calls the appropriate [BatteryMiniXxx](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_battery/) routine to perform the requested operation.

If **BatteryClassIoctl** returns STATUS_NOT_SUPPORTED for the IRP, the miniclass driver must either complete the IRP or forward it to the next-lower driver.

## See also

[BatteryMiniQueryInformation](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_query_information_callback)

[BatteryMiniQueryStatus](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_query_status_callback)

[BatteryMiniQueryTag](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_query_tag_callback)

[BatteryMiniSetInformation](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_information_callback)