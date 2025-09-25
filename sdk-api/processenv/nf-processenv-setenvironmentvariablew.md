# SetEnvironmentVariableW function

## Description

Sets the contents of the specified environment variable for the current process.

## Parameters

### `lpName` [in]

The name of the environment variable. The operating system creates the environment variable if it does not exist and *lpValue* is not NULL.

### `lpValue` [in, optional]

The contents of the environment variable.

The maximum size of a user-defined environment variable is 32,767 characters. There is no technical limitation on the size of the environment block. However, there are practical limits depending on the mechanism used to access the block. For example, a batch file cannot set a variable that is longer than the maximum command line length. For more information, see [Environment Variables](https://learn.microsoft.com/windows/desktop/ProcThread/environment-variables).

**Windows Server 2003 and Windows XP:** The total size of the environment block for a process may not exceed 32,767 characters.

If this parameter is NULL, the variable is deleted from the current process's environment.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function has no effect on the system environment variables or the environment variables of other processes.

#### Examples

For an example, see
[Changing Environment Variables](https://learn.microsoft.com/windows/desktop/ProcThread/changing-environment-variables).

> [!NOTE]
> The processenv.h header defines SetEnvironmentVariable as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Environment Variables](https://learn.microsoft.com/windows/desktop/ProcThread/environment-variables)

[GetEnvironmentVariable](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getenvironmentvariable)