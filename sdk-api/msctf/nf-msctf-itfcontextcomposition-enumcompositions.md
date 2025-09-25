# ITfContextComposition::EnumCompositions

## Description

Creates an enumerator object that contains all compositions in the context.

## Parameters

### `ppEnum` [out]

Pointer to an [IEnumITfCompositionView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumitfcompositionview) interface pointer that receives the enumerator object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The enumerator object could not be initialized. |
| **E_INVALIDARG** | *ppEnum* is invalid. |
| **E_OUTOFMEMORY** | The enumerator object cannot be created. |
| **TF_E_DISCONNECTED** | The context object is not on a document stack. |

## See also

[IEnumITfCompositionView interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-ienumitfcompositionview), [ITfContextComposition interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontextcomposition)