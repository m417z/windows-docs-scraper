# PoCallDriver function (ntifs.h)

## Description

The **PoCallDriver** routine passes a power [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) to the next-lower driver in the device stack. (Windows Server 2003, Windows XP, and Windows 2000 only.)

## Parameters

### `DeviceObject` [in]

A pointer to the driver-created [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) to which the IRP is to be routed.

### `Irp` [in, out]

A pointer to an IRP.

## Return value

**PoCallDriver** returns STATUS_SUCCESS to indicate success. It returns STATUS_PENDING if it has queued the IRP.

## Remarks

Beginning with Windows Vista, drivers should call [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver), not **PoCallDriver** to pass a power IRP to the next-lower driver. However, on Windows Server 2003, Windows XP, and Windows 2000, drivers must call **PoCallDriver**, not **IoCallDriver** to pass a power IRP to the next-lower driver. On Windows Server 2003, Windows XP, a Windows 2000, drivers must also call [PoStartNextPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-postartnextpowerirp) before calling **PoCallDriver**.

A driver that requires a new IRP should call [PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp). A driver must not allocate its own power IRP.

When passing a power IRP down to the next-lower driver, the caller should use [IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation) or [IoCopyCurrentIrpStackLocationToNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocopycurrentirpstacklocationtonext) to set the IRP stack location, then call **PoCallDriver**. Use **IoCopyCurrentIrpStackLocationToNext** if processing the IRP requires setting an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine, or **IoSkipCurrentStackLocation** if no *IoCompletion* routine is required.

When a device is powering up, its drivers must set *IoCompletion* routines to perform start-up tasks (initializing the device, restoring context, and so on) after the bus driver has set the device in the working state. Set *IoCompletion* routines before calling **PoCallDriver**.

When a device is powering down, its drivers must perform necessary power-down tasks before passing the IRP to the next lower driver. After the IRP has reached the bus driver, the device will be powered off and its drivers will no longer have access to it. On Windows Server 2003, Windows XP, and Windows 2000, an *IoCompletion* routine that is associated with a power-down IRP is only required to call **PoStartNextPowerIrp**.

Only one inrush IRP can be active in the system at a time. When passing a power-up IRP for a device that requires inrush current (in other words, the DO_POWER_INRUSH flag is set in the device object), **PoCallDriver** checks whether another inrush IRP is already active. If so, **PoCallDriver** queues the current IRP for handling after the previous IRP completes, and then returns STATUS_PENDING. For more information about inrush IRPs, see [Setting Device Object Flags for Power Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/setting-device-object-flags-for-power-management).

If an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) or [IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power) request is already active for *DeviceObject*, **PoCallDriver** queues this IRP and returns STATUS_PENDING.

On Windows 2000 and later systems, pageable drivers (the DO_POWER_PAGABLE flag is set in the device object) must call **PoCallDriver** at IRQL = PASSIVE_LEVEL. Drivers that cannot be paged (DO_POWER_PAGABLE is not set in the device object) or that require inrush current (DO_POWER_INRUSH is set in the device object) can call **PoCallDriver** at IRQL = PASSIVE_LEVEL or DISPATCH_LEVEL.

On Windows 98/Me, all drivers call **PoCallDriver** at IRQL = PASSIVE_LEVEL.

## See also

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power)

[IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine)

[IoCopyCurrentIrpStackLocationToNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocopycurrentirpstacklocationtonext)

[IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation)

[PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp)

[PoStartNextPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-postartnextpowerirp)