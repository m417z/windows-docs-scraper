# TF_CreateLangBarMgr function

## Description

The **TF_CreateLangBarMgr** function creates a language bar manager object without having to initialize COM. Usage of this method is not recommended, because the calling process must maintain a proper reference count on an object that is owned by Msctf.dll.

It is instead recommended that language bar manager objects be created using [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) , as demonstrated in [ITfLangBarMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbarmgr).

## Parameters

### `pppbm` [out]

Pointer to an **ITfLangBarMgr** interface pointer that receives the language bar manager object.

## Return value

| Value | Meaning |
| --- | --- |
| S_OK | The function was successful. |
| E_FAIL | An unspecified error occurred. |
| E_INVALIDARG | *pppbm* is invalid. |

## See also

[CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[ITfLangBarMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbarmgr)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)