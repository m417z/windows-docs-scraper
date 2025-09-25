# KsDeviceRegisterThermalDispatch function

## Description

This function is used by the Avstream miniport driver to register callbacks for thermal notifications with the KS port driver.

## Parameters

### `KsDevice` [in]

A KS device object representing the device managed by KS. For more information, see [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice).

### `KsDeviceThermalDispatch` [in]

A structure containing the Avstream driver active and passive thermal callback notifications.

## Return value

Returns NTSTATUS STATUS_SUCCESS for success conditions or STATUS_INVALID_DEVICE_REQUEST if both the parameters are NULL.

## Remarks

**KsDeviceRegisterThermalDispatch** takes two arguments:

* A KS device object that represents the hardware device managed by the KS port driver (a camera in this case).
* Thermal dispatch callback functions.

For more information, see [Device-Level Thermal Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-level-thermal-management).

## See also

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)