## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Creates the default video presenter for the enhanced video renderer (EVR).

## Parameters

### `pOwner` [in]

Pointer to the owner of the object. If the object is aggregated, pass a pointer to the aggregating object's **IUnknown** interface. Otherwise, set this parameter to **NULL**.

### `riidDevice` [in]

Interface identifier (IID) of the video device interface that will be used for processing the video. Currently the only supported value is IID_IDirect3DDevice9.

### `riid` [in]

IID of the requested interface on the video presenter. The video presenter exposes the [IMFVideoPresenter](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideopresenter) interface.

### `ppVideoPresenter`

Receives a pointer to the requested interface on the video presenter. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)