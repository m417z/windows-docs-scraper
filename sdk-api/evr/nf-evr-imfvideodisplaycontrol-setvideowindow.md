# IMFVideoDisplayControl::SetVideoWindow

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Sets the clipping window for the video.

## Parameters

### `hwndVideo` [in]

Handle to the window where the enhanced video renderer (EVR) will draw the video.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *hwndVideo* does not specify a valid window. |
| **S_FALSE** | DWM thumbnails were not enabled/disabled. |

## Remarks

The EVR will not display any video unless the application calls this method with a valid window handle.

For protected content, this method might disable Desktop Window Manager (DWM) thumbnail previews for the window. If thumbnail previews cannot be disabled, the method returns S_FALSE.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoDisplayControl](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideodisplaycontrol)

[Using the Video Display Controls](https://learn.microsoft.com/windows/desktop/medfound/using-the-video-display-controls)