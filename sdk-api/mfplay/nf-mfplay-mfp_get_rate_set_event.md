# MFP_GET_RATE_SET_EVENT macro

## Syntax

```cpp
MFP_RATE_SET_EVENT MFP_GET_RATE_SET_EVENT(
    MFP_EVENT_HEADER *pHdr
);
```

## Return value

Type: **[MFP_RATE_SET_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_rate_set_event)**

Returns a pointer to an **MFP_RATE_SET_EVENT** structure.

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Casts an [MFP_EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_event_header) pointer to an [MFP_RATE_SET_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_rate_set_event) pointer.

## Parameters

### `pHdr`

Pointer to an [MFP_EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_event_header) structure.

## Remarks

The **eEventType** member of the input structure must be **MFP_EVENT_TYPE_RATE_SET**. Otherwise, the macro returns **NULL**.

## See also

[Media Foundation Macros](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-macros)