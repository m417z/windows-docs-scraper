# InstallCatalog function

\[This function is not supported and should not be used.\]

Installs a catalog in a directory.

## Parameters

*CatalogFullPath* \[in\]

A pointer to a string that represents the full path of the catalog before installation.

*NewBaseName* \[in, optional\]

A pointer to the new base name.

*NewCatalogFullPath* \[out, optional\]

A pointer to a string that represent the full path of the catalog after installation.

## Return value

This function is not currently implemented, so it does not return an actual value.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Setupapi.dll |

