# PdhEnumObjectItemsHW function

## Description

Returns the specified object's counter and instance names that exist on the specified computer or in the specified log file.

This function is identical to
the [PdhEnumObjectItems](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenumobjectitemsa) function, except that it supports the use of handles to data sources.

## Parameters

### `hDataSource` [in]

Handle to a data source returned by the
[PdhBindInputDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbindinputdatasourcea) function.

### `szMachineName` [in]

**Null**-terminated string that specifies the name of the computer that contains the counter and instance names that you want to enumerate.

Include the leading slashes in the computer name, for example, \\computername.

If the *szDataSource* parameter is **NULL**, you can set *szMachineName* to **NULL** to specify the local computer.

### `szObjectName` [in]

**Null**-terminated string that specifies the name of the object whose counter and instance names you want to enumerate.

### `mszCounterList` [out]

Caller-allocated buffer that receives a list of **null**-terminated counter names provided by the specified object. The list contains unique counter names. The list is terminated by two **NULL** characters. Set to **NULL** if the *pcchCounterListLength* parameter is zero.

### `pcchCounterListLength` [in, out]

Size of the *mszCounterList* buffer, in **TCHARs**. If zero on input and the object exists, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

### `mszInstanceList` [out]

Caller-allocated buffer that receives a list of **null**-terminated instance names provided by the specified object. The list contains unique instance names. The list is terminated by two **NULL** characters. Set to **NULL** if the *pcchInstanceListLength* parameter is zero.

### `pcchInstanceListLength` [in, out]

Size of the *mszInstanceList* buffer, in **TCHARs**. If zero on input and the object exists, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

If the specified object does not support variable instances, then the returned value will be zero. If the specified object does support variable instances, but does not currently have any instances, then the value returned is 2, which is the size of an empty MULTI_SZ list string.

### `dwDetailLevel` [in]

Detail level of the performance items to return. All items that are of the specified detail level or less will be returned (the levels are listed in increasing order). This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PERF_DETAIL_NOVICE** | Novice user level of detail. |
| **PERF_DETAIL_ADVANCED** | Advanced user level of detail. |
| **PERF_DETAIL_EXPERT** | Expert user level of detail. |
| **PERF_DETAIL_WIZARD** | System designer level of detail. |

### `dwFlags` [in]

This parameter must be zero.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_MORE_DATA** | One of the buffers is too small to contain the list of names. This return value is expected if *pcchCounterListLength* or *pcchInstanceListLength* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |
| **PDH_MEMORY_ALLOCATION_FAILURE** | Unable to allocate memory to support this function. |
| **PDH_CSTATUS_NO_MACHINE** | The specified computer is offline or unavailable. |
| **PDH_CSTATUS_NO_OBJECT** | The specified object could not be found on the specified computer or in the specified log file. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set the buffers to **NULL** and the sizes to 0), and the second time to get the data.

Consecutive calls to this function will return identical lists of counters and instances, because
**PdhEnumObjectItemsH** will always query the list of performance objects defined by the last call to
[PdhEnumObjectsH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenumobjectsha) or **PdhEnumObjectItemsH**. To refresh the list of performance objects, call
**PdhEnumObjectsH** with a *bRefresh* flag value of **TRUE** before calling
**PdhEnumObjectItemsH** again.

The order of the instance and counter names is undetermined.

> [!NOTE]
> The pdh.h header defines PdhEnumObjectItemsH as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhBindInputDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbindinputdatasourcea)

[PdhEnumObjectsH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenumobjectsha)