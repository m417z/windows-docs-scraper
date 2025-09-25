## Description

The **IoAttachDevice** routine attaches the caller's device object to a named target device object, so that I/O requests bound for the target device are routed first to the caller.

## Parameters

### `SourceDevice` [in]

Pointer to the caller-created device object.

### `TargetDevice` [in]

Pointer to a buffer containing the name of the device object to which the specified *SourceDevice* is to be attached.

### `AttachedDevice` [out]

Pointer to caller-allocated storage for a pointer. On return, contains a pointer to the target device object if the attachment succeeds.

## Return value

**IoAttachDevice** can return one of the following NTSTATUS values:

## Remarks

**IoAttachDevice** establishes layering between drivers so that the same IRPs can be sent to each driver in the chain.

This routine is used by intermediate drivers during initialization. It allows such a driver to attach its own device object to another device in such a way that any requests being made to the original device are given first to the intermediate driver.

The caller can be layered only at the top of an existing chain of layered drivers. **IoAttachDevice** searches for the highest device object layered over *TargetDevice* and attaches to that object (that can be the *TargetDevice*). Therefore, this routine must not be called if a driver that must be higher-level has already layered itself over the target device.

Note that for file system drivers and drivers in the storage stack, **IoAttachDevice** opens the target device with FILE_READ_ATTRIBUTES and then calls [IoGetRelatedDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetrelateddeviceobject). This does not cause a file system to be mounted. Thus, a successful call to **IoAttachDevice** returns the device object of the storage driver, not that of the file system driver.

This routine sets the **AlignmentRequirement** in *SourceDevice* to the value in the next-lower device object and sets the **StackSize** to the value in the next-lower object plus one.

> [!WARNING]
> *AttachedDevice* must point to a global memory location, such as the driver's device extension. **IoAttachDevice** opens the file object for the target device, updates *AttachedDevice*, performs the attach, and then closes the file object. Thus, the source device receives the [IRP_MJ_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-cleanup) and [IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close) requests for the file object before **IoAttachDevice** returns. The driver must forward these requests to the target device, and *AttachedDevice* must be a memory location accessible to the driver's [DispatchCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_dispatch) and [DispatchClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_dispatch) routines.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack)

[IoAttachDeviceToDeviceStackSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioattachdevicetodevicestacksafe)

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)

[IoDetachDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodetachdevice)

[IoGetRelatedDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetrelateddeviceobject)