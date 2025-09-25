# IMediaControl::get_RegFilterCollection

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_RegFilterCollection` method retrieves a collection of all the filters listed in the registry.

This method is intended for use by Visual Basic 6.0 applications. It was documented for Visual Basic 6.0 as the **FilgraphManager.RegFilterCollection** property. C++ applications should use the [IFilterMapper2::EnumMatchingFilters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltermapper2-enummatchingfilters) method instead.

## Parameters

### `ppUnk` [out]

Receives a pointer to the **IDispatch** interface. The caller must release the interface. You can query the returned pointer for the **IAMCollection** interface. The collection contains a list of **IRegFilterInfo** pointers.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMediaControl Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediacontrol)