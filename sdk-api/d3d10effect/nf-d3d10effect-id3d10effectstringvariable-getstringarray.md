# ID3D10EffectStringVariable::GetStringArray

## Description

Get an array of strings.

## Parameters

### `ppStrings` [out]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to the first string in the array.

### `Offset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The offset (in number of strings) between the start of the array and the first string to get.

### `Count` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of strings in the returned array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10EffectStringVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectstringvariable)