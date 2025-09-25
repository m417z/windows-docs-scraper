# CameraControlProperty enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `CameraControlProperty` enumeration specifies a setting on a camera.

## Constants

### `CameraControl_Pan:0`

Specifies the camera's pan setting, in degrees. Values range from –180 to +180, with the default set to zero. Positive values are clockwise from the origin (the camera rotates clockwise when viewed from above), and negative values are counterclockwise from the origin.

### `CameraControl_Tilt`

Specifies the camera's tilt setting, in degrees. Values range from –180 to +180, with the default set to zero. Positive values point the imaging plane up, and negative values point the imaging plane down.

### `CameraControl_Roll`

Specifies the camera's roll setting, in degrees. Values range from –180 to +180, with the default set to zero. Positive values cause a clockwise rotation of the camera along the image-viewing axis, and negative values cause a counterclockwise rotation of the camera.

### `CameraControl_Zoom`

Specifies the camera's zoom setting, in millimeters. Values range from 10 to 600, and the default is specific to the device.

### `CameraControl_Exposure`

Specifies the exposure setting, in log base 2 seconds. In other words, for values less than zero, the exposure time is 1/2^n seconds, and for values zero or above, the exposure time is 2^n seconds. For example:

| Value | Seconds |
| --- | --- |
| -3 | 1/8 |
| -2 | 1/4 |
| -1 | 1/2 |
| 0 | 1 |
| 1 | 2 |
| 2 | 4 |

### `CameraControl_Iris`

Specifies the camera's iris setting, in units of fₛₜₒₚ* 10.

### `CameraControl_Focus`

Specifies the camera's focus setting, as the distance to the optimally focused target, in millimeters. The range and default value are specific to the device.

## Remarks

For a given property, a particular device might implement only a subset of the listed range.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMCameraControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcameracontrol)