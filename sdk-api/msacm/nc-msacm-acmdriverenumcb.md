# ACMDRIVERENUMCB callback function

## Description

The **acmDriverEnumCallback** function specifies a callback function used with the [acmDriverEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverenum) function. The **acmDriverEnumCallback** name is a placeholder for an application-defined function name.

## Parameters

### `hadid`

Handle to an ACM driver identifier.

### `dwInstance`

Application-defined value specified in [acmDriverEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverenum).

### `fdwSupport`

Driver-support flags specific to the driver specified by [ACMDRIVERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmdriverdetails) structure. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| ACMDRIVERDETAILS_SUPPORTF_ASYNC | Driver supports asynchronous conversions. |
| ACMDRIVERDETAILS_SUPPORTF_CODEC | Driver supports conversion between two different format tags. For example, if a driver supports compression from WAVE_FORMAT_PCM to WAVE_FORMAT_ADPCM, this flag is set. |
| ACMDRIVERDETAILS_SUPPORTF_CONVERTER | Driver supports conversion between two different formats of the same format tag. For example, if a driver supports resampling of WAVE_FORMAT_PCM, this flag is set. |
| ACMDRIVERDETAILS_SUPPORTF_DISABLED | Driver has been disabled. An application must specify the ACM_DRIVERENUMF_DISABLED flag with [acmDriverEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverenum) to include disabled drivers in the enumeration. |
| ACMDRIVERDETAILS_SUPPORTF_FILTER | Driver supports a filter (modification of the data without changing any of the format attributes). For example, if a driver supports volume or echo operations on WAVE_FORMAT_PCM, this flag is set. |

## Return value

The callback function must return **TRUE** to continue enumeration or **FALSE** to stop enumeration.

## Remarks

The [acmDriverEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverenum) function will return MMSYSERR_NOERROR (zero) if no ACM drivers are installed. Moreover, the callback function will not be called.

The following functions should not be called from within the callback function: [acmDriverAdd](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriveradd), [acmDriverRemove](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverremove), and [acmDriverPriority](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverpriority).

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)