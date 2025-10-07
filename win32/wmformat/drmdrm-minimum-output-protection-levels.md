# DRM\_MINIMUM\_OUTPUT\_PROTECTION\_LEVELS structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_MINIMUM\_OUTPUT\_PROTECTION\_LEVELS** structure holds the minimum output protection levels (OPLs) for playback of various types of content. A device must support the minimum OPL for a type of data to receive that type of data from the reader.

## Members

**wCompressedDigitalVideo**

Minimum OPL required to receive compressed digital video.

**wUncompressedDigitalVideo**

Minimum OPL required to receive uncompressed digital video.

**wAnalogVideo**

Minimum OPL required to receive analog video.

**wCompressedDigitalAudio**

Minimum OPL required to receive compressed digital audio.

**wUncompressedDigitalAudio**

Minimum OPL required to receive uncompressed digital audio.

## Remarks

This structure is used as a member of the [**DRM\_PLAY\_OPL**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-play-opl) structure.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

