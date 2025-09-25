# EnumSystemCodePagesA function

## Description

Enumerates the code pages that are either installed on or supported by an operating system.

## Parameters

### `lpCodePageEnumProc` [in]

Pointer to an application-defined callback function. The **EnumSystemCodePages** function enumerates code pages by making repeated calls to this callback function. For more information, see [EnumCodePagesProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317809(v=vs.85)).

### `dwFlags` [in]

Flag specifying the code pages to enumerate. This parameter can have one of the following values, which are mutually exclusive.

| Value | Meaning |
| --- | --- |
| **CP_INSTALLED** | Enumerate only installed code pages. |
| **CP_SUPPORTED** | Enumerate all supported code pages. |

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_BADDB. The function could not access the data. This situation should not normally occur, and typically indicates a bad installation, a disk problem, or the like.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function enumerates the code pages by passing code page identifiers, one at a time, to the specified application-defined callback function. This process continues until all installed or supported code page identifiers have been passed to the callback function, or the callback function returns **FALSE**.

When an application is using this function to determine an appropriate code page for saving data, it should use Unicode when possible. Other code pages are not as portable as Unicode between vendors or operating systems, due to different implementations of the associated standards.

> [!NOTE]
> The winnls.h header defines EnumSystemCodePages as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumCodePagesProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317809(v=vs.85))

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)