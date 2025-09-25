# PdhValidatePathA function

## Description

Validates that the counter is present on the computer specified in the counter path.

## Parameters

### `szFullPathBuffer` [in]

Null-terminated string that contains the counter path to validate. The maximum length of a counter path is PDH_MAX_COUNTER_PATH.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_CSTATUS_NO_INSTANCE** | The specified instance of the performance object was not found. |
| **PDH_CSTATUS_NO_COUNTER** | The specified counter was not found in the performance object. |
| **PDH_CSTATUS_NO_OBJECT** | The specified performance object was not found on the computer. |
| **PDH_CSTATUS_NO_MACHINE** | The specified computer could not be found or connected to. |
| **PDH_CSTATUS_BAD_COUNTERNAME** | The counter path string could not be parsed. |
| **PDH_MEMORY_ALLOCATION_FAILURE** | The function is unable to allocate a required temporary buffer. |

## See also

[PdhMakeCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhmakecounterpatha)

## Remarks

> [!NOTE]
> The pdh.h header defines PdhValidatePath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).