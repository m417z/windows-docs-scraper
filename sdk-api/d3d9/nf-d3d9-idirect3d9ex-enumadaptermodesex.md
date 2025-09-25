# IDirect3D9Ex::EnumAdapterModesEx

## Description

This method returns the actual display mode info based on the given mode index.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number denoting the display adapter to enumerate. D3DADAPTER_DEFAULT is always the primary display adapter. This method returns D3DERR_INVALIDCALL when this value equals or exceeds the number of display adapters in the system.

### `pFilter` [in]

Type: **const [D3DDISPLAYMODEFILTER](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodefilter)***

See [D3DDISPLAYMODEFILTER](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodefilter).

### `Mode` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Represents the display-mode index which is an unsigned integer between zero and the value returned by GetAdapterModeCount minus one.

### `pMode` [out, retval]

Type: **[D3DDISPLAYMODEEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodeex)***

A pointer to the available display mode of type [D3DDISPLAYMODEEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodeex).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

* If the device can be used on this adapter, D3D_OK is returned.
* If the Adapter equals or exceeds the number of display adapters in the system, D3DERR_INVALIDCALL is returned.

## See also

[IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex)