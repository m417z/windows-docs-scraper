# SetupGetLineTextW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetLineText** function returns the contents of a line in an INF file in a compact form. The line to retrieve can be specified by an
[INFCONTEXT](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-infcontext) structure returned from a SetupFindLineXXX function, or by explicitly passing in the INF handle, section, and key of the desired line.

## Parameters

### `Context` [in]

Context for a line in an INF file whose text is to be retrieved. This parameter can be **NULL**. If *Context* is **NULL**, *InfHandle*, *Section*, and *Key* must all be specified.

### `InfHandle` [in]

Handle to the INF file to query. This parameter can be **NULL**. This parameter is used only if *Context* is **NULL**. If *Context* is **NULL**, *InfHandle*, *Section*, and *Key* must all be specified.

### `Section` [in]

Pointer to a **null**-terminated string that specifies the section that contains the key name of the line whose text is to be retrieved. This parameter can be **NULL**. This parameter is used only if *Context* is **NULL**. If *Context* is **NULL**, *InfHandle*, *Section*, and *Key* must be specified.

### `Key` [in]

Pointer to a **null**-terminated string that contains the key name whose associated string is to be retrieved. This parameter can be **NULL**. This parameter is used only if *Context* is **NULL**. If *Context* is **NULL**, *InfHandle*, *Section*, and *Key* must be specified.

### `ReturnBuffer` [in, out]

If not **NULL**, *ReturnBuffer* points to a buffer in which this function returns the contents of the line. The **null**-terminated string must not exceed the size of the destination buffer. You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. Using this technique, you can avoid errors due to an insufficient buffer size. See the Remarks section. This parameter can be **NULL**.

### `ReturnBufferSize` [in]

Size of the buffer pointed to by the *ReturnBuffer* parameter, in characters. This includes the **null** terminator.

### `RequiredSize` [in, out]

If not **NULL**, points to a variable in which this function returns the required size for the buffer pointed to by the *ReturnBuffer* parameter, in characters. This includes the **null** terminator. If *ReturnBuffer* is specified and the size required is larger than the value specified in the *ReturnBufferSize* parameter, the function fails and does not store data in the buffer.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called with a *ReturnBuffer* of **NULL** and a *ReturnBufferSize* of zero, the function puts the buffer size required to hold the specified data into the variable pointed to by *RequiredSize*. If the function succeeds in this, the return value is a nonzero value. Otherwise, the return value is zero and extended error information can be obtained by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

This function returns the contents of a line in a compact format. All extraneous white space is removed and multi-line values are converted into a single contiguous string. For example, this line:

``` syntax
HKLM, , PointerClass0, 1 \
; This is a comment
01, 02, 03
```

would be returned as:

``` syntax
HKLM,,PointerClass0,1,01,02,03
```

> [!NOTE]
> The setupapi.h header defines SetupGetLineText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupFindFirstLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindfirstlinea)

[SetupFindNextLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindnextline)

[SetupFindNextMatchLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindnextmatchlinea)

[SetupGetLineByIndex](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetlinebyindexa)