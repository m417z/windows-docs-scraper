# ID3D10EffectVectorVariable::GetFloatVectorArray

## Description

Get an array of four-component vectors that contain floating-point data.

## Parameters

### `pData` [in]

Type: **float***

A pointer to the start of the data to set.

### `Offset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Must be set to 0; this is reserved for future use.

### `Count` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of array elements to set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10EffectVectorVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvectorvariable)