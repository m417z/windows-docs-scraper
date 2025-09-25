# IEnumDMO::Skip

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Skip` method skips over a specified number of items in the enumeration sequence.

## Parameters

### `cItemsToSkip`

Number of items to skip.

## Return value

Returns S_OK if the number items skipped equals *cItemsToSkip*. Otherwise, returns S_FALSE.

## See also

[IEnumDMO Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-ienumdmo)