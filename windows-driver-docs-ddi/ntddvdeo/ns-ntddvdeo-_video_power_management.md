# _VIDEO_POWER_MANAGEMENT structure

## Description

The VIDEO_POWER_MANAGEMENT structure contains information required by the miniport driver to perform power management.

## Members

### `Length`

Is the size in bytes of this VIDEO_POWER_MANAGEMENT structure.

### `DPMSVersion`

Specifies the version of the Display Power Management Signaling (DPMS) standard supported by the device. Currently, the video port driver sets this member to zero, which corresponds with Version 1.0 of the [VESA](https://learn.microsoft.com/windows-hardware/drivers/) DPMS Standard.

### `PowerState`

Specifies the power management state to be set or queried. This member can be one of the following values in the VIDEO_POWER_STATE enumeration:

#### VideoPowerOn

The monitor and graphics adapter are both fully powered on and operational.

#### VideoPowerStandBy

The monitor is running at a reduced power level that requires a short recovery time to **VideoPowerOn**. The graphics adapter is powered on (registers are still active and video memory is refreshed); however, clocks might be lost.

#### VideoPowerSuspend

The monitor is running at a substantially reduced power level that requires a possibly longer recovery time than **VideoPowerStandBy** to **VideoPowerOn**. The graphics adapter is off.

#### VideoPowerOff

The monitor and graphics adapter are both off, consuming no power at all.

#### VideoPowerHibernate

The monitor and graphics adapter are both fully powered on and operational.

## Remarks

The video port driver allocates and fills in the VIDEO_POWER_MANAGEMENT structure. Depending on the power management request dispatched to the video port, the video port driver passes this structure to the miniport driver's [HwVidGetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_get) or [HwVidSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_set) routine.

**VideoPowerHibernate** is provided to the miniport driver as notification only. The miniport driver's *HwVidSetPowerState* function must leave the monitor and graphics adapter fully powered on and operational. For all other states, the miniport driver must put the device into the specified power state.

A driver will always enter all other power states from the **VideoPowerOn** state. For example, a driver will not move directly to **VideoPowerHibernate** from **VideoPowerOff**; it will always go from **VideoPowerHibernate** to **VideoPowerOn** and then to **VideoPowerOff**.

## See also

[HwVidGetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_get)

[HwVidSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_set)