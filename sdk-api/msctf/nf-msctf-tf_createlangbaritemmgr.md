# TF_CreateLangBarItemMgr function

## Description

The **TF_CreateLangBarItemMgr** function is used to create a language bar item manager object without having to initialize COM. Usage of this method is not recommended, because the calling process must maintain a proper reference count on an object that is owned by Msctf.dll.

It is instead recommended that language bar item manager objects be created using [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) , as demonstrated in [ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr).

## Parameters

### `pplbim` [out]

Pointer to an **ITfLangBarItemMgr** interface pointer that receives the language bar item manager object.

## Return value

| Value | Meaning |
| --- | --- |
| S_OK | The function was successful. |
| E_FAIL | An unspecified error occurred. |
| E_INVALIDARG | *pplbim* is invalid. |

## See also

[CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)