# DISPLAYCONFIG_PATH_TARGET_INFO structure

## Description

The DISPLAYCONFIG_PATH_TARGET_INFO structure contains target information for a single path.

## Members

### `adapterId`

The identifier of the adapter that the path is on.

### `id`

The target identifier on the specified adapter that this path relates to.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.modeInfoIdx`

A valid index into the mode information table that contains the target mode information for this path only when DISPLAYCONFIG_PATH_SUPPORT_VIRTUAL_MODE is not set. If target mode information is not available, the value of **modeInfoIdx** is DISPLAYCONFIG_PATH_MODE_IDX_INVALID.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.desktopModeInfoIdx`

A valid index into the mode array of the [DISPLAYCONFIG_DESKTOP_IMAGE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_desktop_image_info) entry that contains the desktop mode information for this path only when DISPLAYCONFIG_PATH_SUPPORT_VIRTUAL_MODE is set. If there is no entry for this in the mode array, the value of **desktopModeInfoIdx** is DISPLAYCONFIG_PATH_DESKTOP_IMAGE_IDX_INVALID. Supported starting in Windows 10.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.targetModeInfoIdx`

A valid index into the mode array of the [DISPLAYCONFIG_TARGET_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_mode) entry that contains the target mode information for this path only when DISPLAYCONFIG_PATH_SUPPORT_VIRTUAL_MODE is set. If there is no entry for this in the mode array, the value of **targetModeInfoIdx** is DISPLAYCONFIG_PATH_TARGET_MODE_IDX_INVALID. Supported starting in Windows 10.

### `outputTechnology`

The target's connector type. For a list of possible values, see the [DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_video_output_technology) enumerated type.

### `rotation`

A value that specifies the rotation of the target. For a list of possible values, see the [DISPLAYCONFIG_ROTATION](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_rotation) enumerated type.

### `scaling`

A value that specifies how the source image is scaled to the target. For a list of possible values, see the [DISPLAYCONFIG_SCALING](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_scaling) enumerated type. For more information about scaling, see [Scaling the Desktop Image](https://learn.microsoft.com/windows-hardware/drivers/display/scaling-the-desktop-image).

### `refreshRate`

A [DISPLAYCONFIG_RATIONAL](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_rational) structure that specifies the refresh rate of the target. If the caller specifies target mode information, the operating system will instead use the refresh rate that is stored in the **vSyncFreq** member of the [DISPLAYCONFIG_VIDEO_SIGNAL_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_video_signal_info) structure. In this case, the caller specifies this value in the **targetVideoSignalInfo** member of the [DISPLAYCONFIG_TARGET_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_mode) structure. A refresh rate with both the numerator and denominator set to zero indicates that the caller does not specify a refresh rate and the operating system should use the most optimal refresh rate available. For this case, in a call to the [SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig) function, the caller must set the **scanLineOrdering** member to the DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED value; otherwise, **SetDisplayConfig** fails.

### `scanLineOrdering`

A value that specifies the scan-line ordering of the output on the target. For a list of possible values, see the [DISPLAYCONFIG_SCANLINE_ORDERING](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_scanline_ordering) enumerated type. If the caller specifies target mode information, the operating system will instead use the scan-line ordering that is stored in the **scanLineOrdering** member of the [DISPLAYCONFIG_VIDEO_SIGNAL_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_video_signal_info) structure. In this case, the caller specifies this value in the **targetVideoSignalInfo** member of the [DISPLAYCONFIG_TARGET_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_mode) structure.

### `targetAvailable`

A Boolean value that specifies whether the target is available. **TRUE** indicates that the target is available.

Because the asynchronous nature of display topology changes when a monitor is removed, a path might still be marked as active even though the monitor has been removed. In such a case, **targetAvailable** could be **FALSE** for an active path. This is typically a transient situation that will change after the operating system takes action on the monitor removal.

### `statusFlags`

A bitwise OR of flag values that indicates the status of the target. The following values are supported:

| Value | Meaning |
| --- | --- |
| **DISPLAYCONFIG_TARGET_IN_USE**<br><br>0x00000001 | Target is in use on an active path. |
| **DISPLAYCONFIG_TARGET_FORCIBLE**<br><br>0x00000002 | The output can be forced on this target even if a monitor is not detected. |
| **DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_BOOT**<br><br>0x00000004 | Output is currently being forced in a boot-persistent manner. |
| **DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_PATH**<br><br>0x00000008 | Output is currently being forced in a path-persistent manner. |
| **DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_SYSTEM**<br><br>0x00000010 | Output is currently being forced in a nonpersistent manner. |
| **DISPLAYCONFIG_TARGET_IS_HMD**<br><br>0x00000020 | The output is a head-mounted display (HMD). Such a path is only returned from QueryDisplayConfig using the QDC_INCLUDE_HMD flag.<br><br>Supported starting in the Windows 10 Creators Update (Version 1703). |

## Remarks

A DISPLAYCONFIG_PATH_TARGET_INFO structure is specified in the **targetInfo** member of a [DISPLAYCONFIG_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_info) structure.

A target corresponds to the number of possible video outputs on a display adapter. This number, however, does not equate to the number of physical connectors on the display adapter. Each connector exposes a number of targets that includes backward compatibility with older connector technology. For example, a DVI connector exposes a DVI target, as well as a VGA target. A DisplayPort connector, which was introduced in 2006, exposes DisplayPort, HDMI, DVI, legacy TV, and VGA targets.

The **statusFlags** member is set when you call the [QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig) function.

## See also

[DISPLAYCONFIG_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_info)

[DISPLAYCONFIG_RATIONAL](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_rational)

[DISPLAYCONFIG_ROTATION](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_rotation)

[DISPLAYCONFIG_SCALING](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_scaling)

[DISPLAYCONFIG_SCANLINE_ORDERING](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_scanline_ordering)

[DISPLAYCONFIG_TARGET_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_mode)

[DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_video_output_technology)

[DISPLAYCONFIG_VIDEO_SIGNAL_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_video_signal_info)

[QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig)