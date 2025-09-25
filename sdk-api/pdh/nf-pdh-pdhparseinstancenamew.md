# PdhParseInstanceNameW function

## Description

Parses the elements of an instance string.

## Parameters

### `szInstanceString` [in]

**Null**-terminated string that specifies the instance string to parse into individual components. This string can contain the following formats, and is less than MAX_PATH characters in length:

* instance
* instance#index
* parent/instance
* parent/instance#index

### `szInstanceName` [out]

Caller-allocated buffer that receives the **null**-terminated instance name. Set to **NULL** if *pcchInstanceNameLength* is zero.

### `pcchInstanceNameLength` [in, out]

Size of the *szInstanceName* buffer, in **TCHARs**. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

### `szParentName` [out]

Caller-allocated buffer that receives the **null**-terminated name of the parent instance, if one is specified. Set to **NULL** if *pcchParentNameLength* is zero.

### `pcchParentNameLength` [in, out]

Size of the *szParentName* buffer, in **TCHARs**. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

### `lpIndex` [out]

Index value of the instance. If an index entry is not present in the string, then this value is zero. This parameter can be **NULL**.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |
| **PDH_MORE_DATA** | One or both of the string buffers are too small to contain the data. This return value is expected if the corresponding size buffer is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_INVALID_INSTANCE** | The instance string is incorrectly formatted, exceeds MAX_PATH characters in length, or cannot be parsed. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set the buffers to **NULL** and buffer sizes to 0), and the second time to get the data.

> [!NOTE]
> The pdh.h header defines PdhParseInstanceName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhMakeCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhmakecounterpatha)