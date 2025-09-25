# ACMFORMATTAGENUMCB callback function

## Description

The **acmFormatTagEnumCallback** function specifies a callback function used with the [acmFormatTagEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagenum) function. The **acmFormatTagEnumCallback** name is a placeholder for an application-defined function name.

## Parameters

### `hadid`

Handle to the ACM driver identifier.

### `paftd`

Pointer to an [ACMFORMATTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformattagdetails) structure that contains the enumerated format tag details.

### `dwInstance`

Application-defined value specified in the [acmFormatTagEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagenum) function.

### `fdwSupport`

Driver-support flags specific to the format tag. These flags are identical to the [ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails) structure. This parameter can be a combination of the following values and indicates which operations the driver supports with the format tag.

| Value | Meaning |
| --- | --- |
| ACMDRIVERDETAILS_SUPPORTF_ASYNC | Driver supports asynchronous conversions with the specified filter tag. |
| ACMDRIVERDETAILS_SUPPORTF_CODEC | Driver supports conversion between two different format tags where one of the tags is the specified format tag. For example, if a driver supports compression from WAVE_FORMAT_PCM to WAVE_FORMAT_ADPCM, this flag is set. |
| ACMDRIVERDETAILS_SUPPORTF_CONVERTER | Driver supports conversion between two different formats of the specified format tag. For example, if a driver supports resampling of WAVE_FORMAT_PCM, this flag is set. |
| ACMDRIVERDETAILS_SUPPORTF_FILTER | Driver supports a filter (modification of the data without changing any of the format attributes). For example, if a driver supports volume or echo operations on the specified format tag, this flag is set. |
| ACMDRIVERDETAILS_SUPPORTF_HARDWARE | Driver supports hardware input, output, or both of the specified format tag through a waveform-audio device. An application should use [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) with the ACM_METRIC_HARDWARE_WAVE_INPUT and ACM_METRIC_HARDWARE_WAVE_OUTPUT metric indexes to get the waveform-audio device identifiers associated with the supporting ACM driver. |

## Return value

The callback function must return **TRUE** to continue enumeration or **FALSE** to stop enumeration.

## Remarks

The [acmFormatTagEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagenum) function will return MMSYSERR_NOERROR (zero) if no format tags are to be enumerated. Moreover, the callback function will not be called.

The following functions should not be called from within the callback function: [acmDriverAdd](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriveradd), [acmDriverRemove](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverremove), and [acmDriverPriority](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverpriority).

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)