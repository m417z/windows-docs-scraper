# PdhGetDefaultPerfObjectHW function

## Description

Retrieves the name of the default object. This name can be used to set the initial object selection in the Browse Counter dialog box.

This function is identical to
the [PdhGetDefaultPerfObject](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdefaultperfobjecta) function, except that it supports the use of handles to data sources.

## Parameters

### `hDataSource` [in]

Should be **NULL**.

If you specify a log file handle, *szDefaultObjectName* will be a **null** string.

### `szMachineName` [in]

**Null**-terminated string that specifies the name of the computer used to verify the object name. If **NULL**, the local computer is used to verify the name.

### `szDefaultObjectName` [out]

Caller-allocated buffer that receives the **null**-terminated default object name. Set to **NULL** if *pcchBufferSize* is zero.

Note that PDH always returns Processor for the default object name.

### `pcchBufferSize` [in, out]

Size of the *szDefaultObjectName* buffer, in **TCHARs**. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_MORE_DATA** | The *szDefaultObjectName* buffer is too small to contain the object name. This return value is expected if *pcchBufferSize* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_INVALID_ARGUMENT** | A required parameter is not valid. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |
| **PDH_MEMORY_ALLOCATION_FAILURE** | Unable to allocate memory in order to complete the function. |
| **PDH_CSTATUS_NO_MACHINE** | The specified computer is offline or unavailable. |
| **PDH_CSTATUS_NO_COUNTERNAME** | The default object name cannot be read or found. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set *szDefaultObjectName* to **NULL** and *pcchBufferSize* to 0), and the second time to get the data.

> [!NOTE]
> The pdh.h header defines PdhGetDefaultPerfObjectH as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhBindInputDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbindinputdatasourcea)

[PdhBrowseCountersH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbrowsecountersha)

[PdhGetDefaultPerfCounterH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdefaultperfcounterha)