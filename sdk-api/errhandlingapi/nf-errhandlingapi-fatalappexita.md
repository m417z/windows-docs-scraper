# FatalAppExitA function

## Description

Displays a message box and terminates the application when the message box is closed. If the system is running with a debug version of Kernel32.dll, the message box gives the user the opportunity to terminate the application or to cancel the message box and return to the application that called
**FatalAppExit**.

## Parameters

### `uAction` [in]

This parameter must be zero.

### `lpMessageText` [in]

The null-terminated string that is displayed in the message box.

## Remarks

An application calls
**FatalAppExit** only when it is not capable of terminating any other way.

> [!NOTE]
> The errhandlingapi.h header defines FatalAppExit as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Error Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/error-handling-functions)

[FatalExit](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-fatalexit)