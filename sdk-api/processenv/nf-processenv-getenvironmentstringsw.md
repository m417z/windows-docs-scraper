# GetEnvironmentStringsW function

## Description

Retrieves the environment variables for the current process.

## Return value

If the function succeeds, the return value is a pointer to the environment block of the current process.

If the function fails, the return value is NULL.

## Remarks

The
**GetEnvironmentStrings** function returns a pointer to a block of memory that contains the environment variables of the calling process (both the system and the user environment variables). Each environment block contains the environment variables in the following format:

*Var1*=*Value1*\0\
*Var2*=*Value2*\0\
*Var3*=*Value3*\0\
...\
*VarN*=*ValueN*\0\0

The name of an environment variable cannot include an equal sign (=).

Treat this memory as read-only; do not modify it directly. To add or change an environment variable, use the
[GetEnvironmentVariable](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getenvironmentvariable) and
[SetEnvironmentVariable](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setenvironmentvariable) functions.

When the block returned by
**GetEnvironmentStrings** is no longer needed, it should be freed by calling the
[FreeEnvironmentStrings](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-freeenvironmentstringsa) function.

Note that the ANSI version of this function, **GetEnvironmentStringsA**, returns OEM characters.

#### Examples

For an example, see
[Changing Environment Variables](https://learn.microsoft.com/windows/desktop/ProcThread/changing-environment-variables).

> [!NOTE]
> The processenv.h header defines GetEnvironmentStrings as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Environment Variables](https://learn.microsoft.com/windows/desktop/ProcThread/environment-variables)

[FreeEnvironmentStrings](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-freeenvironmentstringsa)

[GetEnvironmentVariable](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getenvironmentvariable)

[SetEnvironmentVariable](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setenvironmentvariable)