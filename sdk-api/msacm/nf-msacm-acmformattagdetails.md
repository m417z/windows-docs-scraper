# acmFormatTagDetails function

## Description

The **acmFormatTagDetails** function queries the ACM for details on a specific waveform-audio format tag.

## Parameters

### `had`

Handle to the ACM driver to query for waveform-audio format tag details. If this parameter is **NULL**, the ACM uses the details from the first suitable ACM driver. An application must specify a valid handle or driver identifier when using the ACM_FORMATTAGDETAILSF_INDEX query type. Driver identifiers for disabled drivers are not allowed.

### `paftd`

Pointer to the [ACMFORMATTAGDETAILS]() structure that is to receive the format tag details.

### `fdwDetails`

Flags for getting the details. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_FORMATTAGDETAILSF_FORMATTAG |[ACMFORMATTAGDETAILS]() structure. The format tag details will be returned in the structure pointed to by *paftd*. If an application specifies an ACM driver handle for *had*, details on the format tag will be returned for that driver. If an application specifies **NULL** for *had*, the ACM finds the first acceptable driver to return the details.
| ACM_FORMATTAGDETAILSF_INDEX |[ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails) structure for an ACM driver. An application must specify a driver handle for *had* when retrieving format tag details with this flag.
| ACM_FORMATTAGDETAILSF_LARGESTSIZE |[ACMFORMATTAGDETAILS]() structure must either be WAVE_FORMAT_UNKNOWN or the format tag to find the largest size for. If an application specifies an ACM driver handle for *had*, details on the largest format tag will be returned for that driver. If an application specifies **NULL** for *had*, the ACM finds an acceptable driver with the largest format tag requested to return the details.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_NOTPOSSIBLE** | The details requested are not available. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)