# ACMFORMATDETAILS structure

## Description

The **ACMFORMATDETAILS** structure details a waveform-audio format for a specific format tag for an ACM driver.

## Members

### `cbStruct`

Size, in bytes, of the **ACMFORMATDETAILS** structure. This member must be initialized before an application calls the [acmFormatDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatdetails) or [acmFormatEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatenum) function. The size specified by this member must be large enough to contain the base **ACMFORMATDETAILS** structure. When the **acmFormatDetails** function returns, this member contains the actual size of the information returned. The returned information will never exceed the requested size.

### `dwFormatIndex`

Index of the format to retrieve details for. The index ranges from zero to one less than the number of standard formats supported by an ACM driver for a format tag. The number of standard formats supported by a driver for a format tag is contained in the [ACMFORMATTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformattagdetails) structure. The **dwFormatIndex** member is used only when an application queries standard format details about a driver by index; otherwise, this member should be zero. Also, this member will be set to zero by the ACM when an application queries for details on a format; in other words, this member is used only for input and is never returned by the ACM or an ACM driver.

### `dwFormatTag`

Waveform-audio format tag that the **ACMFORMATDETAILS** structure describes. This member is used for input for the ACM_FORMATDETAILSF_INDEX query flag. For the ACM_FORMATDETAILSF_FORMAT query flag, this member must be initialized to the same format tag as the **pwfx** member specifies. If a call to the [acmFormatDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatdetails) function is successful, this member is always returned. This member should be set to WAVE_FORMAT_UNKNOWN for all other query flags.

### `fdwSupport`

Driver-support flags specific to the specified format. These flags are identical to the [ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails) structure. This member can be a combination of the following values and indicates which operations the driver supports for the format tag:

| Name | Description |
| --- | --- |
| **ACMDRIVERDETAILS_SUPPORTF_ASYNC** | Driver supports asynchronous conversions with the specified format tag. |
| **ACMDRIVERDETAILS_SUPPORTF_CODEC** | Driver supports conversion between two different format tags for the specified format. For example, if a driver supports compression from WAVE_FORMAT_PCM to WAVE_FORMAT_ADPCM with the specified format, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_CONVERTER** | Driver supports conversion between two different formats of the same format tag while using the specified format. For example, if a driver supports resampling of WAVE_FORMAT_PCM to the specified format, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_FILTER** | Driver supports a filter (which modifies data without changing any format attributes) with the specified format. For example, if a driver supports volume or echo operations on WAVE_FORMAT_PCM, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_HARDWARE** | Driver supports hardware input and/or output of the specified format through a waveform-audio device. An application should use [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) with the ACM_METRIC_HARDWARE_WAVE_INPUT and ACM_METRIC_HARDWARE_WAVE_OUTPUT metric indexes to get the waveform-audio device identifiers associated with the supporting ACM driver. |

### `pwfx`

Pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that will receive the format details. This structure requires no initialization by the application unless the ACM_FORMATDETAILSF_FORMAT flag is specified in the [acmFormatDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatdetails) function. In this case, the **wFormatTag** member of the **WAVEFORMATEX** structure must be equal to the **dwFormatTag** of the **ACMFORMATDETAILS** structure.

### `cbwfx`

Size, in bytes, available for **pwfx** to receive the format details. The [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) and [acmFormatTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagdetails) functions can be used to determine the maximum size required for any format available for the specified driver (or for all installed ACM drivers).

### `szFormat`

String that describes the format for the **dwFormatTag** type. If the [acmFormatDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatdetails) function is successful, this string is always returned.

## See also

[ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails)

[ACMFORMATTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformattagdetails)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)

[Audio Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-structures)

[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85))

[acmFormatDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatdetails)

[acmFormatEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatenum)

[acmFormatTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagdetails)

[acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics)