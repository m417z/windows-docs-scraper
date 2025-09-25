# IFilterMapper::EnumMatchingFilters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IFilterMapper** interface is deprecated. Use [IFilterMapper2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper2) instead.

Provides an enumerator that enumerates registered filters that meet specified requirements.

## Parameters

### `ppEnum` [out]

Address of a pointer to the enumerator returned.

### `dwMerit` [in]

Minimum merit value of filters to enumerate.

### `bInputNeeded`

Value indicating whether there must be at least one input pin; **TRUE** indicates at least one input pin is required.

### `clsInMaj` [in]

Input major type required. Set to GUID_NULL if you do not care.

### `clsInSub` [in]

Input subtype required. Set to GUID_NULL if you do not care.

### `bRender` [in]

Flag that specifies whether the filter must render the input; **TRUE** means that it must.

### `bOututNeeded` [in]

Value indicating whether there must be at least one output pin; **TRUE** indicates at least one output pin is required.

### `clsOutMaj` [in]

Output major type required. Set to GUID_NULL if you do not care.

### `clsOutSub` [in]

Output subtype required. Set to GUID_NULL if you do not care.

## Return value

Returns an **HRESULT** value.

## Remarks

Set the *ppEnum* parameter to be an enumerator for filters matching the requirements. For a description of merit values for the *dwMerit* parameter, see the [IFilterMapper::RegisterFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltermapper-registerfilter) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterMapper Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper)