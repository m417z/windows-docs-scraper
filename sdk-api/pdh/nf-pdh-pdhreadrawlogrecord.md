# PdhReadRawLogRecord function

## Description

Reads the information in the specified binary trace log file.

## Parameters

### `hLog` [in]

Handle to the log file. The
[PdhOpenLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenloga) or [PdhBindInputDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbindinputdatasourcea) function returns this handle.

### `ftRecord` [in]

Time stamp of the record to be read. If the time stamp does not match a record in the log file, the function returns the record that has a time stamp closest to (but not greater than) the given time stamp.

### `pRawLogRecord` [out]

Caller-allocated buffer that receives a
[PDH_RAW_LOG_RECORD](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_log_record) structure; the structure contains the log file record information. Set to **NULL** if *pdwBufferLength* is zero.

### `pdwBufferLength` [in]

Size of the *pRawLogRecord* buffer, in **TCHARs**. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |
| **PDH_MORE_DATA** | The *pRawLogRecord* buffer is too small to contain the path elements. This return value is expected if *pdwBufferLength* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_MEMORY_ALLOCATION_FAILURE** | Unable to allocate memory in order to complete the function. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set *pRawLogRecord* to **NULL** and *pdwBufferLength* to 0), and the second time to get the data.

## See also

[PDH_RAW_LOG_RECORD](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_log_record)

[PdhCollectQueryData](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcollectquerydata)

[PdhFormatFromRawValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhformatfromrawvalue)