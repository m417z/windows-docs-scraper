# FreeEnvironmentStringsA function

## Description

Frees a block of environment strings.

## Parameters

### `penv`

A pointer to a block of environment strings. The pointer to the block must be obtained by calling the [GetEnvironmentStrings](https://learn.microsoft.com/windows/win32/api/processenv/nf-processenv-getenvironmentstrings) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If you used the ANSI version of [GetEnvironmentStrings](https://learn.microsoft.com/windows/win32/api/processenv/nf-processenv-getenvironmentstrings) function, be sure to use the ANSI version of **FreeEnvironmentStrings**. Similarly, if you used the Unicode version of **GetEnvironmentStrings**, be sure to use the Unicode version of **FreeEnvironmentStrings**.

### Examples

For an example, see [Changing Environment Variables](https://learn.microsoft.com/windows/win32/procthread/changing-environment-variables).

> [!NOTE]
> The processenv.h header defines FreeEnvironmentStrings as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Environment Variables](https://learn.microsoft.com/windows/win32/procthread/environment-variables)