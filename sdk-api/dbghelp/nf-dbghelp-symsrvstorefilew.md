# SymSrvStoreFileW function

## Description

Stores a file in the specified symbol store.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `SrvPath` [in, optional]

The symbol store.

### `File` [in]

The name of the file.

### `Flags` [in]

The flags that control the function.
This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SYMSTOREOPT_COMPRESS**<br><br>0x01 | Compress the file. |
| **SYMSTOREOPT_OVERWRITE**<br><br>0x02 | Overwrite the file if it exists. |
| **SYMSTOREOPT_PASS_IF_EXISTS**<br><br>0x40 | Do not report an error if the file already exists in the symbol store. |
| **SYMSTOREOPT_POINTER**<br><br>0x08 | Store in File.ptr. |
| **SYMSTOREOPT_RETURNINDEX**<br><br>0x04 | Return the index only. |

## Return value

If the function succeeds, the return value is a pointer to a null-terminated string that specifies the full-qualified path to the stored file.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

This function returns a pointer to a buffer that may be reused by another function. Therefore, be sure to copy the data returned to another buffer immediately.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SymSrvStoreFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)