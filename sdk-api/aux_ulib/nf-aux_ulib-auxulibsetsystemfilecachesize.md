# AuxUlibSetSystemFileCacheSize function

## Description

Sets the current file system cache size.

As of Windows Server 2003 with Service Pack 1 (SP1), this function has been superseded by the [SetSystemFileCacheSize](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-setsystemfilecachesize) function.

## Parameters

### `MinimumFileCacheSize` [in]

The minimum cache size, in bytes. To flush the cache, use (**DWORD**)–1.

### `MaximumFileCacheSize` [in]

The maximum cache size, in bytes. To flush the cache, use (**DWORD**)–1.

### `Flags` [in]

This parameter is reserved for future use and must be zero.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You must call the [AuxUlibInitialize](https://learn.microsoft.com/windows/desktop/api/aux_ulib/nf-aux_ulib-auxulibinitialize) function before calling this function.

The caller must have enabled the SE_INCREASE_QUOTA_NAME privilege in the active token.

## See also

[AuxUlibInitialize](https://learn.microsoft.com/windows/desktop/api/aux_ulib/nf-aux_ulib-auxulibinitialize)