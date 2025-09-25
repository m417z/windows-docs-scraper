# GetCommandLineA function

## Description

Retrieves the command-line string for the current process.

## Return value

The return value is a pointer to the command-line string for the current process.

## Remarks

The lifetime of the returned value is managed by the system, applications should not free or modify this value.

Console processes can use the *argc* and *argv* arguments of the **main** or **wmain** functions by implementing those as the program entry point.

GUI processes can use the *lpCmdLine* argument of the [WinMain or wWinMain functions](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-winmain) by implementing those as the program entry point.

To convert the command line to an *argv* style array of strings, pass the result from GetCommandLineA to [CommandLineToArgvW](https://learn.microsoft.com/windows/win32/api/shellapi/nf-shellapi-commandlinetoargvw).

> [!NOTE]
> The name of the executable in the command line that the operating system provides to a process is not necessarily identical to that in the command line that the calling process gives to the [CreateProcessA function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessa). The operating system may prepend a fully qualified path to an executable name that is provided without a fully qualified path.

### Security Remarks

The command line returned by GetCommandLineA is a conversion of the Unicode command line to the 8-bit process code page.

For most code pages this conversion is lossy and the converted command line can differ from the Unicode command line, creating possible security issues like the following:

* The conversion may alter strings intended for use as file names. For example, if the ANSI code page is Windows-1252, the Unicode character U+0100 (Latin capital letter A with macron: Ā) converts to 0x41 (the Latin capital letter A). If a user passes a file name containing the character Ā, a program that uses GetCommandLineA will receive it with the character A and operate on the wrong file.
* The conversion may alter how the command line is parsed. For example, if the ANSI code page is Windows-1252, the Unicode character U+FF02 (Fullwidth quotation mark: ＂) converts to 0x22 (the ASCII quotation mark) and the Unicode character U+2010 (Hyphen: ‐) converts to 0x2D (the ASCII minus sign). Both of these can result in command line file arguments being misinterpreted as command line options.

To avoid this problem, use the GetCommandLineW function to receive the Unicode command line, or use an application manifest (on Windows Version 1903 or later) to [set UTF-8 as the process code page](https://learn.microsoft.com/windows/apps/design/globalizing/use-utf8-code-page).

> [!NOTE]
> The processenv.h header defines GetCommandLine as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateProcessA function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)