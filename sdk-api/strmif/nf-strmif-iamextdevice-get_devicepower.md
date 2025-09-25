# IAMExtDevice::get_DevicePower

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_DevicePower` method retrieves the external device's power mode.

## Parameters

### `pPowerMode` [out]

Pointer to a **long** integer that receives one of the following values, indicating the device's power mode.

| Value | Description |
| --- | --- |
| ED_POWER_OFF | Power is off. |
| ED_POWER_ON | Power if on. |
| ED_POWER_STANDBY | Device is in standby mode. |

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

In Windows XP Service Pack 2 and later, the following additional power mode is defined.

| Value | Description |
| --- | --- |
| ED_POWER_DEVICE_DEPENDENT | Power is on with limited functions. |

To use this constant, include the header file Xprtdefs.h.

### DV and MPEG Camcorder Implementation

The [MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) and UVC drivers return ED_POWER_ON when the camcorder is on. If the camcorder is off or in standby mode, the DV driver is not loaded, so this method is not available. If the camcorder is removed unexpectedly, the method can return ERROR_GEN_FAILURE.

[MSTape](https://learn.microsoft.com/windows/desktop/DirectShow/mstape-driver) supports both ED_POWER_OFF and ED_POWER_ON, but not ED_POWER_STANDBY.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtDevice Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamextdevice)

[IAMExtDevice::put_DevicePower](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamextdevice-put_devicepower)