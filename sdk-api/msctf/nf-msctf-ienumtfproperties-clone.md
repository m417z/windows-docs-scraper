# IEnumTfProperties::Clone

## Description

Creates a copy of the enumerator object.

## Parameters

### `ppEnum` [out]

Pointer to an [IEnumTfProperties](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfproperties) interface pointer that receives the new enumerator.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_NOTIMPL** | The method is not implemented. |

## See also

[IEnumTfProperties interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-ienumtfproperties), [ITfProperty interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfproperty)