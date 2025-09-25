# MFVideoRenderPrefs enumeration

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Contains flags that define how the enhanced video renderer (EVR) displays the video.

## Constants

### `MFVideoRenderPrefs_DoNotRenderBorder:0x1`

If this flag is set, the EVR does not draw the border color. By default, the EVR draws a border on areas of the destination rectangle that have no video. See [IMFVideoDisplayControl::SetBorderColor](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-setbordercolor).

### `MFVideoRenderPrefs_DoNotClipToDevice:0x2`

If this flag is set, the EVR does not clip the video when the video window straddles two monitors. By default, if the video window straddles two monitors, the EVR clips the video to the monitor that contains the largest area of video.

### `MFVideoRenderPrefs_AllowOutputThrottling:0x4`

**Note** Requires Windows 7 or later.

Allow the EVR to limit its output to match GPU bandwidth.

### `MFVideoRenderPrefs_ForceOutputThrottling:0x8`

**Note** Requires Windows 7 or later.

Force the EVR
to limit its output to match GPU bandwidth.

### `MFVideoRenderPrefs_ForceBatching:0x10`

**Note** Requires Windows 7 or later.

Force the EVR to batch Direct3D **Present** calls. This optimization enables the system to enter to idle states more frequently, which can reduce power consumption.

### `MFVideoRenderPrefs_AllowBatching:0x20`

**Note** Requires Windows 7 or later.

Allow the EVR to batch Direct3D **Present** calls.

### `MFVideoRenderPrefs_ForceScaling:0x40`

**Note** Requires Windows 7 or later.

Force the EVR to mix the video inside a rectangle that is smaller than the output rectangle. The EVR will then scale the result to the correct output size. The effective resolution will be lower if this setting is applied.

### `MFVideoRenderPrefs_AllowScaling:0x80`

**Note** Requires Windows 7 or later.

Allow
the EVR to mix the video inside a rectangle that is smaller than the output rectangle.

### `MFVideoRenderPrefs_DoNotRepaintOnStop:0x100`

**Note** Requires Windows 7 or later.

Prevent the EVR from repainting the video window after a stop command. By default, the EVR repaints the video window black after a stop command.

### `MFVideoRenderPrefs_Mask:0x1ff`

Bitmask to validate flag values. This value is not a valid flag.

## Remarks

To set these flags, call [IMFVideoDisplayControl::SetRenderingPrefs](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-setrenderingprefs).

The flags named "MFVideoRenderPrefs_Allow..." cause the EVR to use lower-quality settings only when requested by the quality manager. (For more information, see [IMFQualityAdvise](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadvise).) The flags named "MFVideoRenderPrefs_Force..." cause the video mixer to use lower-quality settings regardless of the quality manager.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)