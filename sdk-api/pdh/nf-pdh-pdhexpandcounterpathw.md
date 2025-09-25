# PdhExpandCounterPathW function

## Description

Examines the specified computer (or local computer if none is specified) for counters and instances of counters that match the wildcard strings in the counter path.

**Note** This function is superseded by the [PdhExpandWildCardPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhexpandwildcardpatha) function.

## Parameters

### `szWildCardPath` [in]

**Null**-terminated string that contains the counter path to expand. The function searches the computer specified in the path for matches. If the path does not specify a computer, the function searches the local computer. The maximum length of a counter path is PDH_MAX_COUNTER_PATH.

### `mszExpandedPathList` [out]

Caller-allocated buffer that receives the list of expanded counter paths that match the wildcard specification in *szWildCardPath*. Each counter path in this list is terminated by a **null** character. The list is terminated with two **NULL** characters. Set to **NULL** if *pcchPathListLength* is zero.

### `pcchPathListLength` [in, out]

Size of the *mszExpandedPathList* buffer, in **TCHARs**. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

**Note** You must add one to the required size on Windows XP.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

| Return code | Description |
| --- | --- |
| **PDH_MORE_DATA** | The *mszExpandedPathList* buffer is too small to contain the list of paths. This return value is expected if *pcchPathListLength* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |
| **PDH_MEMORY_ALLOCATION_FAILURE** | Unable to allocate memory to support this function. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set *mszExpandedPathList* to **NULL** and *pcchPathListLength* to 0), and the second time to get the data.

The general counter path format is as follows:

\\computer\object(parent/instance#index)\counter

The parent, instance, index, and counter components of the counter path may contain either a valid name or a wildcard character. The computer, parent, instance, and index components are not necessary for all counters.

The counter paths that you must use is determined by the counter itself. For example, the LogicalDisk object has an instance index, so you must provide the #index, or a wildcard. Therefore, you could use the following format:

\LogicalDisk(*/*#*)\*

In comparison, the Process object does not require an instance index. Therefore, you could use the following format:

\Process(*)\ID Process

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

If a wildcard character is specified in the parent name, all instances of the specified object that match the specified instance and counter fields will be returned.

If a wildcard character is specified in the instance name, all instances of the specified object and parent object will be returned if all instance names corresponding to the specified index match the wildcard character.

If a wildcard character is specified in the counter name, all counters of the specified object are returned.

Partial counter path string matches (for example, "pro*") are not supported.

#### Examples

The following example demonstrates how to this function.

```cpp

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <pdh.h>
#include <pdhmsg.h>

#pragma comment(lib, "pdh.lib")

CONST PWSTR WILDCARD_PATH = L"\\Processor(*)\\*";

void wmain(void)
{
    PDH_STATUS Status;
    PWSTR EndOfPaths;
    PWSTR Paths = NULL;
    DWORD BufferSize = 0;

    Status = PdhExpandCounterPath(WILDCARD_PATH, Paths, &BufferSize);

    while (Status == PDH_MORE_DATA)
    {
        Paths = (PWSTR)malloc(BufferSize * sizeof(WCHAR));
        Status = PdhExpandCounterPath(WILDCARD_PATH, Paths, &BufferSize);
    }

    if (Status != ERROR_SUCCESS)
    {
        wprintf(L"\nPdhExpandCounterPath failed with status 0x%x", Status);
        goto Cleanup;
    }

    if (Paths == NULL)
    {
        wprintf(L"\nThe counter path %s cannot be expanded.", WILDCARD_PATH);
        goto Cleanup;
    }

    EndOfPaths = Paths + BufferSize;

    // On Vista and later operating systems, the buffer is terminated with two
    // null-terminator characters; however, on earlier systems, the buffer is
    // not terminated with two null-terminator characters. This covers both cases.
    for (PWSTR p = Paths; ((p != EndOfPaths) && (*p != L'\0')); p += wcslen(p) + 1)
    {
        wprintf(L"\n%s", p);
    }

Cleanup:
    if (Paths)
    {
        free(Paths);
    }
}

```

> [!NOTE]
> The pdh.h header defines PdhExpandCounterPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhExpandWildCardPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhexpandwildcardpatha)

[PdhMakeCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhmakecounterpatha)