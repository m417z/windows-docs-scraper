# VideoPortSetTrappedEmulatorPorts function

## Description

VGA-compatible (SVGA) miniport drivers call the **VideoPortSetTrappedEmulatorPorts** function to dynamically change the list of I/O ports that are trapped when a VDM (video display monitor) runs in full-screen mode on an x86-based machine.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `NumAccessRanges`

Specifies the number of elements in the *AccessRange* array.

### `AccessRange` [in]

Pointer to an array of [VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range) elements. Each element describes a proper subrange of the **EmulatorAccessEntries** that the miniport driver set up in [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info). Setting the **RangeVisible** member of an *AccessRange* element to **TRUE** enables direct access to the I/O port range by the full-screen MS-DOS application. Setting a **RangeVisible** member to **FALSE** causes application-issued **IN**s, **INSB/INSW/INSD**s, **OUT**s and/or **OUTSB/OUTSW/OUTSD**s to that range to be trapped and forwarded to the corresponding miniport driver *SvgaHwIoPortXxx* function for validation.

The *AccessRange* array passed to **VideoPortSetTrappedEmulatorPorts** must be a proper subset of the I/O port range(s) that the [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function set up in the **EmulatorAccessEntries** array of the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) structure. Any I/O port ranges in the access ranges array that are not included in the **EmulatorAccessEntries** array are trapped and reflected to the user-mode [VDD](https://learn.microsoft.com/windows-hardware/drivers/).

## Return value

**VideoPortSetTrappedEmulatorPorts** returns NO_ERROR if it successfully changed the trapped ports. Otherwise, it returns ERROR_INVALID_PARAMETER.

## Remarks

By default, the *AccessRange* of I/O ports that full-screen MS-DOS applications can access directly includes none of the access range array elements describing I/O port ranges that also have corresponding elements in the **EmulatorAccessEntries** array of the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) structure. That is, I/O port ranges with corresponding emulator access entries are, by default, hooked to the miniport driver's *SvgaHwIoPortXxx* functions so application-issued instructions are forwarded to the *SvgaHwIoPortXxx* functions for validation.

A VGA-compatible SVGA miniport driver can enable and disable ranges of I/O ports on an as-needed basis with calls to **VideoPortSetTrappedEmulatorPorts**. Enabled port ranges allow a full-screen MS-DOS application to access those I/O ports directly, without having application-issued assembly instructions trapped and forwarded to the miniport driver's *SvgaHwIoPortXxx* functions for validation first. Direct I/O port access for such an application gives the user faster video I/O response times.

**VideoPortSetTrappedEmulatorPorts** scans the *AccessRange* parameter array from the first element to the last, enabling and disabling I/O ports as directed in each element. Note that a range of enabled ports (the **RangeVisible** member set to **TRUE**) can be disabled again in the same call if the miniport driver includes a duplicate description of the same range with the **RangeVisible** member set to **FALSE**. Note also that a miniport driver can enable a wide range of I/O ports in the initial element of the *AccessRange* array and selectively disable subranges of ports in subsequent array elements when it calls **VideoPortSetTrappedEmulatorPorts**.

All full-screen MS-DOS applications use the same IOPM (I/O permission map) in x86-based machines and, therefore, the same set of enabled or disabled I/O ports. On each switch to such a full-screen application, a VGA-compatible miniport driver's [HwVidStartIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_io) function is called with the IOCTL_VIDEO_ENABLE_VDM [VRP](https://learn.microsoft.com/windows-hardware/drivers/). The miniport driver should then reinitialize a default set of directly accessible I/O ports, which can include any ports in the **EmulatorAccessEntries** array.

While giving full-screen MS-DOS applications on x86-based machines direct access to the video ports makes application-initiated video operations faster, every VGA-compatible SVGA miniport driver must continue to trap a subset of critical I/O ports to prevent such an application from hanging the machine. In particular, such miniport drivers should *always* trap application I/O to the VGA-compatible adapter sequencer and miscellaneous output registers. Such a miniport driver should also trap and validate application-issued direct I/O that could cause the machine to hang for any additional adapter-dependent subset of I/O ports.

Calling **VideoPortSetTrappedEmulatorPorts** again and resetting the **RangeVisible** member of an *AccessRange* element to **FALSE** causes the application-issued instructions for that range to be forwarded to the corresponding miniport driver *SvgaHwIoPortXxx* function.

## See also

[EMULATOR_ACCESS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_emulator_access_entry)

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[HwVidStartIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_io)

[VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsynchronizeexecution)