# TF\_InvalidAssemblyListCacheIfExist function

The **TF\_InvalidAssemblyListCacheIfExist** function invalidates the text input processor's description cache. It is not necessary to call this function if the input processor setup program requires you to restart or log on. The cache is valid until the user logs off.

## Parameters

This function has no parameters.

## Return value

This function can return one of these values.

| Return code | Description |
|----------------------------------------------------------------------------------------|-------------------------------------------|
| **S\_OK** | The function was successful.<br> |
| **E\_FAIL** | An unspecified error occurred.<br> |

## Examples

There is no import library available that defines this function, so it is necessary to obtain a pointer to this function using [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). The following example demonstrates how to obtain a pointer to this function.

> [!Note]
> Using [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) incorrectly can compromise the security of your application by loading the wrong DLL. Refer to [Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order) for information on how to correctly load DLLs with different versions of Microsoft Windows.

```C++
typedef HRESULT (WINAPI *pTF_InvalidAssemblyListCacheIfExist )(void);

HMODULE hMSCTF = LoadLibrary(TEXT("msctf.dll"));

if(hMSCTF == NULL)
{
    //Error loading module -- fail as securely as possible
}

else
{
    pTF_InvalidAssemblyListCacheIfExist pfnInvalidAssemblyListCacheIfExist;

    pfnInvalidAssemblyListCacheIfExist = (pTF_InvalidAssemblyListCacheIfExist )GetProcAddress(hMSCTF, "TF_InvalidAssemblyListCacheIfExist");

    if(pfnInvalidAssemblyListCacheIfExist)
    {
        (*pfnInvalidAssemblyListCacheIfExist)();

    }

    FreeLibrary(hMSCTF);
}
```

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Redistributable<br> | TSF 1.0 on Windows 2000 Professional<br> |
| DLL<br> | Msctf.dll |

