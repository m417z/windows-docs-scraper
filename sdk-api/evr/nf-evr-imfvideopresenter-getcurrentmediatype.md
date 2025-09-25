# IMFVideoPresenter::GetCurrentMediaType

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Retrieves the presenter's media type.

## Parameters

### `ppMediaType` [out]

Receives a pointer to the [IMFVideoMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfvideomediatype) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_INITIALIZED** | The media type is not set. |
| **MF_E_SHUTDOWN** | The video renderer has been shut down |

## Remarks

This method returns the media type that the presenter sets for the mixer's output type. It describes the format of the composited image.

## See also

[How to Write an EVR Presenter](https://learn.microsoft.com/windows/desktop/medfound/how-to-write-an-evr-presenter)

[IMFVideoPresenter](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideopresenter)