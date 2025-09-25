# ITfThreadMgr2::EnumFunctionProviders

## Description

Obtains an enumerator for all of the function providers registered for the calling thread.

## Parameters

### `ppEnum` [out]

Address of a [IEnumTfFunctionProviders](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtffunctionproviders) interface that receives the function provider enumerator.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppEnum* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The enumerator only contains the registered function providers. The enumerator will not contain the predefined function providers as described in [GetFunctionProvider](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr2-getfunctionprovider).

A function provider registers itself by calling the TSF manager [ITfSourceSingle::AdviseSingleSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfsourcesingle-advisesinglesink) method with IID_ITfFunctionProvider.

## See also

[ITfThreadMgr2](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr2)