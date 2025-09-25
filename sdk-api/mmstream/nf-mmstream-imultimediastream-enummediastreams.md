# IMultiMediaStream::EnumMediaStreams

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `EnumMediaStreams` method retrieves a media stream object, specified by index.

## Parameters

### `Index` [in]

Zero-based index of the media stream to retrieve.

### `ppMediaStream` [out]

Address of a variable that receives an [IMediaStream](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imediastream) interface pointer.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_FALSE** | Index is out of range. |
| **S_OK** | Success. |

## Remarks

If the return value is S_OK, the caller must release the **IMediaStream** interface.

## See also

[IMultiMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imultimediastream)