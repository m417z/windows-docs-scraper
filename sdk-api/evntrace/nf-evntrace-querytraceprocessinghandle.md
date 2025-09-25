# QueryTraceProcessingHandle function

## Description

Retrieves information about an ETW trace processing session opened by
[OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea).

## Parameters

### `ProcessingHandle` [in]

A valid handle created with
[OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea) that the data
should be queried from.

### `InformationClass` [in]

An
[ETW_PROCESS_HANDLE_INFO_TYPE](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-etw_process_handle_info_type)
value that specifies what kind of operation will be done on the handle.

### `InBuffer` [in, optional]

Reserved for future use. May be null.

### `InBufferSize` [in]

Size in bytes of the _InBuffer_.

### `OutBuffer` [out, optional]

Buffer provided by the caller to receive output data.

### `OutBufferSize` [in]

Size in bytes of _OutBuffer._

### `ReturnLength` [out]

The size in bytes of the data that the API wrote into _OutBuffer_. Used for
variable length returns.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes).