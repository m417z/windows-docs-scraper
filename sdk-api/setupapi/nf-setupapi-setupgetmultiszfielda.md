# SetupGetMultiSzFieldA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetMultiSzField** function retrieves multiple strings stored in a line of an INF file, from the specified field to the end of the line.

## Parameters

### `Context` [in]

Pointer to the context for a line in an INF file.

### `FieldIndex` [in]

The 1-based index of the starting field within the specified line from which the strings should be retrieved. The string list is built from each field starting at this point to the end of the line. A *FieldIndex* of zero is not valid with this function.

### `ReturnBuffer` [in, out]

Optional pointer to a character buffer that receives the strings. Each string is **null**-terminated, with an extra **null** at the end of the string list. The **null**-terminated string should not exceed the size of the destination buffer. You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. Using this technique, you can avoid errors due to an insufficient buffer size. See the Remarks section. This parameter can be **NULL**.

### `ReturnBufferSize` [in]

Size of the buffer pointed to by *ReturnBuffer*, in characters. This includes the **null** terminator.

### `RequiredSize` [in]

Optional pointer to a variable that receives the size required for the buffer pointed to by *ReturnBuffer*, in characters. This includes the **null** terminator. If the size needed is larger than the value specified by *ReturnBufferSize*, the function fails and a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called with a *ReturnBuffer* of **NULL** and a *ReturnBufferSize* of zero, the function puts the buffer size needed to hold the specified data into the variable pointed to by *RequiredSize*. If the function succeeds in this, the return value is a nonzero value. Otherwise, the return value is zero and extended error information can be obtained by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**SetupGetMultiSzField** should not be used to iterate through string values on an INF line. Instead you should use [SetupGetStringField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetstringfielda). **SetupGetMultiSzField** returns a value in the format of REG_MULTI_SZ. This is an array of **null**-terminated strings terminated by an extra **null** character. This format does not allow zero-length strings. If the list of strings contains any zero-length strings, **SetupGetMultiSzField** will return prematurely when it encounters the first blank string value.

> [!NOTE]
> The setupapi.h header defines SetupGetMultiSzField as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetBinaryField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetbinaryfield)

[SetupGetIntField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetintfield)

[SetupGetStringField](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetstringfielda)