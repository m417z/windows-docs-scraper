# SymAddSourceStream function

## Description

Adds the stream to the specified module for use by the [Source Server](https://learn.microsoft.com/windows/desktop/Debug/source-server-and-source-indexing).

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Base` [in]

The base address of the module.

### `StreamFile` [in, optional]

A null-terminated string that contains the absolute or relative path to a file that contains the source indexing stream. Can be **NULL** if *Buffer* is not **NULL**.

### `Buffer` [in, optional]

A buffer that contains the source indexing stream. Can be **NULL** if *StreamFile* is not **NULL**.

### `Size` [in]

Size, in bytes, of the *Buffer* buffer.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SymAddSourceStream** adds a stream of data formatted for use by the [source Server](https://learn.microsoft.com/windows/desktop/Debug/source-server-and-source-indexing) to a designated module. The caller can pass the stream either as a buffer in the *Buffer* parameter or a file in the *StreamFile* parameter. If both parameters are filled, then the function uses the *Buffer* parameter. If both parameters are **NULL**, then the function returns **FALSE** and the [last-error code](https://learn.microsoft.com/windows/desktop/Debug/last-error-code) is set to **ERROR_INVALID_PARAMETER**.

It is important to note that **SymAddSourceStream** does not add the stream to any corresponding PDB in order to persist the data. This function is used by those programmatically implementing their own debuggers in scenarios in which a PDB is not available.