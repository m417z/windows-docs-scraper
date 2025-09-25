# ExpandEnvironmentStringsW function

## Description

Expands environment-variable strings and replaces them with the values defined for the current user.

To specify the environment block for a particular user or the system, use the [ExpandEnvironmentStringsForUser](https://learn.microsoft.com/windows/win32/api/userenv/nf-userenv-expandenvironmentstringsforuserw) function.

## Parameters

### `lpSrc` [in]

A buffer that contains one or more environment-variable strings in the form: %*variableName*%. For each such reference, the %*variableName*% portion is replaced with the current value of that environment variable.

Case is ignored when looking up the environment-variable name. If the name is not found, the %*variableName*% portion is left unexpanded.

Note that this function does not support all the features that Cmd.exe supports. For example, it does not support %*variableName*:*str1*=*str2*% or %*variableName*:~*offset*,*length*%.

### `lpDst` [out, optional]

A pointer to a buffer that receives the result of expanding the environment variable strings in the *lpSrc* buffer. Note that this buffer cannot be the same as the *lpSrc* buffer.

### `nSize` [in]

The maximum number of characters that can be stored in the buffer pointed to by the *lpDst* parameter. When using ANSI strings, the buffer size should be the string length, plus terminating null character, plus one. When using Unicode strings, the buffer size should be the string length plus the terminating null character.

## Return value

If the function succeeds, the return value is the number of **TCHARs** stored in the destination buffer, including the terminating null character. If the destination buffer is too small to hold the expanded string, the return value is the required buffer size, in characters.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Windows Server 2003 and Windows XP:** The size of the *lpSrc* and *lpDst* buffers is limited to 32K.

To replace folder names in a fully qualified path with their associated environment-variable strings, use the [PathUnExpandEnvStrings](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathunexpandenvstringsa) function.

To retrieve the list of environment variables for a process, use the [GetEnvironmentStrings](https://learn.microsoft.com/windows/win32/api/processenv/nf-processenv-getenvironmentstrings) function.

#### Examples

For an example, see
[Getting System Information](https://learn.microsoft.com/windows/desktop/SysInfo/getting-system-information).

> [!NOTE]
> The processenv.h header defines ExpandEnvironmentStrings as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Environment Variables](https://learn.microsoft.com/windows/desktop/ProcThread/environment-variables)

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)