# TF_CreateDisplayAttributeMgr function

## Description

The **TF_CreateDisplayAttributeMgr** function is used to create a display attribute manager object without having to initialize COM. Usage of this method is not recommended, because the calling process must maintain a proper reference count on an object that is owned by Msctf.dll.

It is instead recommended that display attribute manager objects be created using [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) , as demonstrated in [ITfDisplayAttributeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdisplayattributemgr).

## Parameters

### `ppdam` [out]

Pointer to an **ITfDisplayAttributeMgr** interface pointer that receives the display attribute manager object.

## Return value

| Value | Meaning |
| --- | --- |
| S_OK | The function was successful. |
| E_FAIL | An unspecified error occurred. |
| E_INVALIDARG | *ppdam* is invalid. |

## See also

[CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[ITfDisplayAttributeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdisplayattributemgr)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)