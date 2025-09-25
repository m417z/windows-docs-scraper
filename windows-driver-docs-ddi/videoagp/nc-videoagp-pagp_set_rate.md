# PAGP_SET_RATE callback function

## Description

The **AgpSetRate** function reprograms the data transfer rate of the AGP chipset.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `AgpRate` [in]

Specifies the transfer rate to be set. This value can be one of the following:

|Value|Meaning|
|--- |--- |
|VIDEO_AGP_RATE_1X|Single speed (66 Mhz)|
|VIDEO_AGP_RATE_2X|Two times single speed|
|VIDEO_AGP_RATE_4X|Four times single speed|
|VIDEO_AGP_RATE_8X|Eight times single speed|

## Return value

**AgpSetRate** returns **TRUE** if it was successful in changing the transfer rate; otherwise, it returns **FALSE**.

## Remarks

This function is available in Microsoft Windows XP and later.

The transfer rate set by the **AgpSetRate** function is persistent across changes in power state. The video miniport driver does not have to reset the AGP transfer rate when it changes from a low power state to a full power state. For information about change of power state, see [HwVidSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_set).

The **AgpSetRate** function can be used to change an AGP chipset's data transfer rate to any of the rates shown in the preceding table, as long as that transfer rate has not been explicitly eliminated in the INF file that loaded the display driver. For more information, see [Display INF File Sections](https://learn.microsoft.com/windows-hardware/drivers/display/display-inf-file-sections).

## See also

[VIDEO_PORT_AGP_INTERFACE_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_agp_interface_2)