# _D3DKMDT_DISPLAYMODE_FLAGS structure

## Description

The D3DKMDT_DISPLAYMODE_FLAGS structure identifies attributes of a display mode.

## Members

### `ValidatedAgainstMonitorCaps`

A Boolean value that specifies whether the display mode is supported by the monitor that the display mode will be displayed on.

Setting this member is equivalent to setting the first bit of a 32-bit value (0x00000001).

A UINT value that specifies whether the display mode is supported by the monitor that the display mode will be displayed on.

Setting this member is equivalent to setting the first bit of a 32-bit value (0x00000001).

Supported starting with Windows 8.

### `RoundedFakeMode`

A Boolean value that specifies whether the display mode is rounded.

Setting this member is equivalent to setting the second bit of a 32-bit value (0x00000002).

A UINT value that specifies whether the display mode is rounded.

Setting this member is equivalent to setting the second bit of a 32-bit value (0x00000002).

Supported starting with Windows 8.

### `ModePruningReason` [in]

A value of type [D3DKMDT_MODE_PRUNING_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmdt_mode_pruning_reason) that identifies the reason why the monitor either supports the display mode or does not support the display mode. The four bits are defined by one of the values in the **D3DKMDT_MODE_PRUNING_REASON** enumeration type and depend on the setting of the **ValidatedAgainstMonitorCaps** member. For more information about how the **ModePruningReason** value is set, see **D3DKMDT_MODE_PRUNING_REASON**.

Setting this member is equivalent to setting bits 4 through 7 of a 32-bit value (0x0000003C).

[in] A value of type [D3DKMDT_MODE_PRUNING_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmdt_mode_pruning_reason) that identifies the reason why the monitor either supports the display mode or does not support the display mode. The four bits are defined by one of the values in the **D3DKMDT_MODE_PRUNING_REASON** enumeration type and depend on the setting of the **ValidatedAgainstMonitorCaps** member. For more information about how the **ModePruningReason** value is set, see **D3DKMDT_MODE_PRUNING_REASON**.
This member is equivalent to bits 4 through 7 of a 32-bit value (0x0000003C).

Supported starting with Windows 8.

### `Stereo` [in]

A UINT value that specifies whether stereo is supported by the monitor that the display mode will be displayed on.

Setting this member is equivalent to setting the eighth bit of a 32-bit value (0x00000080).

Supported starting with Windows 8.

### `AdvancedScanCapable` [in]

A UINT value that specifies whether the driver supports the advanced scan capability.

The driver reports support for this option in the current display mode by setting the **Type** member of the [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure to **D3DKMDT_RMT_GRAPHICS_STEREO_ADVANCED_SCAN**.
Setting this member is equivalent to setting the ninth bit of a 32-bit value (0x00000100).

Supported starting with Windows 8.

### `PreferredTiming`

A UINT value that specifies whether the driver supports preferred timing.

### `PhysicalModeSupported`

A UINT value that specifies whether the driver supports physical mode.

### `Reserved`

This member is reserved and should be set to zero. Setting this member is equivalent to setting the remaining 28 bits (0xFFFFFFF0) of a 32-bit value to zeros.

This member is reserved and should be set to zero.

Setting this member is equivalent to setting the remaining 26 bits (0xFFFFFFC0) of a 32-bit value to zeros.

Supported starting with Windows 8.

### `VirtualRefreshRate`

A UINT value that specifies whether the driver supports virtual refresh rate.

## See also

[D3DKMDT_MODE_PRUNING_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmdt_mode_pruning_reason)

[D3DKMT_DISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode)