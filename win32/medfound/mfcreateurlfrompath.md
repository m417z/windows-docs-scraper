# MFCreateURLFromPath function

\[This API is not supported and may be altered or unavailable in the future. Instead, Applications should call [UrlCreateFromPath](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlcreatefrompatha).\]

Converts a Microsoft MS-DOS path to a canonicalized URL.

## Parameters

*pwszFilePath* \[in, optional\]

A null-terminated string that contains the path. The maximum length of the string is **INTERNET\_MAX\_URL\_LENGTH**.

*ppwszFileURL* \[out\]

Receives a null-terminated string that contains the URL. The caller must free the string by calling [**CoTaskMemFree**](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
|-----------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **S\_FALSE** | The string given in the *pwszFilePath* parameter is already in URL format. In this case, *pszFilePath* is simply copied to *ppszFileURL* without modification.<br> |
| **S\_OK** | The function succeeded. <br> |

## Remarks

This function has no associated import library. To call this function, you must use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mfplat.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Mfplat.dll |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/win32/medfound/media-foundation-functions)

