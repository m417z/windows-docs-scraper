# IMFAudioMediaType::GetAudioFormat

## Description

[**GetAudioFormat** is no longer available for use as of Windows 7. Instead, use the media type attributes to get the properties of the audio format.]

Returns a pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that describes the audio format.

## Return value

This method returns a pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure.

## Remarks

If you need to convert the media type into a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure, call [MFCreateWaveFormatExFromMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatewaveformatexfrommfmediatype).

There are no guarantees about how long the returned pointer is valid.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Audio Media Types](https://learn.microsoft.com/windows/desktop/medfound/audio-media-types)

[IMFAudioMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfaudiomediatype)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)