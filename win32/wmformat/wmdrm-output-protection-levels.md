# WMDRM\_OUTPUT\_PROTECTION\_LEVELS structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRM\_OUTPUT\_PROTECTION\_LEVELS** structure contains the output protections levels (OPLs) required by a license to perform various actions.

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

**wMinimumCopyProtectionLevel**

Minimum OPL required to copy the content.

## Remarks

This structure is used by the [**IWMDRMLicense::GetOutputProtectionLevels**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmlicense-getoutputprotectionlevels) method.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

