# REGFILTER2 structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `REGFILTER2` structure contains information for registering a filter.

## Members

### `dwVersion`

Filter registration format. If the value is 1, the union contains the first unnamed structure. If the value is 2, the union contains the second unnamed structure.

### `dwMerit`

Filter merit. Filters with higher merit are enumerated first. See [Merit](https://learn.microsoft.com/windows/desktop/DirectShow/merit).

### `cPins`

Number of pins. (Defined only if **dwVersion** is 1.)

### `rgPins`

Pointer to an array of [REGFILTERPINS](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regfilterpins) structures, of size **cPins**. (Defined only if **dwVersion** is 1.)

### `cPins2`

Number of pins. (Defined only if **dwVersion** is 2.)

### `rgPins2`

Pointer to an array of [REGFILTERPINS2](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regfilterpins2) structures, of size **cPins2**. (Defined only if **dwVersion** is 2.)

## Remarks

This structure is passed to the [IFilterMapper2::RegisterFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltermapper2-registerfilter) method.

If you need to register pin mediums or pin categories, set **dwVersion** to 2 and use the [REGFILTERPINS2](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regfilterpins2) structure.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)