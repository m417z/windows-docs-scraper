# GetEnvironmentVariable function

## Description

Retrieves the contents of the specified variable from the environment block of the calling process.

## Parameters

### `lpName` [in, optional]

The name of the environment variable.

### `lpBuffer` [out, optional]

A pointer to a buffer that receives the contents of the specified environment variable as a null-terminated string. An environment variable has a maximum size limit of 32,767 characters, including the null-terminating character.

### `nSize` [in]

The size of the buffer pointed to by the *lpBuffer* parameter, including the null-terminating character, in characters.

## Return value

If the function succeeds, the return value is the number of characters stored in the buffer pointed to by *lpBuffer*, not including the terminating null character.

If *lpBuffer* is not large enough to hold the data, the return value is the buffer size, in characters, required to hold the string and its terminating null character and the contents of *lpBuffer* are undefined.

If the function fails, the return value is zero. If the specified environment variable was not found in the environment block,
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_ENVVAR_NOT_FOUND.

## Remarks

This function can retrieve either a system environment variable or a user environment variable.

#### Examples

For an example, see
[Changing Environment Variables](https://learn.microsoft.com/windows/desktop/ProcThread/changing-environment-variables).

## See also

[Environment Variables](https://learn.microsoft.com/windows/desktop/ProcThread/environment-variables)

[GetEnvironmentStrings](https://learn.microsoft.com/windows/win32/api/processenv/nf-processenv-getenvironmentstrings)

[SetEnvironmentVariable](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setenvironmentvariable)