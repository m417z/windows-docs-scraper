# GetCachedSigningLevel function (securitybaseapi.h)

## Description

Retrieves the cached signing level.

## Parameters

### `File` [in]

Handle to a file.

### `Flags` [Out]

Pointer to the flags set on the file. The following *Flags* are supported:

| Flag | Value |
|--------|--------|
| **SIGNING_LEVEL_FILE_CACHE_FLAG_NOT_VALIDATED** | `0x01` |
| **SIGNING_LEVEL_FILE_CACHE_FLAG_VALIDATE_ONLY** | `0x04` |

Using these flags together (**SIGNING_LEVEL_FILE_CACHE_FLAG_NOT_VALIDATED \| SIGNING_LEVEL_FILE_CACHE_FLAG_VALIDATE_ONLY**) indicates that the file was validated.

### `SigningLevel` [Out]

Pointer to the signing level.

### `Thumbprint` [Out, optional]

Pointer to the thumbprint.

### `ThumbprintSize` [In, Out, optional]

Pointer to the thumbprint size.

### `ThumbprintAlgorithm` [Out, optional]

Pointer to the thumbprint algorithm.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the error codes defined in WinError.h.

## Remarks

## See also

[SetCachedSigningLevel](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-setcachedsigninglevel)