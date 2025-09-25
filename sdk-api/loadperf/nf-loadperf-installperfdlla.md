# InstallPerfDllA function

## Description

Installs performance counter strings, as defined in an input .ini file, into the system registry.

**Note** Microsoft recommends that developers use [LoadPerfCounterTextStrings](https://learn.microsoft.com/windows/desktop/api/loadperf/nf-loadperf-loadperfcountertextstringsa) instead of **InstallPerfDll**. **LoadPerfCounterTextStrings** calls **InstallPerfDll** internally.

## Parameters

### `szComputerName` [in]

The name of the system. This should be **NULL** because this function cannot be used to install remotely.

### `lpIniFile` [in]

The name of the initialization file that contains definitions to add to the registry.

### `dwFlags` [in]

This parameter can be **LOADPERF_FLAGS_DISPLAY_USER_MSGS** (`(ULONG_PTR) 8`).

## Return value

If the function is successful, it returns **TRUE** and posts additional information in an application event log. Otherwise, it returns an error code that represents the condition that caused the failure.

## Remarks

This function has no associated import library; you must call it using the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

> [!NOTE]
> The loadperf.h header defines InstallPerfDll as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LoadPerfCounterTextStrings](https://learn.microsoft.com/windows/desktop/api/loadperf/nf-loadperf-loadperfcountertextstringsa)