# SetCachedSigningLevel function (securitybaseapi.h)

## Description

Sets the cached signing level.

## Parameters

### `SourceFiles` [in]

Pointer to a set of source file handles.

### `SourceFileCount` [in]

The source file count.

### `Flags` [in]

The flags set for the file. The following *Flags* are supported:

| Flag | Value |
|--------|--------|
| **SIGNING_LEVEL_FILE_CACHE_FLAG_NOT_VALIDATED** | `0x01` |
| **SIGNING_LEVEL_FILE_CACHE_FLAG_VALIDATE_ONLY** | `0x04` |

Using these flags together (**SIGNING_LEVEL_FILE_CACHE_FLAG_NOT_VALIDATED \| SIGNING_LEVEL_FILE_CACHE_FLAG_VALIDATE_ONLY**) indicates that the file should be validated.

### `TargetFile` [in, optional]

The target file.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the error codes defined in WinError.h.

## Remarks

## See also

[GetCachedSigningLevel](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-getcachedsigninglevel)