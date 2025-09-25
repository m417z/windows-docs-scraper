# CameraControlFlags enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CameraControlFlags** enumeration defines whether a camera setting is controlled manually or automatically.

## Constants

### `CameraControl_Flags_Auto:0x1`

The setting is controlled automatically.

### `CameraControl_Flags_Manual:0x2`

The setting is controlled manually.

## Remarks

In addition, the following flags are defined in Ksmedia.h:

| Flag | Value | Description |
| --- | --- | --- |
| **KSPROPERTY_CAMERACONTROL_FLAGS_AUTO** | 0X0001L | Equivalent to CameraControl_Flags_Auto. |
| **KSPROPERTY_CAMERACONTROL_FLAGS_MANUAL** | 0X0002L | Equivalent to CameraControl_Flags_Manual. |
| **KSPROPERTY_CAMERACONTROL_FLAGS_ABSOLUTE** | 0X0000L | The camera supports absolute units for this setting. |
| **KSPROPERTY_CAMERACONTROL_FLAGS_RELATIVE** | 0X0010L | The camera supports relative controls for this setting. A relative control is divided into a number of steps with no defined units. The absolute size of each step depends on the camera model. |

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMCameraControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcameracontrol)