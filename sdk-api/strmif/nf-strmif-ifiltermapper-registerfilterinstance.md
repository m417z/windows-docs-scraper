# IFilterMapper::RegisterFilterInstance

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IFilterMapper** interface is deprecated. Use [IFilterMapper2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper2) instead.

Registers an identifiable instance of a filter.

## Parameters

### `clsid` [in]

GUID of the filter.

### `Name` [in]

Descriptive name of the instance.

### `MRId` [out]

Pointer to the returned media resource ID. This parameter is a locally unique identifier for this instance of this filter.

## Return value

Returns an **HRESULT** value.

## Remarks

This method handles cases such as when two similar sound cards that are driven by the same driver are available, and it is necessary to choose which card will emit the sound. This is not needed if there is only one instance of the filter (such as when there is only one sound card in the computer), or if all instances of the filter are equivalent.

The filter itself must have already been registered.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterMapper Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper)