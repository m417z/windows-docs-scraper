# SetupGetStringFieldW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetStringField** function retrieves a string from the specified field of a line in an INF file.

## Parameters

### `Context` [in]

Pointer to the context for a line in an INF file.

### `FieldIndex` [in]

The 1-based index of the field within the specified line from which the string should be retrieved. Use a *FieldIndex* of 0 to retrieve a string key, if present.

### `ReturnBuffer` [in, out]

Optional pointer to a buffer that receives the **null**-terminated string. You should ensure the destination buffer is the same size or larger than the source buffer. This parameter can be **NULL**. See the Remarks section.

### `ReturnBufferSize` [in]

Size of the buffer pointed to by *ReturnBuffer*, in characters. This includes the **null** terminator.

### `RequiredSize` [out]

Optional pointer to a variable that receives the required size for the buffer pointed to by the *ReturnBuffer* parameter, in characters. If *ReturnBuffer* is specified and the actual size needed is larger than the value specified by *ReturnBufferSize*, the function fails and does not store the string in the buffer. In this case, a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER. For the Unicode version of this function, the required size is in characters. This includes the **null** terminator.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called with a *ReturnBuffer* of **NULL** and a *ReturnBufferSize* of zero, the function puts the buffer size needed to hold the specified data into the variable pointed to by *RequiredSize*. If the function succeeds in this, the return value is a nonzero value. Otherwise, the return value is zero and extended error information can be obtained by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. Using this technique, you can avoid errors due to an insufficient buffer size.

Note that the maximum length of any single string specified in an INF Strings section is 512 characters, including the terminating **NULL**. If the string length is greater than 512 it will be truncated and no error will be returned. The maximum length of any concatenated string created from one or more %strkey% tokens is 4096 characters.

> [!NOTE]
> The setupapi.h header defines SetupGetStringField as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetBinaryField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetbinaryfield)

[SetupGetIntField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetintfield)

[SetupGetMultiSzField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetmultiszfielda)