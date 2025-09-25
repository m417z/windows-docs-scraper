# ITfContext::EnumProperties

## Description

Obtains a document property enumerator.

## Parameters

### `ppEnum` [out]

Pointer to an [IEnumTfProperties](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfproperties) interface pointer that receives the enumerator object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_DISCONNECTED** | The context object is not on a document stack. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_INVALIDARG** | *ppEnum* is invalid. |

## See also

[IEnumTfProperties](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfproperties)

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)