# IPersistMediaPropertyBag::Save

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Save` method saves properties from the filter into the media property bag.

## Parameters

### `pPropBag` [in]

Pointer to the [IMediaPropertyBag](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediapropertybag) interface of a media property bag created by the caller.

### `fClearDirty` [in]

Reserved. Can be any value.

### `fSaveAllProperties` [in]

Reserved. Can be any value.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Not implemented. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_DATA)** | Invalid data. |

## Remarks

If you call this method on the [AVI Splitter](https://learn.microsoft.com/windows/desktop/DirectShow/avi-splitter-filter) filter or the [WAVE Parser](https://learn.microsoft.com/windows/desktop/DirectShow/wave-parser-filter), the filter reads any INFO and DISP chunks from the file and stores them in the media property bag. You can use the [IMediaPropertyBag::EnumProperty](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediapropertybag-enumproperty) method to retrieve the chunks.

The [AVI Mux](https://learn.microsoft.com/windows/desktop/DirectShow/avi-mux-filter) filter does not implement this method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPersistMediaPropertyBag Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipersistmediapropertybag)