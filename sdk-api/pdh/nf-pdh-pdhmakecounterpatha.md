# PdhMakeCounterPathA function

## Description

Creates a full counter path using the members specified in the [PDH_COUNTER_PATH_ELEMENTS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_path_elements_a) structure.

## Parameters

### `pCounterPathElements` [in]

A
[PDH_COUNTER_PATH_ELEMENTS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_path_elements_a) structure that contains the members used to make up the path. Only the **szObjectName** and **szCounterName** members are required, the others are optional.

If the instance name member is **NULL**, the path will not contain an instance reference and the **szParentInstance** and **dwInstanceIndex** members will be ignored.

### `szFullPathBuffer` [out]

Caller-allocated buffer that receives a **null**-terminated counter path. The maximum length of a counter path is PDH_MAX_COUNTER_PATH. Set to **NULL** if *pcchBufferSize* is zero.

### `pcchBufferSize` [in, out]

Size of the *szFullPathBuffer* buffer, in **TCHARs**. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

### `dwFlags` [in]

Format of the input and output counter values. You can specify one of the following values.

| Value | Meaning |
| --- | --- |
| **PDH_PATH_WBEM_RESULT** | Converts a PDH path to the WMI class and property name format. |
| **PDH_PATH_WBEM_INPUT** | Converts the WMI class and property name to a PDH path. |
| **0** | Returns the path in the PDH format, for example, \\computer\object(parent/instance#index)\counter. |

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_MORE_DATA** | The *szFullPathBuffer* buffer is too small to contain the counter name. This return value is expected if *pcchBufferSize* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid or is incorrectly formatted. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set *szFullPathBuffer* to **NULL** and *pcchBufferSize* to 0), and the second time to get the data.

> [!NOTE]
> The pdh.h header defines PdhMakeCounterPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PDH_COUNTER_PATH_ELEMENTS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_path_elements_a)

[PdhParseCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhparsecounterpatha)