# IEnumITfCompositionView::Clone

## Description

Creates a copy of the enumerator object.

## Parameters

### `ppEnum` [out]

Pointer to an [IEnumITfCompositionView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumitfcompositionview) interface pointer that receives the new enumerator.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[IEnumITfCompositionView interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-ienumitfcompositionview), [ITfCompositionView interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompositionview)