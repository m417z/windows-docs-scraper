# IDvdInfo2::GetAllSPRMs

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAllSPRMs** method retrieves the current contents of all system parameter registers (SPRMs).

## Parameters

### `pRegisterArray` [out]

Pointer to an array of type [SPRMARRAY](https://learn.microsoft.com/windows/desktop/DirectShow/sprmarray) that receives the address of an array of SPRMs.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | Invalid argument. |

## Remarks

The 24 SPRMs are used to hold information on current language, subpicture, and other navigation data.

**Note** A player application does not need to access these read-only registers for any standard navigation functionality. To use these registers effectively, you will probably need a more detailed knowledge of the DVD navigation commands than is provided in this documentation. The following table lists the contents of each register. Bits within the word are referred to as b0 (low order bit) through b15 (high order bit).

| Register | Contents |
| --- | --- |
| 0 | ISO-639 language code (two lowercase ASCII letters). Default value is undefined. |
| 1 | Low 4 bits (b0-b3) contain audio stream number (0 to 7) or 15 (none). Default value is 15. |
| 2 | Low 6 bits (b0-b5) contain subpicture stream number (0 to 31) or 62 (none) or 63 (dummy stream for forced subpicture). 7th bit (b6) contains subpicture display flag (0 = don't display subpicture). Default value is 62. |
| 3 | Low 4 bits (b0-b3) contain angle number (1 to 9). Default value is 1. |
| 4 | Low 7 bits (b0-b6) contain title number (1 to 99). Default value is 1. |
| 5 | Low 7 bits (b0-b6) contain title number within current VTS (1 to 99). Default value is 1. |
| 6 | Low 15 bits (b0-b14) contain PGC number in current title (1 to 32767). Default value is undefined. |
| 7 | Low 10 bits (b0-b9) contain chapter number (1 to 99). Default value is 1. Value undefined unless title is one_sequential_PGC_title. |
| 8 | High 6 bits (b10-b15) contain button number (1 to 36). Default value is 1024 (button 1). |
| 9 | Timer count, in seconds (0 to 65535). Default value is 0. |
| 10 | Low 15 bits (b0-b14) contain PGC number in current title (1 to 32767). Default value is undefined. |
| 11 | Six flags (b2: mix ch2 to ch1, b3: mix ch3 to ch1, b4: mix ch4 to ch1, b10 mix ch2 to ch0, b11: mix ch3 to ch0, b12: mix ch4 to ch0). Flag value of 0 means don't mix. Default value for all flags is 0. Value undefined if not playing Karaoke stream. |
| 12 | ISO-3166 country/region code (two uppercase ASCII letters) or 65535 (not specified). Default value is undefined. |
| 13 | Low 4 bits (b0-b3) contain parental level (1 to 8) or 15 (none). Default value is undefined. |
| 14 | b8-b9 contain current video output mode (0 = normal [4:3 or 16:9], 1 = panscan, 2 = letterbox). b10-b11 contain preferred display mode (0 = 4:3, 3 = 16:9). Default value is undefined. |
| 15 | Nine flags (b2: SDDS karaoke, b3: DTS karaoke, b4: MPEG karaoke, b6: Dolby Digital karaoke, b7: PCM karaoke, b10: SDDS playback, b11: DTS playback, b12: MPEG playback, b14: Dolby Digital playback). Flag value of 0 means incapable, 1 means capable. Default value is undefined. |
| 16 | ISO-639 language code (two lowercase ASCII letters) or 65535 (not specified). Default value is 65535. |
| 17 | Language extension code (0 = not specified, 1 = normal audio, 2 = audio for visually impaired, 3 = director comments #1, 4 = director comments #2). Default value is 0. |
| 18 | ISO-639 language code (two lowercase ASCII letters) or 65535 (not specified). Default value is 65535. |
| 19 | Language extension code (0 = not specified, 1 = normal subtitles, 2 = large subtitles, 3 = subtitles for children, 5 = normal Closed Captions, 6 = large Closed Captions, 7 = Closed Captions for children, 9 = forced subtitles, 13 = director comments, 14 = large director comments, 15 = director comments for children). Default value is 0. |
| 20 | Low 8 bits (b0-b7) contain region code (1 to 8). |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)