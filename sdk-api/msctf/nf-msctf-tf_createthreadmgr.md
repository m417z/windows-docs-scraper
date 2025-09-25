# TF_CreateThreadMgr function

## Description

The **TF_CreateThreadMgr** function creates a thread manager object without having to initialize COM. Usage of this method is not recommended, because the calling process must maintain a proper reference count on an object that is owned by Msctf.dll.

It is instead recommended that thread manager objects be created using [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) , as demonstrated in [ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr).

## Parameters

### `pptim` [out]

Pointer to an **ITfThreadMgr** interface pointer that receives the thread manager object.

## Return value

| Value | Meaning |
| --- | --- |
| S_OK | The function was successful. |
| E_FAIL | An unspecified error occurred. |
| E_INVALIDARG | *pptim* is invalid. |

## See also

[CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)