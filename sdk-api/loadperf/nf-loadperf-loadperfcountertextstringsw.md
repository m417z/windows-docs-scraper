# LoadPerfCounterTextStringsW function

## Description

Loads onto the computer the performance objects and counters defined in the specified initialization file.

## Parameters

### `lpCommandLine` [in]

Null-terminated string that consists of one or more arbitrary letters, a space, and then the name of the initialization (.ini) file. The name can include the path to the initialization file.

The function uses only the initialization file; the first argument is discarded. For example, to load an initialization file called "myfile.ini", the *commandLine* string could be "xx myfile.ini". The letters before the space (here "xx") are discarded, and the second part, following the space, is interpreted as the initialization file specification.

### `bQuietModeArg` [in]

Set to **TRUE** to prevent the function from displaying the output from the **Lodctr** tool; otherwise, **FALSE**. This parameter has meaning only if the application is run from a command prompt.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function provides an API to the functionality provided by the **Lodctr** tool. For information on **Lodctr**, see [Adding Counter Names and Descriptions to the Registry](https://learn.microsoft.com/windows/desktop/PerfCtrs/adding-counter-names-and-descriptions-to-the-registry).

> [!NOTE]
> The loadperf.h header defines LoadPerfCounterTextStrings as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[UnloadPerfCounterTextStrings](https://learn.microsoft.com/windows/desktop/api/loadperf/nf-loadperf-unloadperfcountertextstringsa)