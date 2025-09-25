# REGPINTYPES structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `REGPINTYPES` structure contains media type information for registering a filter.

## Members

### `clsMajorType`

Major type GUID of the media type.

### `clsMinorType`

Sub type GUID of the media type. Can be MEDIASUBTYPE_NULL.

## Remarks

This structure is used by the [IFilterMapper2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper2) interface to identify the media types that a pin supports. The equivalent **AMOVIESETUP_MEDIATYPE** type is used in class factory templates ([CFactoryTemplate](https://learn.microsoft.com/windows/desktop/DirectShow/cfactorytemplate)).

To register a range of subtypes within the same major type, use the value MEDIASUBTYPE_NULL.

For more information, see [How to Register DirectShow Filters](https://learn.microsoft.com/windows/desktop/DirectShow/how-to-register-directshow-filters).

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[Media Types](https://learn.microsoft.com/windows/desktop/DirectShow/media-types)