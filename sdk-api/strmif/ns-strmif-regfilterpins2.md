# REGFILTERPINS2 structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `REGFILTERPINS2` structure contains information for registering a filter through the [IFilterMapper2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper2) interface.

## Members

### `dwFlags`

Bitwise combination of zero or more [REG_PINFLAG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd377518(v=vs.85)) flags.

### `cInstances`

Number of instances of this pin.

### `nMediaTypes`

Number of media types supported by this pin.

### `lpMediaType`

Pointer to an array of [REGPINTYPES](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regpintypes) structures, of size nMediaTypes.

### `nMediums`

Number of mediums. Can be zero.

### `lpMedium`

Pointer to an array of [REGPINMEDIUM](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regpinmedium) structures, of size nMediums.

### `clsPinCategory`

Optional pin category, from the [Pin Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/pin-property-set).

## Remarks

If you use this structure, set the **dwVersion** member of the [REGFILTER2](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regfilter2) structure to 2.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)