# ID3D10EffectMatrixVariable::GetMatrixTranspose

## Description

Transpose and get a floating-point matrix.

## Parameters

### `pData` [out]

Type: **float***

A pointer to the first element of a transposed matrix.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Transposing a matrix will rearrange the data order from row-column order to column-row order (or vice versa).

## See also

[ID3D10EffectMatrixVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectmatrixvariable)