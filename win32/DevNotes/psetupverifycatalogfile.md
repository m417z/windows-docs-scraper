# pSetupVerifyCatalogFile function

\[This function is no longer supported by Microsoft. For an INF file (device install), developers should use **SetupVerifyInfFile**. To validate a non-INF based catalog, use **WinVerifyTrust**.\]

Verifies a single catalog file using standard operating system code signing policy, such as driver signing.

## Parameters

*CatalogFullPath* \[in\]

The fully qualified path of the catalog file to be verified.

## Return value

If the function succeeds, it returns **ERROR\_SUCCESS**; otherwise, it returns the error from [**WinVerifyTrust**](https://learn.microsoft.com/windows/win32/api/wintrust/nf-wintrust-winverifytrust).

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Setupapi.dll |

## See also

[**SetupVerifyInfFile**](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupverifyinffilea)

[**WinVerifyTrust**](https://learn.microsoft.com/windows/win32/api/wintrust/nf-wintrust-winverifytrust)

