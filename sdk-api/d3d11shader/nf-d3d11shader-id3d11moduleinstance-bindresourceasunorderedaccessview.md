# ID3D11ModuleInstance::BindResourceAsUnorderedAccessView

## Description

Rebinds a resource as an unordered access view (UAV) from source slot to destination slot.

## Parameters

### `uSrcSrvSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The first source slot number for rebinding.

### `uDstUavSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The first destination slot number for rebinding.

### `uCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of slots for rebinding.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns:

* **S_OK** for a valid rebinding
* **S_FALSE** for rebinding a nonexistent slot; that is, for which the shader reflection doesn’t have any data
* **E_FAIL** for an invalid rebinding, for example, the rebinding is out-of-bounds
* Possibly one of the other [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues)

## See also

[ID3D11ModuleInstance](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11moduleinstance)