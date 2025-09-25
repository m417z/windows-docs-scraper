# IFilterMapper::RegisterPin

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IFilterMapper** interface is deprecated. Use [IFilterMapper2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper2) instead.

Records the details of the pin in the registry.

## Parameters

### `Filter` [in]

GUID of the filter.

### `Name` [in]

Name of the pin. This should be unique within the filter. It has no significance other than to indicate type information. You should not use pin names longer than 99 characters, because this causes filter enumeration problems.

### `bRendered` [in]

Value specifying whether the filter renders this input. Set to **TRUE** if it does; otherwise, set to **FALSE**.

### `bOutput` [in]

Value specifying whether this is an output pin. Set to **TRUE** if it is; otherwise, set to **FALSE**.

### `bZero` [in]

Value specifying whether the filter can have zero instances of this pin. If it can, set to **TRUE**; otherwise, set to **FALSE**. For example, a decompression filter doesn't need to create a sound output pin for a movie without a sound track.

### `bMany` [in]

Value specifying whether the filter can have many instances of this pin. If it can, set to **TRUE**; otherwise, set to **FALSE**. For example, a mixer might have multiple instances of its input pin.

### `ConnectsToFilter` [in]

Reserved. Must be **NULL**. (This is intended for filters such as system-wide mixers that have connections outside the filter graph. It is not yet implemented.)

### `ConnectsToPin` [in]

Reserved. Must be **NULL**.

## Return value

Returns an **HRESULT** value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterMapper Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper)