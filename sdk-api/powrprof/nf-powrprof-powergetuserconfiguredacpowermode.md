# PowerGetUserConfiguredACPowerMode function

## Description

Retrieves the user configured power mode GUID when the device is in an AC (adapter/charge) supply state.

## Parameters

### `PowerModeGuid` [out]

A pointer to a GUID buffer that receives the user configured power mode GUID on a successful return.

| Value | Meaning |
|------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|
| **GUID_POWER_MODE_BEST_EFFICIENCY**<br>961cc777-2547-4f9d-8174-7d86181b8a7a | This power mode indicates the device is biased towards energy efficiency. |
| **GUID_POWER_MODE_NONE**<br>00000000-0000-0000-0000-000000000000 | This power mode indicates the device has a balance between performance and energy efficiency. |
| **GUID_POWER_MODE_BEST_PERFORMANCE**<br>ded574b5-45a0-4f42-8737-46345c09c238 | This power mode indicates the device is biased towards performance. |

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**. If the function fails, it returns a system error code.

## Remarks

Windows comes installed with three default power modes that have preconfigured power setting values: "Best Power Efficiency", "Balanced", and "Best Performance". These power modes cannot be removed or changed and are the only supported values for the user configured power mode.

> [!NOTE]
> Power modes were previously referred to as "overlays" or "overlay schemes".

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)