## Description

The **KsInitializeDriver** function initializes the driver object of an AVStream minidriver.

## Parameters

### `DriverObject` [in]

A pointer to the [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure for the AVStream driver being initialized. Minidrivers that call **KsInitializeDriver** should use the driver object passed to **DriverEntry** by the operating system.

### `RegistryPathName` [in]

A pointer to a Unicode string containing the registry path string passed into the minidriver's **DriverEntry** function by the operating system.

### `Descriptor` [in, optional]

A pointer to a [KSDEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_descriptor) structure that specifies the characteristics of the device being initialized. If this pointer is **NULL**, a device is created with default characteristics and no associated filter factories.

## Return value

**KsInitializeDriver** returns STATUS_SUCCESS or an appropriate error code as returned by [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) or internal AVStream device initialization routines.

## Remarks

This function is typically called from **DriverEntry**. If the minidriver passes in a device descriptor, AVStream creates a device with the specified characteristics at **AddDevice** time. Minidrivers that perform device initialization themselves do not necessarily need to call **KsInitializeDriver**. For more information, see [Initializing an AVStream Minidriver](https://learn.microsoft.com/windows-hardware/drivers/stream/initializing-an-avstream-minidriver).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[DriverEntry of AVStream](https://learn.microsoft.com/previous-versions/ff558721(v=vs.85))

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)

[KSDEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_descriptor)

[KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)

[KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor)

[KsInitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedevice)