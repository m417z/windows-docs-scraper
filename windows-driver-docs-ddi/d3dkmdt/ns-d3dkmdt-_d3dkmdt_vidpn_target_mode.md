# D3DKMDT_VIDPN_TARGET_MODE structure

## Description

The **D3DKMDT_VIDPN_TARGET_MODE** structure contains information about a video present network (VidPN) target mode.

## Members

### `Id`

An integer that identifies the target mode. The identifier is generated and filled in by the VidPN manager. However, the display miniport driver has the option of overwriting the identifier. For more information, see [**pfnCreateNewModeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntargetmodeset_createnewmodeinfo).

### `VideoSignalInfo`

A [**D3DKMDT_VIDEO_SIGNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_signal_info) structure that contains information about the target mode (for example, video standard, resolution, refresh rate).

### `WireFormatAndPreference`

A [**D3DKMDT_WIRE_FORMAT_AND_PREFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_wire_format_and_preference) structure that specifies the wire format and preference.

### `Preference`

A [**D3DKMDT_MODE_PREFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_mode_preference) enumerator that indicates whether a particular mode is one of the modes that is preferred by the monitor that is connected to the video present target.

### `MinimumVSyncFreq`

The minimum vertical sync frequency of the monitor. Available starting in Windows Server 2022 (WDDM 2.9).

## Remarks

For more information about video present targets and VidPN target modes, see [Introduction to Video Present Networks](https://learn.microsoft.com/windows-hardware/drivers/display/introduction-to-video-present-networks) and [Enumerating Cofunctional VidPN Source and Target Modes](https://learn.microsoft.com/windows-hardware/drivers/display/enumerating-cofunctional-vidpn-source-and-target-modes).

## See also

[**D3DKMDT_MONITOR_SOURCE_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode)

[**D3DKMDT_VIDPN_SOURCE_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode)