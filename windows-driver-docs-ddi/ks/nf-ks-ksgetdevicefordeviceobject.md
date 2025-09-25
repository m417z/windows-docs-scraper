# KsGetDeviceForDeviceObject function

## Description

The **KsGetDeviceForDeviceObject** function returns the AVStream device structure for a given functional device object.

## Parameters

### `FunctionalDeviceObject` [in]

A pointer to the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) for which to return the corresponding [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure.

## Return value

**KsGetDeviceForDeviceObject** returns a pointer to the [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure corresponding to *FunctionalDeviceObject*. It returns **NULL** if *FunctionalDeviceObject* is a child PDO.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KsGetFilterFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetfilterfromfileobject)