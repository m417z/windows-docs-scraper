# pSetupInstallCatalog function

\[This function is no longer supported by Microsoft. Developers should use **CryptCATAdminAddCatalog**.\]

Installs a catalog file.

## Parameters

*CatalogFullPath* \[in\]

The fully qualified path of the catalog to be installed on the system.

*NewBaseName* \[in\]

The new base name to use when the catalog file is copied into the catalog store.

*NewCatalogFullPath* \[out, optional\]

Optionally receives the fully qualified path of the catalog file within the catalog store. This buffer should be at least **MAX\_PATH** bytes (ANSI version) or chars (Unicode version).

## Return value

If the function succeeds, it returns **NO\_ERROR**; otherwise, it returns a Win32 error code that indicates the cause of the failure.

## Remarks

The file is copied by the system into a special directory and is optionally renamed.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Setupapi.dll |

## See also

[**CryptCATAdminAddCatalog**](https://learn.microsoft.com/windows/win32/api/mscat/nf-mscat-cryptcatadminaddcatalog)

