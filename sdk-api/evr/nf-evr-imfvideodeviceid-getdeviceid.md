# IMFVideoDeviceID::GetDeviceID

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Returns the identifier of the video device supported by an EVR mixer or presenter.

## Parameters

### `pDeviceID` [out]

Receives the device identifier. Generally, the value is IID_IDirect3DDevice9.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The video renderer has been shut down. |

## Remarks

If a mixer or presenter uses Direct3D 9, it must return the value IID_IDirect3DDevice9 in *pDeviceID*. The EVR's default mixer and presenter both return this value. If you write a custom mixer or presenter, it can return some other value. However, the mixer and presenter must use matching device identifiers.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoDeviceID](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideodeviceid)