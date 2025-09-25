# IoAttachDeviceToDeviceStackSafe function

## Description

The **IoAttachDeviceToDeviceStackSafe** routine attaches the caller's device object to the topmost device object in a driver stack.

## Parameters

### `SourceDevice` [in]

Pointer to a caller-created device object.

### `TargetDevice` [in]

Pointer to the device object in the stack to which the *SourceDevice* object is to be attached.

### `AttachedToDeviceObject` [out]

On input, this parameter specifies the address of *SourceDevice->DeviceExtension->AttachedToDeviceObject*, which must contain a **NULL** pointer. On output, this parameter receives a pointer to the device object to which the *SourceDevice* was attached.

## Return value

**IoAttachDeviceToDeviceStackSafe** returns STATUS_SUCCESS if *SourceDevice* is successfully attached above the *TargetDevice*; otherwise it returns STATUS_NO_SUCH_DEVICE.

## Remarks

Like [IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack), **IoAttachDeviceToDeviceStackSafe** establishes layering between drivers so that the same IRPs are sent to each driver in the stack. However, unlike **IoAttachDeviceToDeviceStack**, **IoAttachDeviceToDeviceStackSafe** has an additional parameter, *AttachedToDeviceObject*, which the filter driver uses to pass the address of the *SourceDevice* object's AttachedToDeviceObject field. **IoAttachDeviceToDeviceStackSafe** updates this field while holding the I/O system database lock. Because it holds this lock, **IoAttachDeviceToDeviceStackSafe** avoids a race condition that could otherwise occur if the *SourceDevice* object received an IRP before its AttachedToDeviceObject field was updated.

A file system filter driver calls **IoAttachDeviceToDeviceStackSafe** to attach its own filter device object (*SourceDevice*) above a device object (*TargetDevice*) belonging to a file system or another filter driver. Subsequent I/O requests sent to *AttachedToDeviceObject* are received first by the filter driver, which processes them and forwards them down to the next driver in the stack by calling [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver).

If the device object specified by *TargetDevice* is currently at the top of the driver stack, the *SourceDevice* is attached directly to the *TargetDevice*. In this case, *TargetDevice* and the returned *AttachedToDeviceObject* pointer are equal.

If one or more filter device objects are already attached above the *TargetDevice* in the driver stack, **IoAttachDeviceToDeviceStackSafe** attaches the *SourceDevice* to the topmost filter device object. A pointer to the latter is returned in *AttachedToDeviceObject*.

At the moment immediately after it is attached to the top of the stack, the *SourceDevice* occupies the top of the driver stack. Note, however, that this does not necessarily mean that the *SourceDevice* will remain at the top of the driver stack. Other filters can attach their own filter device objects above the *SourceDevice* in the stack.

**IoAttachDeviceToDeviceStackSafe** sets the **AlignmentRequirement** member of the device object pointed to by *SourceDevice* to the value of the corresponding in the next-lower device object and sets the **StackSize** in *SourceDevice* to the value in the next-lower-object plus one.

## See also

[IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)