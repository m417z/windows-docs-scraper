# KsCreateDevice function

## Description

The **KsCreateDevice** function creates an AVStream device.

## Parameters

### `DriverObject` [in]

A pointer to the WDM driver object of the minidriver.

### `PhysicalDeviceObject` [in]

A pointer to the WDM physical device object for the device you want to create under AVStream.

### `Descriptor` [in, optional]

A pointer to a device descriptor that describes the characteristics of the device being created. If the caller does not specify this optional parameter, AVStream creates a device with default characteristics and no associated filter factories.

### `ExtensionSize` [in]

This parameter contains the size of the device extension. If this is zero, the default extension size is used. If not, it must be at least sizeof (KSDEVICE_HEADER).

### `Device` [out, optional]

A pointer to a memory location that contains the address of the created [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure. Optional.

## Return value

Returns STATUS_SUCCESS if the device is created successfully. Otherwise, it returns an appropriate error code.

## Remarks

Normally, the minidriver does not call this function directly. Instead, **KsCreateDevice** is called by the default *AddDevice* handler, [KsAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadddevice). Because **KsAddDevice** makes an internal call to **KsCreateDevice**, drivers that call **KsCreateDevice** should not call **KsAddDevice** separately.

A minidriver that calls **KsCreateDevice** directly should not use [KsInitializeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedriver). If the minidriver is not calling **KsInitializeDriver**, it should instead provide its own *AddDevice* callback. The minidriver can then call **KsCreateDevice** from that *AddDevice* callback.

If no [KSDEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_descriptor) is provided, AVStream creates a device with the default characteristics and no associated filter factories. If a KSDEVICE_DESCRIPTOR is supplied and contains a [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) table with a create dispatch, the create dispatch is called.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KSDEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_descriptor)

[KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)

[KsAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadddevice)

[KsInitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedevice)

[KsInitializeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedriver)