# StorPortHardwareReset function

## Description

A storage miniport can call **StorPortHardwareReset** to issue a hardware reset.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport's device extension.

### `Type`

A [**STOR_DEVICE_RESET_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_device_reset_type) enum that specifies the type of reset to be issued. Currently, *Type* must be set to **StorFunctionLevelReset**.

## Return value

**StorPortHardwareReset** returns a status code such as the following:

| Return code | Description |
|-------------|-------------|
| STOR_STATUS_INVALID_PARAMETER | *HwDeviceExtension* is invalid. |
| STOR_STATUS_NOT_IMPLEMENTED | **Type** values other than **StorFunctionLevelReset** are not implemented. |
| STOR_STATUS_SUCCESS | The hardware reset completed successfully. |
| STOR_STATUS_UNSUCCESSFUL | The operation failed. |

## Remarks

See [Resetting and recovering a device](https://learn.microsoft.com/windows-hardware/drivers/kernel/resetting-and-recovering-a-device) for more details.

## See also

[**STOR_DEVICE_RESET_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_device_reset_type)