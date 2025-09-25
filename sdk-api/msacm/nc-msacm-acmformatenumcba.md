# ACMFORMATENUMCBA callback function

## Description

The **acmFormatEnumCallback** function specifies a callback function used with the [acmFormatEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatenum) function. The **acmFormatEnumCallback** name is a placeholder for the application-defined function name.

## Parameters

### `hadid`

Handle to the ACM driver identifier.

### `pafd`

Pointer to an [ACMFORMATDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformatdetails) structure that contains the enumerated format details for a format tag.

### `dwInstance`

Application-defined value specified in the [acmFormatEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatenum) function.

### `fdwSupport`

Driver support flags specific to the driver identified by [ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails) structure, but they are specific to the format that is being enumerated. This parameter can be a combination of the following values and indicates which operations the driver supports for the format tag.

| Value | Meaning |
| --- | --- |
| ACMDRIVERDETAILS_SUPPORTF_ASYNC | Driver supports asynchronous conversions with the specified filter tag. |
| ACMDRIVERDETAILS_SUPPORTF_CODEC | Driver supports conversion between two different format tags for the specified format. For example, if a driver supports compression from WAVE_FORMAT_PCM to WAVE_FORMAT_ADPCM with the specified format, this flag is set. |
| ACMDRIVERDETAILS_SUPPORTF_CONVERTER | Driver supports conversion between two different formats of the same format tag while using the specified format. For example, if a driver supports resampling of WAVE_FORMAT_PCM to the specified format, this flag is set. |
| ACMDRIVERDETAILS_SUPPORTF_FILTER | Driver supports a filter (modification of the data without changing any of the format attributes) with the specified format. For example, if a driver supports volume or echo operations on WAVE_FORMAT_PCM, this flag is set. |
| ACMDRIVERDETAILS_SUPPORTF_HARDWARE | Driver supports hardware input, output, or both of the specified format tags through a waveform-audio device. An application should use the [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) function with the ACM_METRIC_HARDWARE_WAVE_INPUT and ACM_METRIC_HARDWARE_WAVE_OUTPUT metric indexes to get the waveform-audio device identifiers associated with the supporting ACM driver. |

## Return value

The callback function must return **TRUE** to continue enumeration or **FALSE** to stop enumeration.

## Remarks

The [acmFormatEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatenum) function will return MMSYSERR_NOERROR (zero) if no formats are to be enumerated. Moreover, the callback function will not be called.

The following functions should not be called from within the callback function: [acmDriverAdd](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriveradd), [acmDriverRemove](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverremove), and [acmDriverPriority](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverpriority).

> [!NOTE]
> The msacm.h header defines ACMFORMATENUMCB as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)