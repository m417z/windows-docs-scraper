# ITfThreadMgr::GetFunctionProvider

## Description

Obtains the specified function provider object.

## Parameters

### `clsid` [in]

CLSID of the desired function provider. This can be the CLSID of a function provider registered for the calling thread or one of the following predefined values.

| Value | Meaning |
| --- | --- |
| **GUID_SYSTEM_FUNCTIONPROVIDER** | Obtains the TSF system function provider. |
| **GUID_APP_FUNCTIONPROVIDER** | Obtains the function provider implemented by the current application. This object is not available if the application does not register itself as a function provider. |

### `ppFuncProv` [out]

Pointer to a [ITfFunctionProvider](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itffunctionprovider) interface that receives the function provider.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_NOPROVIDER** | No function provider matching *clsid* was available. |
| **E_FAIL** | GUID_SYSTEM_FUNCTIONPROVIDER was requested, but cannot be obtained. |

## Remarks

A function provider registers by calling the TSF manager [ITfSourceSingle::AdviseSingleSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfsourcesingle-advisesinglesink) method with IID_ITfFunctionProvider.

## See also

[ITfFunctionProvider](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itffunctionprovider)

[ITfSourceSingle::AdviseSingleSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfsourcesingle-advisesinglesink)

[ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr)

[ITfThreadMgr::EnumFunctionProviders](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-enumfunctionproviders)