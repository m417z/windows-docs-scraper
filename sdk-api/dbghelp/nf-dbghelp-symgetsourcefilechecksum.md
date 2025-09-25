# SymGetSourceFileChecksum function

## Description

Retrieves the specified source file checksum from the source server.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Base` [in]

The base address of the module.

### `FileSpec` [in]

The name of the source file.

### `pCheckSumType` [out]

On success, points to the checksum type.

### `pChecksum` [out]

pointer to a buffer that receives the checksum. If **NULL**, then when the call returns *pActualBytesWritten* returns the number of bytes required.

### `checksumSize` [in]

The size of the *pChecksum* buffer, in bytes.

### `pActualBytesWritten` [out]

Pointer to the actual bytes written in the buffer.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).