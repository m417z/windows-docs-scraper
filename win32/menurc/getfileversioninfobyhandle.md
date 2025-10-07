# GetFileVersionInfoByHandle function

Retrieves version information for the file associated with the specified handle.

## Parameters

### dwFlags [in]

Controls the MUI DLLs (if any) from which the version resource is extracted. Zero or more of the following flags.

| Flag | Value | Meaning |
|------|-------|---------|
| FILE_VER_GET_LOCALISED | 0x01 | Loads the entire version resource (both strings and binary version information) from the corresponding MUI file, if available. |
| FILE_VER_GET_NEUTRAL | 0x02 | Loads the version resource strings from the corresponding MUI file, if available, and loads the binary version information (VS_FIXEDFILEINFO) from the corresponding language-neutral file, if available. |
| FILE_VER_GET_PREFETCHED | 0x04 | Indicates a preference for version.dll to attempt to preload the image outside of the loader lock to avoid contention. This flag does not change the behavior or semantics of the function. |

### hFile [in]

The handle to the file.

### lplpData [out]

When this function returns, contains a pointer to a buffer that contains the file-version information.

You can use this value in a subsequent call to the [VerQueryValue](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verqueryvaluea) function to retrieve data from the buffer.

The caller is responsible for freeing this buffer by [LocalFree](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-localfree) when it is no longer being used.

### pdwLen [out]

The size of the buffer returned in *lplpData*.

## Return value

A boolean. If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. The API is exported from version.dll.

This function should be called with `*lplpdata = NULL`. If the function returns a non-NULL value the caller is responsible for freeing it with **LocalFree**. It is possible for this function to fail but still return an allocated buffer.

## Requirements

| Requirement | Value |
|-----------------------------------|-------------------------------------------------------------------------------------------------------|
| DLL | version.dll |