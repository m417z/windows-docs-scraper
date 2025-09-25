# IEnumTfLatticeElements::Clone

## Description

Creates a copy of the enumerator object.

## Parameters

### `ppEnum` [out]

Pointer to an [IEnumTfLatticeElements](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-ienumtflatticeelements) interface pointer that receives the new enumerator.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_NOTIMPL** | The method is not implemented. |

## See also

[IEnumTfLatticeElements](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-ienumtflatticeelements)