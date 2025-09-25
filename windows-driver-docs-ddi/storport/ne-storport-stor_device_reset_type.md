# STOR_DEVICE_RESET_TYPE enumeration

## Description

The **STOR_DEVICE_RESET_TYPE** enum specifies the type of device reset being requested in a call to [**StorPortHardwareReset**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storporthardwarereset).

## Constants

### `StorFunctionLevelReset`

The reset operation request is for a function-level device reset. In this case, the reset operation is restricted to a specific device, and is not visible to other devices. The device stays connected to the bus throughout the reset and returns to a valid (initial) state after the reset.

### `StorPlatformLevelReset`

The reset operation request is for a platform-level device reset. In this case, the reset operation causes the device to be reported as missing from the bus. The reset operation affects a specific device and all other devices that are connected to it via the same power rail or reset line. This type of reset has the most impact on the system. The OS will tear down and rebuild the stacks of all affected devices to ensure that everything restarts from a blank state.

### `StorBusSpecificReset`

The reset operation request is for a bus-specific reset.

## Remarks

See [Resetting and recovering a device](https://learn.microsoft.com/windows-hardware/drivers/kernel/resetting-and-recovering-a-device) for more details.

## See also

[**StorPortHardwareReset**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storporthardwarereset)