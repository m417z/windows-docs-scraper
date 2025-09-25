# acmFilterTagDetailsA function

## Description

The **acmFilterTagDetails** function queries the ACM for details about a specific waveform-audio filter tag.

## Parameters

### `had`

Handle to the ACM driver to query for waveform-audio filter tag details. If this parameter is **NULL**, the ACM uses the details from the first suitable ACM driver. An application must specify a valid **HACMDRIVER** or **HACMDRIVERID** identifier when using the ACM_FILTERTAGDETAILSF_INDEX query type. Driver identifiers for disabled drivers are not allowed.

### `paftd`

Pointer to the [ACMFILTERTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfiltertagdetails) structure that is to receive the filter tag details.

### `fdwDetails`

Flags for getting the details. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_FILTERTAGDETAILSF_FILTERTAG |[ACMFILTERTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfiltertagdetails) structure. The filter tag details will be returned in the structure pointed to by *paftd*. If an application specifies an ACM driver handle for *had*, details on the filter tag will be returned for that driver. If an application specifies **NULL** for *had*, the ACM finds the first acceptable driver to return the details.
| ACM_FILTERTAGDETAILSF_INDEX |[ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails) structure for an ACM driver. An application must specify a driver handle for *had* when retrieving filter tag details with this flag.
| ACM_FILTERTAGDETAILSF_LARGESTSIZE | Details on the filter tag with the largest filter size, in bytes, are to be returned. The **dwFilterTag** member must either be WAVE_FILTER_UNKNOWN or the filter tag to find the largest size for. If an application specifies an ACM driver handle for *had*, details on the largest filter tag will be returned for that driver. If an application specifies **NULL** for *had*, the ACM finds an acceptable driver with the largest filter tag requested to return the details. |

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

## Remarks

> [!NOTE]
> The msacm.h header defines ACMFILTERTAGDETAILS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).