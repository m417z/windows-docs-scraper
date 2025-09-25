# KsTerminateDevice function

## Description

The **KsTerminateDevice** function removes an AVStream device.

## Parameters

### `DeviceObject` [in]

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure corresponding to the device for which to remove AVStream support.

## Remarks

Normally, AVStream calls **KsTerminateDevice** upon receipt of a PnP remove device IRP (IRP_MN_REMOVE_DEVICE). Most minidrivers do not call this function directly; however, it can be used to remove AVStream support for the device given in *DeviceObject*.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KsAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadddevice)

[KsCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatedevice)

[KsInitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedevice)

[KsInitializeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedriver)