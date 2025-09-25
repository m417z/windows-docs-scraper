# IAMTimecodeGenerator::SetTCGMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetTCGMode` method sets the SMPTE timecode generator properties.

## Parameters

### `Param` [in]

Timecode generator mode. Specify one of the following modes.

| Value | Description |
| --- | --- |
| ED_TCG_FRAMERATE | Frame rate |
| ED_TCG_REFERENCE_SOURCE | Source of the count value |
| ED_TCG_SYNC_SOURCE | Source of the hardware clock reference |
| ED_TCG_TIMECODE_TYPE | SMPTE timecode format of the generator |

### `Value` [in]

Setting of the mode specified in *Param*.

If ED_TCG_FRAMERATE is specified in *Param*, this parameter is set to one of the following.

| Value | Description |
| --- | --- |
| ED_FORMAT_SMPTE_24 | 24 frames per second. |
| ED_FORMAT_SMPTE_25 | 25 frames per second. |
| ED_FORMAT_SMPTE_30 | 30 frames per second. Nondrop frame. |
| ED_FORMAT_SMPTE_30DROP | 30 frames per second. Drop frame (actually 29.97 frames per second). |

If ED_TCG_REFERENCE_SOURCE is specified in *Param*, set one of the following.

| Value | Description |
| --- | --- |
| ED_TCG_FREE | No count reference source. |
| ED_TCG_READER | Sync to reader value (jamsync). |

If ED_TCG_SYNC_SOURCE is specified in *Param*, set one of the following.

| Value | Description |
| --- | --- |
| ED_TCG_FREE | Lock to nothing (freerun). |
| ED_TCG_READER | Lock to timecode reader. |
| ED_TCG_VIDEO | Lock to incoming video. |

If ED_TCG_TIMECODE_TYPE is specified in *Param*, set one of the following.

| Value | Description |
| --- | --- |
| ED_TCG_MIDI_FULL | MIDI Full Frame timecode |
| ED_TCG_MIDI_QF | MIDI quarter frame timecode |
| ED_TCG_SMPTE_LTC | Linear timecode |
| ED_TCG_SMPTE_VITC | Vertical interval timecode |

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

For more information on ED_TCG_TIMECODE_TYPE, see the [IAMTimecodeReader::SetTCRMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodereader-settcrmode) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTimecodeGenerator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtimecodegenerator)

[IAMTimecodeGenerator::GetTCGMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodegenerator-gettcgmode)