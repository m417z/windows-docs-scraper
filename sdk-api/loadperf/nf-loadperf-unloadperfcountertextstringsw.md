# UnloadPerfCounterTextStringsW function

## Description

Unloads performance objects and counters from the computer for the specified application.

## Parameters

### `lpCommandLine` [in]

Null-terminated string that consists of one or more arbitrary letters, a space, and then the name of the application. The name of the application must match the **drivername** key value found in the initialization (.ini) file used to [load the text strings](https://learn.microsoft.com/windows/desktop/api/loadperf/nf-loadperf-loadperfcountertextstringsa).

### `bQuietModeArg` [in]

Set to **TRUE** to prevent the function from displaying the output from the **Unlodctr** tool; otherwise, **FALSE**. This parameter has meaning only if the application is run from a command prompt.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function provides an API to the functionality provided by **Unlodctr** tool. For more information, see [Removing Counter Names and Descriptions from the Registry](https://learn.microsoft.com/windows/desktop/PerfCtrs/removing-counter-names-and-descriptions-from-the-registry).

> [!NOTE]
> The loadperf.h header defines UnloadPerfCounterTextStrings as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LoadPerfCounterTextStrings](https://learn.microsoft.com/windows/desktop/api/loadperf/nf-loadperf-loadperfcountertextstringsa)