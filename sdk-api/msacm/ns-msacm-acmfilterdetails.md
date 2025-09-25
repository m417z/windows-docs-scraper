# ACMFILTERDETAILS structure

## Description

The **ACMFILTERDETAILS** structure details a waveform-audio filter for a specific filter tag for an ACM driver.

## Members

### `cbStruct`

Size, in bytes, of the **ACMFILTERDETAILS** structure. This member must be initialized before calling the [acmFilterDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterdetails) or [acmFilterEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterenum) functions. The size specified in this member must be large enough to contain the base **ACMFILTERDETAILS** structure. When the **acmFilterDetails** function returns, this member contains the actual size of the information returned. The returned information will never exceed the requested size.

### `dwFilterIndex`

Index of the filter about which details will be retrieved. The index ranges from zero to one less than the number of standard filters supported by an ACM driver for a filter tag. The number of standard filters supported by a driver for a filter tag is contained in the [ACMFILTERTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfilterdetails) structure. The **dwFilterIndex** member is used only when querying standard filter details about a driver by index; otherwise, this member should be zero. Also, this member will be set to zero by the ACM when an application queries for details on a filter; in other words, this member is used only for input and is never returned by the ACM or an ACM driver.

### `dwFilterTag`

Waveform-audio filter tag that the **ACMFILTERDETAILS** structure describes. This member is used as an input for the ACM_FILTERDETAILSF_INDEX query flag. For the ACM_FILTERDETAILSF_FORMAT query flag, this member must be initialized to the same filter tag as the **pwfltr** member specifies. If the [acmFilterDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterdetails) function is successful, this member is always returned. This member should be set to WAVE_FILTER_UNKNOWN for all other query flags.

### `fdwSupport`

Driver-support flags specific to the specified filter. These flags are identical to the [ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails) structure, but they are specific to the filter that is being queried. This member can be a combination of the following values and identifies which operations the driver supports for the filter tag:

| Name | Description |
| --- | --- |
| **ACMDRIVERDETAILS_SUPPORTF_ASYNC** | Driver supports asynchronous conversions. |
| **ACMDRIVERDETAILS_SUPPORTF_CODEC** | Driver supports conversion between two different format tags while using the specified filter. For example, if a driver supports compression from WAVE_FORMAT_PCM to WAVE_FORMAT_ADPCM with the specified filter, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_CONVERTER** | Driver supports conversion between two different formats of the same format tag while using the specified filter. For example, if a driver supports resampling of WAVE_FORMAT_PCM with the specified filter, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_FILTER** | Driver supports a filter (modification of the data without changing any of the format attributes). For example, if a driver supports volume or echo operations on WAVE_FORMAT_PCM, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_HARDWARE** | Driver supports hardware input, output, or both with the specified filter through a waveform-audio device. An application should use the [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) function with the ACM_METRIC_HARDWARE_WAVE_INPUT and ACM_METRIC_HARDWARE_WAVE_OUTPUT metric indexes to retrieve the waveform-audio device identifiers associated with the supporting ACM driver. |

### `pwfltr`

Pointer to a [WAVEFILTER](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-wavefilter) structure that will receive the filter details. This structure requires no initialization by the application unless the ACM_FILTERDETAILSF_FILTER flag is specified with the [acmFilterDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterdetails) function. In this case, the **dwFilterTag** member of the **WAVEFILTER** structure must be equal to the **dwFilterTag** member of the **ACMFILTERDETAILS** structure.

### `cbwfltr`

Size, in bytes, available for **pwfltr** to receive the filter details. The [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) and [acmFilterTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfiltertagdetails) functions can be used to determine the maximum size required for any filter available for the specified driver (or for all installed ACM drivers).

### `szFilter`

String that describes the filter for the **dwFilterTag** type. If the [acmFilterDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterdetails) function is successful, this string is always returned.

## See also

[ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails)

[ACMFILTERTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfilterdetails)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)

[Audio Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-structures)

[WAVEFILTER](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-wavefilter)

[acmFilterDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterdetails)

[acmFilterEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterenum)

[acmFilterTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfiltertagdetails)

[acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics)