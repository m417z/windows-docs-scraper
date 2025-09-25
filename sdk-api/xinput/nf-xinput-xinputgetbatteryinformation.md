# XInputGetBatteryInformation function

## Description

Retrieves the battery type and charge status of a wireless controller.

## Parameters

### `dwUserIndex` [in]

Index of the signed-in gamer associated with the device. Can be a value in the range 0–XUSER_MAX_COUNT − 1.

### `devType` [in]

Specifies which device associated with this user index should be queried. Must be **BATTERY_DEVTYPE_GAMEPAD** or **BATTERY_DEVTYPE_HEADSET**.

### `pBatteryInformation` [out]

Pointer to an [XINPUT_BATTERY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_battery_information) structure that receives the battery information.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[XInput Functions](https://learn.microsoft.com/windows/desktop/xinput/functions)