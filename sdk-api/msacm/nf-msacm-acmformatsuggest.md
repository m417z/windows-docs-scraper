# acmFormatSuggest function

## Description

The **acmFormatSuggest** function queries the ACM or a specified ACM driver to suggest a destination format for the supplied source format. For example, an application can use this function to determine one or more valid PCM formats to which a compressed format can be decompressed.

## Parameters

### `had`

Handle to an open instance of a driver to query for a suggested destination format. If this parameter is **NULL**, the ACM attempts to find the best driver to suggest a destination format.

### `pwfxSrc`

Pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that identifies the source format for which a destination format will be suggested by the ACM or specified driver.

### `pwfxDst`

Pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that will receive the suggested destination format for the *pwfxSrc* format. Depending on the *fdwSuggest* parameter, some members of the structure pointed to by *pwfxDst* may require initialization.

### `cbwfxDst`

Size, in bytes, available for the destination format. The [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) and [acmFormatTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagdetails) functions can be used to determine the maximum size required for any format available for the specified driver (or for all installed ACM drivers).

### `fdwSuggest`

Flags for matching the desired destination format. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_FORMATSUGGESTF_NCHANNELS | The **nChannels** member of the structure pointed to by *pwfxDst* is valid. The ACM will query acceptable installed drivers that can suggest a destination format matching **nChannels** or fail. |
| ACM_FORMATSUGGESTF_NSAMPLESPERSEC | The **nSamplesPerSec** member of the structure pointed to by *pwfxDst* is valid. The ACM will query acceptable installed drivers that can suggest a destination format matching **nSamplesPerSec** or fail. |
| ACM_FORMATSUGGESTF_WBITSPERSAMPLE | The **wBitsPerSample** member of the structure pointed to by *pwfxDst* is valid. The ACM will query acceptable installed drivers that can suggest a destination format matching **wBitsPerSample** or fail. |
| ACM_FORMATSUGGESTF_WFORMATTAG | The **wFormatTag** member of the structure pointed to by *pwfxDst* is valid. The ACM will query acceptable installed drivers that can suggest a destination format matching **wFormatTag** or fail. |

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)