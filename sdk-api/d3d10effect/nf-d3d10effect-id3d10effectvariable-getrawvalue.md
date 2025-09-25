# ID3D10EffectVariable::GetRawValue

## Description

Get data.

## Parameters

### `pData` [in]

Type: **void***

A pointer to the variable.

### `Offset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The offset (in bytes) from the beginning of the pointer to the data.

### `ByteCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bytes to get.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This method does no conversion or type checking; it is therefore a very quick way to access array items.

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)