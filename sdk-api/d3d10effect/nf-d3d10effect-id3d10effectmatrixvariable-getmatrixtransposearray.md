# ID3D10EffectMatrixVariable::GetMatrixTransposeArray

## Description

Transpose and get an array of floating-point matrices.

## Parameters

### `pData` [out]

Type: **float***

A pointer to the first element of an array of transposed matrices.

### `Offset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The offset (in number of matrices) between the start of the array and the first matrix to get.

### `Count` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of matrices in the array to get.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Transposing a matrix will rearrange the data order from row-column order to column-row order (or vice versa).

## See also

[ID3D10EffectMatrixVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectmatrixvariable)