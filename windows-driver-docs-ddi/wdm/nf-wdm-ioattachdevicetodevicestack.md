# IoAttachDeviceToDeviceStack function

## Description

The **IoAttachDeviceToDeviceStack** routine attaches the caller's device object to the highest device object in the chain and returns a pointer to the previously highest device object.

## Parameters

### `SourceDevice` [in]

Pointer to the caller-created device object.

### `TargetDevice` [in]

Pointer to another driver's device object, such as a pointer returned by a preceding call to [IoGetDeviceObjectPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceobjectpointer).

## Return value

**IoAttachDeviceToDeviceStack** returns a pointer to the device object to which the *SourceDevice* was attached. The returned device object pointer can differ from *TargetDevice* if *TargetDevice* had additional drivers layered on top of it.

**IoAttachDeviceToDeviceStack** returns **NULL** if it could not attach the device object because, for example, the target device was being unloaded.

## Remarks

**IoAttachDeviceToDeviceStack** establishes layering between drivers so that the same IRPs are sent to each driver in the chain.

An intermediate driver can use this routine during initialization to attach its own device object to another driver's device object. Subsequent I/O requests sent to *TargetDevice* are sent first to the intermediate driver.

This routine sets the **AlignmentRequirement** in *SourceDevice* to the value in the next-lower device object and sets the **StackSize** to the value in the next-lower-object plus one.

A driver writer must take care to call this routine before any drivers that must layer on top of their driver. **IoAttachDeviceToDeviceStack** attaches *SourceDevice* to the highest device object currently layered in the chain and has no way to determine whether drivers are being layered in the correct order.

A driver that acquired a pointer to the target device by calling [IoGetDeviceObjectPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceobjectpointer) should call [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) with the file object pointer that was returned by **IoGetDeviceObjectPointer** to release its reference to the file object before it detaches its own device object, for example, when such a higher-level driver is unloaded.

## See also

[IoAttachDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevice)

[IoDetachDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodetachdevice)

[IoGetDeviceObjectPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceobjectpointer)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)