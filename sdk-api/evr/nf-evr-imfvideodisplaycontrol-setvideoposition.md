# IMFVideoDisplayControl::SetVideoPosition

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Sets the source and destination rectangles for the video.

## Parameters

### `pnrcSource` [in]

Pointer to an [MFVideoNormalizedRect](https://learn.microsoft.com/windows/desktop/api/evr/ns-evr-mfvideonormalizedrect) structure that specifies the source rectangle. This parameter can be **NULL**. If this parameter is **NULL**, the source rectangle does not change.

### `prcDest` [in]

Specifies the destination rectangle. This parameter can be **NULL**. If this parameter is **NULL**, the destination rectangle does not change.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one parameter must be non-**NULL**. |
| **MF_E_SHUTDOWN** | The video renderer has been shut down. |

## Remarks

The source rectangle defines which portion of the video is displayed. It is specified in *normalized* coordinates. For more information, see [MFVideoNormalizedRect](https://learn.microsoft.com/windows/desktop/api/evr/ns-evr-mfvideonormalizedrect) structure. To display the entire video image, set the source rectangle to {0, 0, 1, 1}. The default source rectangle is {0, 0, 1, 1}.

The destination rectangle defines a rectangle within the clipping window where the video appears. It is specified in pixels, relative to the client area of the window. To fill the entire window, set the destination rectangle to {0, 0, *width*, *height*}, where *width* and *height* are dimensions of the window client area. The default destination rectangle is {0, 0, 0, 0}.

To update just one of these rectangles, set the other parameter to **NULL**. You can set *pnrcSource* or *prcDest* to **NULL**, but not both.

Before setting the destination rectangle (*prcDest*), you must set the video window by calling [IMFVideoDisplayControl::SetVideoWindow](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-setvideowindow). (For the Media Foundation version of the EVR, you can also provide the video window in the [MFCreateVideoRendererActivate](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatevideorendereractivate) function.) If no video window was provided, **SetVideoPosition** returns E_POINTER.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoDisplayControl](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideodisplaycontrol)

[Using the Video Display Controls](https://learn.microsoft.com/windows/desktop/medfound/using-the-video-display-controls)