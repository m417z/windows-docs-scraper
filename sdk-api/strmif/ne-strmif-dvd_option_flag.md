# DVD_OPTION_FLAG enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DVD_OPTION_FLAG** enumeration defines flags that control the behavior of the [DVD Navigator Filter](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter). To set any of these flags, call [IDvdControl2::SetOption](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-setoption).

## Constants

### `DVD_ResetOnStop:1`

Specifies whether the DVD Navigator returns to the start of the disc when the graph stops.

| Value | Description |
| --- | --- |
| **TRUE** | The DVD Navigator enters the DVD Stop domain when the filter graph stops. When playback resumes, it starts at the beginning of the disc. |
| **FALSE** | The DVD Navigator does not enter the DVD Stop domain when the filter graph stops. When the filter graph starts again, playback resumes from the point where it stopped. |

The default value is **TRUE**.

The default behavior is not always desirable, because the filter graph might be stopped unexpectedly. This can happen, for example, if the screen resolution changes, a screen saver starts, or the computer goes into suspended mode. In these situations, the user probably wants playback to restart from the same point. Typically, the application should set this flag to **FALSE** immediately before calling [IMediaControl::Run](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-run). It should set the flag to **TRUE** before calling [IMediaControl::Stop](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-stop) in response to an explicit user to command to stop playback.

### `DVD_NotifyParentalLevelChange:2`

Specifies whether the DVD Navigator notifies the application when the parental level changes on the disc.

| Value | Description |
| --- | --- |
| **TRUE** | If the DVD Navigator reaches a temporary parental management level command, it sends the application an [EC_DVD_PARENTAL_LEVEL_CHANGE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-parental-level-change) event. It blocks playback until it the application responds by calling [IDvdControl2::AcceptParentalLevelChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-acceptparentallevelchange). |
| **FALSE** | When the DVD Navigator encounters a temporary parental management level command and the current parental level is too low, the Navigator automatically rejects the command and branches to whatever path the disc specifies. The Navigator sends an [EC_DVD_PARENTAL_LEVEL_CHANGE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-parental-level-change) event indicating the required level. The application can stop playback, put up a password dialog box, and restart playback so that it can succeed on the next attempt. |

The default value **FALSE**.

### `DVD_HMSF_TimeCodeEvents:3`

Specifies the format for timecode information.

| Value | Description |
| --- | --- |
| **TRUE** |[DVD_HMSF_TIMECODE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_hmsf_timecode) structure.
| **FALSE** |[DVD_TIMECODE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_timecode) structure.

For backward compatibility, the default value is [DVD_HMSF_TIMECODE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_hmsf_timecode) format is easier to use.

### `DVD_AudioDuringFFwdRew:4`

Specifies the format for timecode information.

| Value | Description |
| --- | --- |
| **TRUE** | The DVD Navigator enables audio during fast forward and rewind, as long as the audio rate does not exceed the maximum rate of the audio decoder. |
| **FALSE** | The Navigator disables audio during fast forward and rewind. |

The default value is **FALSE**.

You can also enable audio during fast forward and rewind by creating the following key in the Windows registry:

`DWORD HKLM\Software\Microsoft\DVDNavigator\AudioDuringFFwdRev = 1`

This has the same effect as setting the DVD_AudioDuringFFwdRew flag to **TRUE**.

### `DVD_EnableNonblockingAPIs:5`

**Note** Requires Windows XP Service Pack 2 or later.

If this flag is **FALSE**, certain DVD Navigator functions block until the DVD Navigator can complete the operation. This is the default behavior.

If this flag is **TRUE**, those functions no longer block. Instead, if the DVD Navigator cannot complete the operation immediately, the function returns **VFW_E_DVD_NONBLOCKING**. If the application sets this flag to **TRUE**, it must handle the **VFW_E_DVD_NONBLOCKING** error code. Usually the correct behavior is to poll the function until the function succeeds or returns some other error code.

This flag affects at least the following methods: [IDvdControl2::ActivateAtPosition](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-activateatposition), [IDvdControl2::SelectAtPosition](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-selectatposition), [IDvdInfo2::GetCurrentLocation](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getcurrentlocation), [IDvdInfo2::GetState](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getstate). This list may be expanded in the future.

### `DVD_CacheSizeInMB:6`

**Note** Requires Windows Vista or later.

Specifies how much data the DVD Navigator reads in advance, in MB. For this flag, the *bEnable* parameter of [SetOption](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-setoption) is interpreted as a **DWORD** value, rather than a Boolean.

If the application sets this flag to a large value (> 50 MB), the DVD drive may spin down after the initial pre-fetch, depending on the hardware.

You can also set the cache size by creating the following registry key: `HKLM\Software\Microsoft\DVDNavigator\CacheSizeInMB`. This registry key is intended for diagnostic purposes only. Applications should use the **DVD_CacheSizeInMB** flag, not the registry key.

### `DVD_EnablePortableBookmarks:7`

**Note** Requires Windows Vista or later.

