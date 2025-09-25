## Description

The **DXGK_DISPLAYMUX_RUNTIME_STATUS** enumeration specifies the runtime status level of automatic display switch (ADS) support that the driver provides.

## Constants

### `DXGK_DISPLAYMUX_RUNTIME_STATUS_UNINITIALIZED:0`

A variable of this enumeration type hasn't yet been assigned a meaningful value.

### `DXGK_DISPLAYMUX_RUNTIME_STATUS_OK:1`

The GPU supports ADS and the driver has obtained required information from the system.

### `DXGK_DISPLAYMUX_RUNTIME_STATUS_NO_GPU_SUPPORT:2`

The GPU doesn't support ADS.

### `DXGK_DISPLAYMUX_RUNTIME_STATUS_NON_CRITICAL_SYSTEM_INFO_MISSING:3`

The driver couldn't obtain some non-critical information from the system. ADS can still function but the user's experience might be impacted.

### `DXGK_DISPLAYMUX_RUNTIME_STATUS_CRITICAL_SYSTEM_INFO_MISSING:4`

The driver couldn't obtain some critical information from the system. ADS can still function but the user's experience might be impacted.

## Remarks

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DxgkDdiDisplayMuxGetRuntimeStatus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_get_runtime_status)