# IDirect3D9::GetAdapterModeCount

## Description

Returns the number of display modes available on this adapter.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number that denotes the display adapter. D3DADAPTER_DEFAULT is always the primary display adapter.

### `Format` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Identifies the format of the surface type using [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat). Use [EnumAdapterModes](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-enumadaptermodes) to see the valid formats.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This method returns the number of display modes on this adapter or zero if Adapter is greater than or equal to the number of adapters on the system.

## See also

[EnumAdapterModes](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-enumadaptermodes)

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)