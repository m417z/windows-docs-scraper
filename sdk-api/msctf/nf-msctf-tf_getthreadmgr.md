# TF_GetThreadMgr function

## Description

The **TF_GetThreadMgr** function obtains a copy of a thread manager object previously created within the calling thread.

## Parameters

### `pptim` [out]

Pointer to an [ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr) interface pointer that receives the thread manager object. This receives **NULL** if no thread manager is created within the calling thread.

## Return value

| Value | Meaning |
| --- | --- |
| S_OK | The function was successful. *pptim* will be **NULL** if no thread manager is created within the calling thread. |
| E_FAIL | An unspecified error occurred. |

## Remarks

If no thread manager is created within the calling thread, this function will set *pptim* to **NULL** and return S_OK. Therefore, it is necessary to verify that the function succeeded and that *pptim* is not **NULL** before using *pptim*.

#### Examples

There is no import library available that defines this function, so it is necessary to manually obtain a pointer to this function using [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). The following code example demonstrates how to accomplish this.

The following example demonstrates a function that will attempt to obtain a copy of a previously created thread manager object. If no thread manager object exists within the calling thread, the function will create one.

**Note**

Using **LoadLibrary** incorrectly can compromise the security of your application by loading the wrong DLL. Refer to the **LoadLibrary** documentation for information on how to correctly load DLLs with different versions of Windows.

```cpp

typedef HRESULT (WINAPI *PTF_GETTHREADMGR)(ITfThreadMgr **pptim);

HRESULT GetThreadMgr(ITfThreadMgr **pptm)
{
    HRESULT hr = E_FAIL;
    HMODULE hMSCTF = LoadLibrary(TEXT("msctf.dll"));
    ITfThreadMgr *pThreadMgr = NULL;

    if(hMSCTF == NULL)
    {
        //Error loading module -- fail as securely as possible
    }

    else
    {
        PTF_GETTHREADMGR pfnGetThreadMgr;

        pfnGetThreadMgr = (PTF_GETTHREADMGR)GetProcAddress(hMSCTF, "TF_GetThreadMgr");

        if(pfnGetThreadMgr)
        {
            hr = (*pfnGetThreadMgr)(&pThreadMgr);
        }

        FreeLibrary(hMSCTF);
    }

    //If no object could be obtained, try to create one.
    if(NULL == pThreadMgr)
    {
        //CoInitialize or OleInitialize must already have been called.
        hr = CoCreateInstance(  CLSID_TF_ThreadMgr,
                                NULL,
                                CLSCTX_INPROC_SERVER,
                                IID_ITfThreadMgr,
                                (void**)&pThreadMgr);
    }

    *pptm = pThreadMgr;

    return hr;
}

```

## See also

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)