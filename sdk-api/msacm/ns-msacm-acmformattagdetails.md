# ACMFORMATTAGDETAILS structure

## Description

The **ACMFORMATTAGDETAILS** structure details a waveform-audio format tag for an ACM driver.

## Members

### `cbStruct`

Size, in bytes, of the **ACMFORMATTAGDETAILS** structure. This member must be initialized before an application calls the [acmFormatTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagdetails) or [acmFormatTagEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagenum) function. The size specified by this member must be large enough to contain the base **ACMFORMATTAGDETAILS** structure. When the **acmFormatTagDetails** function returns, this member contains the actual size of the information returned. The returned information will never exceed the requested size.

### `dwFormatTagIndex`

Index of the format tag for which details will be retrieved. The index ranges from zero to one less than the number of format tags supported by an ACM driver. The number of format tags supported by a driver is contained in the [ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails) structure. The **dwFormatTagIndex** member is used only when querying format tag details on a driver by index; otherwise, this member should be zero.

### `dwFormatTag`

Waveform-audio format tag that the **ACMFORMATTAGDETAILS** structure describes. This member is used for input for the ACM_FORMATTAGDETAILSF_FORMATTAG and ACM_FORMATTAGDETAILSF_LARGESTSIZE query flags. If the [acmFormatTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagdetails) function is successful, this member is always returned. This member should be set to WAVE_FORMAT_UNKNOWN for all other query flags.

### `cbFormatSize`

Largest total size, in bytes, of a waveform-audio format of the **dwFormatTag** type. For example, this member will be 16 for WAVE_FORMAT_PCM and 50 for WAVE_FORMAT_ADPCM.

### `fdwSupport`

Driver-support flags specific to the format tag. These flags are identical to the [ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails) structure. This member may be some combination of the following values and refer to what operations the driver supports with the format tag:

| Name | Description |
| --- | --- |
| **ACMDRIVERDETAILS_SUPPORTF_ASYNC** | Driver supports asynchronous conversions with the specified format tag. |
| **ACMDRIVERDETAILS_SUPPORTF_CODEC** | Driver supports conversion between two different format tags where one of the tags is the specified format tag. For example, if a driver supports compression from WAVE_FORMAT_PCM to WAVE_FORMAT_ADPCM, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_CONVERTER** | Driver supports conversion between two different formats of the specified format tag. For example, if a driver supports resampling of WAVE_FORMAT_PCM, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_FILTER** | Driver supports a filter (modification of the data without changing any of the format attributes). For example, if a driver supports volume or echo operations on the specified format tag, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_HARDWARE** | Driver supports hardware input, output, or both of the specified format tag through a waveform-audio device. An application should use the [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) function with the ACM_METRIC_HARDWARE_WAVE_INPUT and ACM_METRIC_HARDWARE_WAVE_OUTPUT metric indexes to get the waveform-audio device identifiers associated with the supporting ACM driver. |

### `cStandardFormats`

Number of standard formats of the **dwFormatTag** type; that is, the combination of all sample rates, bits per sample, channels, and so on. This value can specify all formats supported by the driver, but not necessarily.

### `szFormatTag`

String that describes the **dwFormatTag** type. If the [acmFormatTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagdetails) function is successful, this string is always returned.

## See also

[ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)

[Audio Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-structures)

[acmFormatTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagdetails)

[acmFormatTagEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagenum)

[acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics)