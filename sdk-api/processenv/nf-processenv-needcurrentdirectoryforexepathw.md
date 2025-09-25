# NeedCurrentDirectoryForExePathW function

## Description

Determines whether the current directory should be included in the search path for the specified executable.

## Parameters

### `ExeName` [in]

The name of the executable file.

## Return value

If the current directory should be part of the search path, the return value is TRUE. Otherwise, the return value is FALSE.

## Remarks

This function should only be called in instances where the caller must explicitly resolve a relative executable name to an absolute name. If [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) is called with a relative executable name, it will automatically search for the executable, calling this function to determine the search path.

Most system functions perform their own path resolution, therefore, this function should only be called if you are attempting to resolve a search path for the specified executable based on the current directory.

The value of the NoDefaultCurrentDirectoryInExePath environment variable determines the value this function returns. However, you should call this function rather than checking the environment variable directly, as the registry location of this environment variable can change.

If the value of the *ExeName* parameter contains a backslash (\\), this function will always return TRUE. If it does not contain a backslash, the existence of the NoDefaultCurrentDirectoryInExePath environment variable is checked, and not its value.

An example of an instance when this function should be called instead of relying on the default search path resolution algorithm in [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) is the "cmd.exe" executable. It calls this function to determine the command search path because it does its own path resolution before calling **CreateProcess**. If this function returns TRUE, cmd.exe uses the path ".;%PATH%" for the executable search. If it returns FALSE, cmd.exe uses the path "%PATH%" for the search.

> [!NOTE]
> The processenv.h header defines NeedCurrentDirectoryForExePath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)