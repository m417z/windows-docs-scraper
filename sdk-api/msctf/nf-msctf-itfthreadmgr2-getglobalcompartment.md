# ITfThreadMgr2::GetGlobalCompartment

## Description

Obtains the global compartment manager object.

## Parameters

### `ppCompMgr` [out]

Pointer to a [ITfCompartmentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcompartmentmgr) interface that receives the global compartment manager.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppCompMgr* is invalid. |

## See also

[ITfThreadMgr2](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr2)