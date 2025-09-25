# ID3D10EffectMatrixVariable::SetMatrixTransposeArray

## Description

Transpose and set an array of floating-point matrices.

## Parameters

### `pData` [in]

Type: **float***

A pointer to an array of matrices.

### `Offset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The offset (in number of matrices) between the start of the array and the first matrix to set.

### `Count` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of matrices in the array to set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Transposing a matrix will rearrange the data order from row-column order to column-row order (or vice versa).

## See also

[ID3D10EffectMatrixVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectmatrixvariable)