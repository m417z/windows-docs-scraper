# PdhParseCounterPathA function

## Description

Parses the elements of the counter path and stores the results in the [PDH_COUNTER_PATH_ELEMENTS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_path_elements_a) structure.

## Parameters

### `szFullPathBuffer` [in]

**Null**-terminated string that contains the counter path to parse. The maximum length of a counter path is PDH_MAX_COUNTER_PATH.

### `pCounterPathElements` [out]

Caller-allocated buffer that receives a
[PDH_COUNTER_PATH_ELEMENTS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_path_elements_a) structure. The structure contains pointers to the individual string elements of the path referenced by the *szFullPathBuffer* parameter. The function appends the strings to the end of the **PDH_COUNTER_PATH_ELEMENTS** structure. The allocated buffer should be large enough for the structure and the strings. Set to **NULL** if *pdwBufferSize* is zero.

### `pdwBufferSize` [in, out]

Size of the *pCounterPathElements* buffer, in bytes. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

### `dwFlags`

Reserved. Must be zero.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid. |
| **PDH_MORE_DATA** | The *pCounterPathElements* buffer is too small to contain the path elements. This return value is expected if *pdwBufferSize* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_INVALID_PATH** | The path is not formatted correctly and cannot be parsed. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |
| **PDH_MEMORY_ALLOCATION_FAILURE** | Unable to allocate memory in order to complete the function. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set *pCounterPathElements* to **NULL** and *pdwBufferSize* to 0), and the second time to get the data.

> [!NOTE]
> The pdh.h header defines PdhParseCounterPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PDH_COUNTER_PATH_ELEMENTS](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_path_elements_a)

[PdhMakeCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhmakecounterpatha)