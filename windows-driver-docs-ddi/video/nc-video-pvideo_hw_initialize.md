# PVIDEO_HW_INITIALIZE callback function

## Description

*HwVidInitialize* performs the first initialization of the adapter, after the HAL has given up control of the video hardware to the video port driver.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

## Return value

If the initialization succeeds, *HwVidInitialize* returns **TRUE**.

## Remarks

Every video miniport driver must have a *HwVidInitialize* function.

The video port driver calls *HwVidInitialize* in response to an open request by the corresponding display driver. As soon as *HwVidInitialize* is called, the miniport driver can change the state of the adapter, unlike the miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function, which must leave the adapter in VGA mode. On return from *HwVidInitialize*, the adapter must be initialized to a state equivalent to that set up by the miniport driver's [HwVidResetHw](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_reset_hw) function. This feature is used by autodetection to get mode information from the miniport driver.

If at all possible, *HwVidInitialize* should avoid programming the device hardware. The miniport driver will initialize the device later, when it is instructed to switch display modes.

*HwVidInitialize* should be made pageable.

## See also

[DrvAssertMode](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvassertmode)

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[HwVidResetHw](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_reset_hw)