| Value | Description |
| --- | --- |
| **TRUE** | DVD bookmarks can be used on another computer. See [Saving and Restoring DvdState Objects](https://learn.microsoft.com/windows/desktop/DirectShow/saving-and-restoring-dvdstate-objects). |
| **FALSE** | DVD bookmarks are usable only on the computer where they were created. |

The default value is **FALSE**.

### `DVD_EnableExtendedCopyProtectErrors:8`

**Note** Requires Windows Vista or later.

If this flag **TRUE**, the DVD Navigator supports an extended set of errors related to copy protection failures. These errors are conveyed through the [EC_DVD_ERROR](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-error) event, and include the following:

* DVD_PB_STOPPED_CopyProtectOutputNotSupported
* DVD_PB_STOPPED_CopyProtectOutputFailure

(See [DVD_PB_STOPPED](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdevcod/ne-dvdevcod-dvd_pb_stopped).)

If this flag is **FALSE**, all copy protection errors are reported using the general **DVD_PB_STOPPED_CopyProtectFailure** error code.

For backward compatibility, the default value is **FALSE**.

### `DVD_NotifyPositionChange:9`

**Note** Requires Windows 7 or later.

If this flag is **TRUE**, the following events are enabled:

* [EC_DVD_PROGRAM_CELL_CHANGE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-program-cell-change)
* [EC_DVD_PROGRAM_CHAIN_CHANGE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-program-chain-change)
* [EC_DVD_TITLE_SET_CHANGE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-title-set-change)

The default value for this flag is **FALSE**.

### `DVD_IncreaseOutputControl:10`

**Note** Requires Windows 7 or later.

Bitwise **OR** of the following flags:

| Flag | Description |
| --- | --- |
| 0x01 | Enforce High-Bandwidth Digital Content Protection (HDCP) without fallback. |
| 0x02 | Enforce HDCP even for DVD discs that do not have Content Scramble System (CSS) protection. |

The default value is zero. These flags are intended for purposes. The recommended value is zero.

### `DVD_EnableStreaming:11`

**Note** Requires Windows 7 or later.

Enables or disables *streaming mode*. In streaming mode, bad blocks on the disc are skipped. The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) receives partially corrected data. This mode generally produces better results when playing scratched or damaged disks, because it results in brief video corruption, rather than long waits that block playback. The DVD drive must support streaming I/O.

The default value is **TRUE**.

### `DVD_EnableESOutput:12`

**Note** Requires Windows 7 or later.

Enables the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-dvd-navigator) to output elementary streams. For more information, see the media types listed in the topic [DVD Navigator Filter](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-dvd-navigator).

The default value is **FALSE**.

### `DVD_EnableTitleLength:13`

**Note** Requires Windows 7 or later.

| Value | Description |
| --- | --- |
| **TRUE** |[DVD_TitleAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_titleattributes) structure.
| **FALSE** | The [GetTitleAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-gettitleattributes) method returns the title mode (karaoke mode or other mode) and not the title length. |

The default value is **FALSE**.

### `DVD_DisableStillThrottle:14`

If this flag is **TRUE**, it disables a call to `Sleep(1)` that the Navigator otherwise makes when displaying stills.

For backward compatibility, the default value for this flag is **FALSE**, but the recommended value is **TRUE**.

**Note** Requires Windows 7 or later.

### `DVD_EnableLoggingEvents:15`

**Note** Requires Windows 7 or later.

If this flag is **TRUE**, the following events are enabled:

* [EC_DVD_BeginNavigationCommands](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-beginnavigationcommands)
* [EC_DVD_GPRM_Change](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-gprm-change)
* [EC_DVD_NavigationCommand](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-navigationcommand)
* [EC_DVD_SPRM_Change](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-sprm-change)
* [EC_DVD_VOBU_Offset](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-vobu-offset)
* [EC_DVD_VOBU_Timestamp](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-vobu-timestamp)

The default value for this flag is **FALSE**.

### `DVD_MaxReadBurstInKB:16`

**Note** Requires Windows 7 or later.

The maximum amount of data that the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) will read ahead in a single burst, in kilobytes. For this flag, the *bEnable* parameter of [SetOption](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-setoption) is interpreted as a **DWORD** value.

The default value is 128 KB.

### `DVD_ReadBurstPeriodInMS:17`

**Note** Requires Windows 7 or later.

How often to perform burst reads into the cache, in milliseconds. For this flag, the *bEnable* parameter of [SetOption](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-setoption) is interpreted as a **DWORD** value.

The default value is 250 milliseconds.

### `DVD_RestartDisc:18`

### `DVD_EnableCC:19`

## Remarks

The following table lists the default values for the Boolean flags.

| Flag | Default value |
| --- | --- |
| **DVD_AudioDuringFFwdRew** | **FALSE** |
| **DVD_DisableStillThrottle** | **FALSE** |
| **DVD_EnableESOutput** | **FALSE** |
| **DVD_EnableExtendedCopyProtectErrors** | **FALSE** |
| **DVD_EnableLoggingEvents** | **FALSE** |
| **DVD_EnableNonblockingAPIs** | **FALSE** |
| **DVD_EnableStreaming** | **TRUE** |
| **DVD_EnablePortableBookmarks** | **FALSE** |
| **DVD_EnableTitleLength** | **FALSE** |
| **DVD_HMSF_TimeCodeEvents** | **FALSE** |
| **DVD_NotifyParentalLevelChange** | **FALSE** |
| **DVD_NotifyPositionChange** | **FALSE** |
| **DVD_ResetOnStop** | **TRUE** |

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdControl2::SetOption](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-setoption)