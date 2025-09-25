# ITfComposition::GetRange

## Description

Obtains a range object that contains the text covered by the composition.

## Parameters

### `ppRange` [out]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcomposition) interface pointer that receives the range object. It is possible that the range will have zero length.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *ppRange* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_UNEXPECTED** | The composition has already terminated. |

## See also

[ITfComposition interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcomposition), [ITfRange interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrange)