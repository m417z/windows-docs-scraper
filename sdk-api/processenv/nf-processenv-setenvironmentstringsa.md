## Description

Sets the environment strings of the calling process (both the system and the user environment variables) for the current process.

## Parameters

### `NewEnvironment`

The environment variable string using the following format:

*Var1*=*Value1*\0\
*Var2*=*Value2*\0\
*Var3*=*Value3*\0\
...\
*VarN*=*ValueN*\0\0

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also

[Environment Variables](https://learn.microsoft.com/windows/desktop/ProcThread/environment-variables)
[GetEnvironmentStrings](https://learn.microsoft.com/windows/win32/api/processenv/nf-processenv-getenvironmentstrings)
[GetEnvironmentVariable](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getenvironmentvariable)
[SetEnvironmentVariable](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-setenvironmentvariable)