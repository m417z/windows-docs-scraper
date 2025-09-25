# ACMFILTERTAGDETAILS structure

## Description

The **ACMFILTERTAGDETAILS** structure details a waveform-audio filter tag for an ACM filter driver.

## Members

### `cbStruct`

Size, in bytes, of the **ACMFILTERTAGDETAILS** structure. This member must be initialized before an application calls the [acmFilterTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfiltertagdetails) or [acmFilterTagEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfiltertagenum) function. The size specified in this member must be large enough to contain the base **ACMFILTERTAGDETAILS** structure. When the **acmFilterTagDetails** function returns, this member contains the actual size of the information returned. The returned information will never exceed the requested size.

### `dwFilterTagIndex`

Index of the filter tag to retrieve details for. The index ranges from zero to one less than the number of filter tags supported by an ACM driver. The number of filter tags supported by a driver is contained in the [ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails) structure. The **dwFilterTagIndex** member is used only when querying filter tag details about a driver by index; otherwise, this member should be zero.

### `dwFilterTag`

Waveform-audio filter tag that the **ACMFILTERTAGDETAILS** structure describes. This member is used as an input for the ACM_FILTERTAGDETAILSF_FILTERTAG and ACM_FILTERTAGDETAILSF_LARGESTSIZE query flags. This member is always returned if the [acmFilterTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfiltertagdetails) function is successful. This member should be set to WAVE_FILTER_UNKNOWN for all other query flags.

### `cbFilterSize`

Largest total size, in bytes, of a waveform-audio filter of the **dwFilterTag** type. For example, this member will be 40 for WAVE_FILTER_ECHO and 36 for WAVE_FILTER_VOLUME.

### `fdwSupport`

Driver-support flags specific to the filter tag. These flags are identical to the [ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails) structure. This member can be a combination of the following values and identifies which operations the driver supports with the filter tag:

| Name | Description |
| --- | --- |
| **ACMDRIVERDETAILS_SUPPORTF_ASYNC** | Driver supports asynchronous conversions. |
| **ACMDRIVERDETAILS_SUPPORTF_CODEC** | Driver supports conversion between two different format tags while using the specified filter tag. For example, if a driver supports compression from WAVE_FORMAT_PCM to WAVE_FORMAT_ADPCM with the specified filter tag, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_CONVERTER** | Driver supports conversion between two different formats of the same format tag while using the specified filter tag. For example, if a driver supports resampling of WAVE_FORMAT_PCM with the specified filter tag, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_FILTER** | Driver supports a filter (modification of the data without changing any of the format attributes). For example, if a driver supports volume or echo operations on WAVE_FORMAT_PCM, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_HARDWARE** | Driver supports hardware input, output, or both with the specified filter tag through a waveform-audio device. An application should use the [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) function with the ACM_METRIC_HARDWARE_WAVE_INPUT and ACM_METRIC_HARDWARE_WAVE_OUTPUT metric indexes to get the waveform-audio device identifiers associated with the supporting ACM driver. |

### `cStandardFilters`

Number of standard filters of the **dwFilterTag** type (that is, the combination of all filter characteristics). This value cannot specify all filters supported by the driver.

### `szFilterTag`

String that describes the **dwFilterTag** type. This string is always returned if the [acmFilterTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfiltertagdetails) function is successful.

## See also

[ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)

[Audio Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-structures)

[acmFilterTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfiltertagdetails)

[acmFilterTagEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfiltertagenum)