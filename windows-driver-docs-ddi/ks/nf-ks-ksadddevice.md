# KsAddDevice function

## Description

The **KsAddDevice** function is the default *AddDevice* handler installed by [KsInitializeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedriver).

## Parameters

### `DriverObject` [in]

A pointer to the WDM driver object for the minidriver.

### `PhysicalDeviceObject` [in]

A pointer to the WDM physical device object.

## Return value

Returns STATUS_SUCCESS indicating the device was successfully created or an error status from [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) or [KsInitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedevice).

## Remarks

Normally, an AVStream minidriver does not call this function directly.

For more information, see [AddDevice Routine for AVStream Minidrivers](https://learn.microsoft.com/previous-versions/ff554081(v=vs.85)).

**KsAddDevice** extracts the device descriptor stored in the device extension allocated from a call to [KsInitializeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedriver) and creates the device described by it. If **KsInitializeDriver** is not used to initialize the driver, this function creates a device with the default characteristics and no filter factories. The minidriver always has the option of calling [KsCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatedevice) directly, in which case the driver extension is not used by AVStream. Because **KsAddDevice** calls **KsCreateDevice**, drivers that call **KsAddDevice** should not call **KsCreateDevice** separately.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KsCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatedevice)

[KsDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdispatchirp)

[KsInitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedevice)

[KsInitializeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedriver)