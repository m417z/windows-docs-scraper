# MFCreateVideoMixerAndPresenter callback function

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Creates the default video mixer and video presenter for the enhanced video renderer (EVR).

## Parameters

### `pMixerOwner` [in]

Pointer to the owner of the video mixer. If the mixer is aggregated, pass a pointer to the aggregating object's **IUnknown** interface. Otherwise, set this parameter to **NULL**.

### `pPresenterOwner` [in]

Pointer to the owner of the video presenter. If the presenter is aggregated, pass a pointer to the aggregating object's **IUnknown** interface. Otherwise, set this parameter to **NULL**.

### `riidMixer` [in]

Interface identifier (IID) of the requested interface on the video mixer. The video mixer exposes the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface.

### `ppvVideoMixer` [out]

Receives a pointer to the requested interface on the video mixer. The caller must release the interface.

### `riidPresenter` [in]

IID of the requested interface on the video presenter. The video presenter exposes the [IMFVideoPresenter](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideopresenter) interface.

### `ppvVideoPresenter` [out]

Receives a pointer to the requested interface on the video presenter. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)