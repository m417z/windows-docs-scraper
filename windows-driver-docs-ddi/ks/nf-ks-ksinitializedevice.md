# KsInitializeDevice function

## Description

The **KsInitializeDevice** function is called by AVStream to initialize the AVStream device class from within [KsCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatedevice).

## Parameters

### `FunctionalDeviceObject` [in]

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure representing the WDM functional device object for the device being initialized.

Normally, this is returned from an [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) call. Minidrivers calling this function directly are responsible for calling **IoCreateDevice** and attaching themselves to the device stack.

### `PhysicalDeviceObject` [in]

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure representing the WDM physical device object for the device being initialized.

### `NextDeviceObject` [in]

A pointer to the next [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure in the device stack as determined by a call to [IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack).

### `Descriptor` [in, optional]

A pointer to a [KSDEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_descriptor) structure that describes the characteristics of the device being initialized. If this parameter is **NULL**, the device is initialized with the default characteristics and has no associated filter factories.

## Return value

**KsInitializeDevice** returns STATUS_SUCCESS if the device was successfully initialized. Otherwise, it returns an appropriate error code.

## Remarks

Most minidrivers do not call this function directly. Only call **KsInitializeDevice** if your minidriver does not use [KsInitializeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedriver) for initialization, handles **AddDevice** independently, and does not use [KsAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadddevice) or [KsCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatedevice) in its **AddDevice** handler.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack)

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KsAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadddevice)

[KsCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatedevice)

[KsInitializeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedriver)

[KsTerminateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksterminatedevice)