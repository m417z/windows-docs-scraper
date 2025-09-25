# _DXGKARG_COMMITVIDPN_FLAGS structure

## Description

The DXGKARG_COMMITVIDPN_FLAGS structure identifies details about a call to the [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function.

## Members

### `PathPowerTransition`

A UINT value that specifies whether the Microsoft DirectX graphics kernel subsystem calls the [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function to power off a connected monitor.

If **PathPowerTransition** is set to **TRUE**, the display miniport driver can optimize this call for a power down (for example, the driver might disable vertical syncs). The driver must also be aware that it might still receive calls to its [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) function on the affected source.

Setting this member is equivalent to setting the first bit of a 32-bit value (0x00000001).

For more information, see the following Remarks section.

### `PathPoweredOff`

A UINT value that specifies whether the DirectX graphics kernel subsystem calls [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) to inform the driver that the user changed modes.

If **PathPoweredOff** is set to **TRUE**, the display miniport driver should expect present operations that are based on the new topology. The driver cannot perform any operations that would cause the topology path to be powered on again (for example, the driver cannot enable vertical syncs) because the monitor should now be powered off.

If **PathPoweredOff** is set to **FALSE**, the topology path is powered on. The display miniport driver should program hardware for present operations that are based on the former topology path, and the driver should commit hardware to support this topology path. Setting this member is equivalent to setting the second bit of a 32-bit value (0x00000002).

For more information, see the following Remarks section.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 30 bits (0xFFFFFFFC) of a 32-bit value to zeros.

## Remarks

The DXGKARG_COMMITVIDPN_FLAGS structure stores information that the display miniport driver can use to determine how to respond to requested mode changes. With this information, the driver can distinguish between mode changes that occur during regular activity because an application requested a mode change, changes that occur because of power transitions, and changes that occur while monitors are turned off.

During regular activity, when the [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function is called, both **PathPowerTransition** and **PathPoweredOff** members will be **FALSE** so that the driver should apply mode changes immediately. Such mode changes are usually performed as isolated events. Therefore, there is no need for the driver to track any state that is associated with the previous mode configuration.

If monitors are being turned off or turned on, **PathPowerTransition** will be **TRUE** to indicate a power transition. In this case, a common pattern is that the monitors will be turned off, and then at some later time, the original configuration will be restored. It can be a significant workload for the driver to reset the display configuration completely after a system shutdown. Additionally, , the driver must continue to complete [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) operations while the monitors are turned off. However, the driver can reduce its workload when a call is made to *DxgkDdiCommitVidPn* by making sure that the involved monitors are powered off. When power is restored, the driver workload to restore the display configuration will thereby be reduced.

Because the monitor might not be physically connected (at system resume time, for example), the driver should not rely on Windows to make a later call to the [DxgkDdiSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_set_power_state) function to set the power state of the child device of the display adapter. However, Windows will still request that the CRTC is to be turned on. If the driver does not turn on vertical sync when it is requested to do so by the display mode manager (DMM), and if the user later reconnects the monitor, the monitor display might be blank.

*DxgkDdiPresent* operations must still be honored by the driver while monitors are turned off. The driver might have to act upon a mode change triggered by an application, for example to perform modifications to the rendering pipeline to account for rotation changes. Settings of **PathPowerTransition** = **FALSE** and **PathPoweredOff** = **TRUE** inform the driver that such a mode change has occurred. In this case, the driver must not turn on the monitors, but instead it should reprogram the hardware, if it is necessary, to accommodate the mode change so that additional *DxgkDdiPresent* operations can be completed. When such a mode change has been performed, and monitors are later turned back on, it is unlikely that the mode that occurred before the power down will be restored.

If a system resume operation is triggered after monitors were turned off for a system suspend operation, the driver can receive a *DxgkDdiCommitVidPn* call with both **PathPowerTransition** = **FALSE** and **PathPoweredOff** = **FALSE** before a *DxgkDdiCommitVidPn* call is made with **PathPowerTransition** = **TRUE**. This situation should only occur with an empty topology and, in this case, the driver should not turn monitors back on because the power transition is not yet completed.

## See also

[DXGKARG_COMMITVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_commitvidpn)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)

[DxgkDdiSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_set_power_state)