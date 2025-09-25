# acmMetrics function

## Description

The **acmMetrics** function returns various metrics for the ACM or related ACM objects.

## Parameters

### `hao`

Handle to the ACM object to query for the metric specified in *uMetric*. For some queries, this parameter can be **NULL**.

### `uMetric`

Metric index to be returned in *pMetric*.

| Value | Meaning |
| --- | --- |
| ACM_METRIC_COUNT_CODECS | Returned value is the number of global ACM compressor or decompressor drivers in the system. The *hao* parameter must be **NULL** for this metric index. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_COUNT_CONVERTERS | Returned value is the number of global ACM converter drivers in the system. The *hao* parameter must be **NULL** for this metric index. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_COUNT_DISABLED | Returned value is the total number of global disabled ACM drivers (of all support types) in the system. The *hao* parameter must be **NULL** for this metric index. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. The sum of the ACM_METRIC_COUNT_DRIVERS and ACM_METRIC_COUNT_DISABLED metric indices is the total number of globally installed ACM drivers. |
| ACM_METRIC_COUNT_DRIVERS | Returned value is the total number of enabled global ACM drivers (of all support types) in the system. The *hao* parameter must be **NULL** for this metric index. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_COUNT_FILTERS | Returned value is the number of global ACM filter drivers in the system. The *hao* parameter must be **NULL** for this metric index. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_COUNT_HARDWARE | Returned value is the number of global ACM hardware drivers in the system. The *hao* parameter must be **NULL** for this metric index. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_COUNT_LOCAL_CODECS | Returned value is the number of local ACM compressor drivers, ACM decompressor drivers, or both for the calling task. The *hao* parameter must be **NULL** for this metric index. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_COUNT_LOCAL_CONVERTERS | Returned value is the number of local ACM converter drivers for the calling task. The *hao* parameter must be **NULL** for this metric index. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_COUNT_LOCAL_DISABLED | Returned value is the total number of local disabled ACM drivers, of all support types, for the calling task. The *hao* parameter must be **NULL** for this metric index. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. The sum of the ACM_METRIC_COUNT_LOCAL_DRIVERS and ACM_METRIC_COUNT_LOCAL_DISABLED metric indices is the total number of locally installed ACM drivers. |
| ACM_METRIC_COUNT_LOCAL_DRIVERS | Returned value is the total number of enabled local ACM drivers (of all support types) for the calling task. The *hao* parameter must be **NULL** for this metric index. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_COUNT_LOCAL_FILTERS | Returned value is the number of local ACM filter drivers for the calling task. The *hao* parameter must be **NULL** for this metric index. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_DRIVER_PRIORITY | Returned value is the current priority for the specified driver. The *hao* parameter must be a valid ACM driver identifier of the **HACMDRIVERID** data type. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_DRIVER_SUPPORT | Returned value is the **fdwSupport** flags for the specified driver. The *hao* parameter must be a valid ACM driver identifier of the **HACMDRIVERID** data type. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_HARDWARE_WAVE_INPUT | Returned value is the waveform-audio input device identifier associated with the specified driver. The *hao* parameter must be a valid ACM driver identifier of the **HACMDRIVERID** data type that supports the ACMDRIVERDETAILS_SUPPORTF_HARDWARE flag. If no waveform-audio input device is associated with the driver, MMSYSERR_NOTSUPPORTED is returned. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_HARDWARE_WAVE_OUTPUT | Returned value is the waveform-audio output device identifier associated with the specified driver. The *hao* parameter must be a valid ACM driver identifier of the **HACMDRIVERID** data type that supports the ACMDRIVERDETAILS_SUPPORTF_HARDWARE flag. If no waveform-audio output device is associated with the driver, MMSYSERR_NOTSUPPORTED is returned. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. |
| ACM_METRIC_MAX_SIZE_FILTER | Returned value is the size of the largest [WAVEFILTER](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-wavefilter) structure. If *hao* is **NULL**, the return value is the largest **WAVEFILTER** structure in the system. If *hao* identifies an open instance of an ACM driver of the **HACMDRIVER** data type or an ACM driver identifier of the **HACMDRIVERID** data type, the largest **WAVEFILTER** structure for that driver is returned. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. This metric is not allowed for an ACM stream handle of the **HACMSTREAM** data type. |
| ACM_METRIC_MAX_SIZE_FORMAT | Returned value is the size of the largest [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure. If *hao* is **NULL**, the return value is the largest **WAVEFORMATEX** structure in the system. If *hao* identifies an open instance of an ACM driver of the **HACMDRIVER** data type or an ACM driver identifier of the **HACMDRIVERID** data type, the largest **WAVEFORMATEX** structure for that driver is returned. The *pMetric* parameter must point to a buffer of a size equal to a **DWORD** value. This metric is not allowed for an ACM stream handle of the **HACMSTREAM** data type. |

### `pMetric`

Pointer to the buffer to receive the metric details. The exact definition depends on the *uMetric* index.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_NOTPOSSIBLE** | The index specified in *uMetric* cannot be returned for the specified *hao*. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |
| **MMSYSERR_NOTSUPPORTED** | The index specified in *uMetric* is not supported. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)