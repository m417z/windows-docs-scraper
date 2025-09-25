# IEnumPins::Skip

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Skip` method skips over a specified number of pins.

## Parameters

### `cPins` [in]

Number of pins to skip.

## Return value

Returns one of the following **HRESULT**

| Return code | Description |
| --- | --- |
| **S_FALSE** | Skipped past the end of the sequence. |
| **S_OK** | Success. |
| **VFW_E_ENUM_OUT_OF_SYNC** | The filter's state has changed and is now inconsistent with the enumerator. |

## Remarks

If the number of pins changes, the enumerator is no longer consistent with the filter, and the method returns VFW_E_ENUM_OUT_OF_SYNC. Discard any data obtained from previous calls to the enumerator, because it might be invalid. Update the enumerator by calling the [IEnumPins::Reset](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ienumpins-reset) method. You can then call the `Skip` method safely.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IEnumPins Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ienumpins)