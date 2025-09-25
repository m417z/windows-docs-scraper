# PdhGetCounterInfoW function

## Description

Retrieves information about a counter, such as data size, counter type, path, and user-supplied data values.

## Parameters

### `hCounter` [in]

Handle of the counter from which you want to retrieve information. The
[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function returns this handle.

### `bRetrieveExplainText` [in]

Determines whether explain text is retrieved. If you set this parameter to **TRUE**, the explain text for the counter is retrieved. If you set this parameter to **FALSE**, the field in the returned buffer is **NULL**.

### `pdwBufferSize` [in, out]

Size of the *lpBuffer* buffer, in bytes. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

### `lpBuffer` [out]

Caller-allocated buffer that receives a
[PDH_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_info_a) structure. The structure is variable-length, because the string data is appended to the end of the fixed-format portion of the structure. This is done so that all data is returned in a single buffer allocated by the caller. Set to **NULL** if *pdwBufferSize* is zero.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid or is incorrectly formatted. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |
| **PDH_INVALID_HANDLE** | The counter handle is not valid. |
| **PDH_MORE_DATA** | The *lpBuffer* buffer is too small to hold the counter information. This return value is expected if *pdwBufferSize* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set *lpBuffer* to **NULL** and *pdwBufferSize* to 0), and the second time to get the data.

> [!NOTE]
> The pdh.h header defines PdhGetCounterInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PDH_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_info_a)