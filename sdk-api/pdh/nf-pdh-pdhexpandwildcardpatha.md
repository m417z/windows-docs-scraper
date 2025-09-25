# PdhExpandWildCardPathA function

## Description

Examines the specified computer or log file and returns those counter paths that match the given counter path which contains wildcard characters.

To use handles to data sources, use the
[PdhExpandWildCardPathH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhexpandwildcardpathha) function.

## Parameters

### `szDataSource` [in]

**Null**-terminated string that contains the name of a log file. The function uses the performance objects and counters defined in the log file to expand the path specified in the *szWildCardPath* parameter.

If **NULL**, the function searches the computer specified in *szWildCardPath*.

### `szWildCardPath` [in]

**Null**-terminated string that specifies the counter path to expand. The maximum length of a counter path is PDH_MAX_COUNTER_PATH.

If the *szDataSource* parameter is **NULL**, the function searches the computer specified in the path for matches. If the path does not specify a computer, the function searches the local computer.

### `mszExpandedPathList` [out]

Caller-allocated buffer that receives a list of **null**-terminated counter paths that match the wildcard specification in the *szWildCardPath*. The list is terminated by two **NULL** characters. Set to **NULL** if *pcchPathListLength* is zero.

### `pcchPathListLength` [in, out]

Size of the *mszExpandedPathList* buffer, in **TCHARs**. If zero on input and the object exists, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

**Note** You must add one to the required size on Windows XP.

### `dwFlags` [in]

Flags that indicate which wildcard characters not to expand. You can specify one or more flags.

| Value | Meaning |
| --- | --- |
| **PDH_NOEXPANDCOUNTERS** | Do not expand the counter name if the path contains a wildcard character for counter name. |
| **PDH_NOEXPANDINSTANCES** | Do not expand the instance name if the path contains a wildcard character for parent instance, instance name, or instance index. |
| **PDH_REFRESHCOUNTERS** | Refresh the counter list. |

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

| Return code | Description |
| --- | --- |
| **PDH_MORE_DATA** | The *mszExpandedPathList* buffer is not large enough to contain the list of paths. This return value is expected if *pcchPathListLength* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |
| **PDH_INVALID_PATH** | The specified object does not contain an instance. |
| **PDH_MEMORY_ALLOCATION_FAILURE** | Unable to allocate memory to support this function. |
| **PDH_CSTATUS_NO_OBJECT** | Unable to find the specified object on the computer or in the log file. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set *mszExpandedPathList* to **NULL** and *pcchPathListLength* to 0), and the second time to get the data.

**PdhExpandWildCardPath** differs from
[PdhExpandCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhexpandcounterpatha) in the following ways:

1. Lets you control which wildcard characters are expanded.
2. The contents of a log file can be used as the source of counter names.

The general counter path format is as follows:

\\computer\object(parent/instance#index)\counter

The parent, instance, index, and counter components of the counter path may contain either a valid name or a wildcard character. The computer, parent, instance, and index components are not necessary for all counters.

The following is a list of the possible formats:

* \\computer\object(parent/instance#index)\counter
* \\computer\object(parent/instance)\counter
* \\computer\object(instance#index)\counter
* \\computer\object(instance)\counter
* \\computer\object\counter
* \object(parent/instance#index)\counter
* \object(parent/instance)\counter
* \object(instance#index)\counter
* \object(instance)\counter
* \object\counter

Use an asterisk (*) as the wildcard character, for example, \object(*)\counter.

If a wildcard character is specified in the parent name, all instances of the specified object that match the specified instance and counter fields will be returned. For example, \object(*/instance)\counter.

If a wildcard character is specified in the instance name, all instances of the specified object and parent object will be returned if all instance names corresponding to the specified index match the wildcard character. For example, \object(parent/*)\counter. If the object does not contain an instance, an error occurs.

If a wildcard character is specified in the counter name, all counters of the specified object are returned.

Partial counter path string matches (for example, "pro*") are supported.

**Prior to Windows Vista:** Partial wildcard matches are not supported.

> [!NOTE]
> The pdh.h header defines PdhExpandWildCardPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhEnumObjectItems](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenumobjectitemsa)

[PdhEnumObjects](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenumobjectsa)

[PdhExpandCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhexpandcounterpatha)

[PdhExpandWildCardPathH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhexpandwildcardpathha)