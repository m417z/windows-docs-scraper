# PdhLookupPerfIndexByNameW function

## Description

Returns the counter index corresponding to the specified counter name.

## Parameters

### `szMachineName` [in]

**Null**-terminated string that specifies the name of the computer where the specified counter is located. The computer name can be specified by the DNS name or the IP address. If **NULL**, the function uses the local computer.

### `szNameBuffer` [in]

**Null**-terminated string that contains the counter name.

### `pdwIndex` [out]

Index of the counter.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following is a possible value.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid or is incorrectly formatted. |

## See also

[PdhLookupPerfNameByIndex](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhlookupperfnamebyindexa)

## Remarks

> [!NOTE]
> The pdh.h header defines PdhLookupPerfIndexByName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).