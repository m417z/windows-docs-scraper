# ID3D10EffectMatrixVariable::GetMatrixArray

## Description

Get an array of matrices.

## Parameters

### `pData` [out]

Type: **float***

A pointer to the first element of the first matrix in an array of matrices.

### `Offset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The offset (in number of matrices) between the start of the array and the first matrix returned.

### `Count` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of matrices in the returned array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10EffectMatrixVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectmatrixvariable)