# GetCommandLineW function

## Description

Retrieves the command-line string for the current process.

## Return value

The return value is a pointer to the command-line string for the current process.

## Remarks

The lifetime of the returned value is managed by the system, applications should not free or modify this value.

Console processes can use the *argc* and *argv* arguments of the **main** or **wmain** functions by implementing those as the program entry point.
GUI processes can use the *lpCmdLine* argument of the [WinMain](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-winmain) or wWinMain functions by implementing those as the program entry point.

To convert the command line to an *argv* style array of strings, pass the result from GetCommandLineW to
[CommandLineToArgvW](https://learn.microsoft.com/windows/win32/api/shellapi/nf-shellapi-commandlinetoargvw).

**Note** The name of the executable in the command line that the operating system provides to a process is not necessarily identical to that in the command line that the calling process gives to the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function. The operating system may prepend a fully qualified path to an executable name that is provided without a fully qualified path.

> [!NOTE]
> The processenv.h header defines GetCommandLine as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)