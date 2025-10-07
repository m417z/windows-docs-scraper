# AMOVIESETUP\_FILTER structure

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AMOVIESETUP\_FILTER** structure contains information for registering a filter.

## Members

**clsID**

Class identifier of the filter.

**strName**

Name of the filter.

**dwMerit**

Filter merit. Used by the [**IGraphBuilder**](https://learn.microsoft.com/windows/desktop/api/Strmif/nn-strmif-igraphbuilder) interface when constructing a filter graph. For a list of merit values, see [Merit](https://learn.microsoft.com/windows/win32/directshow/merit).

**nPins**

Number of elements in the *lpPin* array. If *lpPin* is **NULL**, set this member to zero.

**lpPin**

Pointer to an array of [**AMOVIESETUP\_PIN**](https://learn.microsoft.com/windows/win32/directshow/amoviesetup-pin) structures, of size *nPins*. Each member of this array describes a pin on the filter.

## Remarks

For information about using this structure, see [How to Register DirectShow Filters](https://learn.microsoft.com/windows/win32/directshow/how-to-register-directshow-filters). Use this structure only for filters that are registered in the default filter category (CLSID\_LegacyAmFilterCategory). To register a filter in a different category, use the [**IFilterMapper2::RegisterFilter**](https://learn.microsoft.com/windows/desktop/api/Strmif/nf-strmif-ifiltermapper2-registerfilter) method, as described in [Implementing DllRegisterServer](https://learn.microsoft.com/windows/win32/directshow/implementing-dllregisterserver).

> [!Note]
> The header file combase.h is provided with the [DirectShow Base Classes](https://learn.microsoft.com/windows/win32/directshow/directshow-base-classes).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------------|
| Header<br> | Combase.h (include Streams.h) |

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/win32/directshow/directshow-structures)

