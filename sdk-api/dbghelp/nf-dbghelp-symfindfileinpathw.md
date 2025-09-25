# SymFindFileInPathW function

## Description

Locates a symbol file or executable image.

## Parameters

### `hprocess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `SearchPath` [in, optional]

The search path. This can be multiple paths separated by semicolons. It can include both directories and symbol servers. If this parameter is **NULL**, the function uses the search path set using the
[SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath) or [SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `FileName` [in]

The name of the file. You can specify a path; however, only the file name is used.

### `id` [in, optional]

The first of three identifying parameters (see Remarks).

### `two` [in]

The second of three identifying parameters (see Remarks).

### `three` [in]

The third of three identifying parameters (see Remarks).

### `flags` [in]

The format of the *id* parameter. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SSRVOPT_DWORD**<br><br>0x0002 | The *id* parameter is a **DWORD**. |
| **SSRVOPT_DWORDPTR**<br><br>0x0004 | The *id* parameter is a pointer to a **DWORD**. |
| **SSRVOPT_GUIDPTR**<br><br>0x0008 | The *id* parameter is a pointer to a **GUID**. |

### `FoundFile` [out]

A pointer to a buffer that receives the fully qualified path to the symbol file. This buffer must be at least MAX_PATH characters.

### `callback` [in, optional]

A [SymFindFileInPathProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfindfileinpathcallback) callback function.

### `context` [in, optional]

A user-defined value or **NULL**. This value is simply passed to the callback function. This parameter is typically used by an application to pass a pointer to a data structure that provides some context for the callback function.

## Return value

If the server locates a valid symbol file, it returns **TRUE**; otherwise, it returns **FALSE** and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns a value that indicates why the symbol file was not returned.

## Remarks

The identifying parameters are filled in as follows:

* If DbgHelp is looking for a .pdb file, the *id* parameter specifies the PDB signature as found in the codeview debug directory of the original image. Parameter *two* specifies the PDB age. Parameter *three* is unused and set to zero.
* If DbgHelp is looking for any other type of image, such as an executable file or .dbg file, the *id* parameter specifies the TimeDateStamp of the original image as found in its PE header. Parameter *two* specifies the SizeOfImage field, also extracted from the PE header. Parameter *three* is unused and set to zero.

All of these values can be obtained by calling [SymSrvGetFileIndexInfo](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsrvgetfileindexinfo).

When searching a directory, this function does not verify that the symbol identifiers match by default. To ensure the matching symbol files are located, call the [SymSetOptions](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetoptions) function with SYMOPT_EXACT_SYMBOLS.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SymFindFileInPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymFindFileInPathProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfindfileinpathcallback)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)

[SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath)

[SymSrvGetFileIndexInfo](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsrvgetfileindexinfo)