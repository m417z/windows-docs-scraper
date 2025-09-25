# IDirect3DDevice9::EvictManagedResources

## Description

Evicts all managed resources, including both Direct3D and driver-managed resources.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_OUTOFVIDEOMEMORY, D3DERR_COMMAND_UNPARSED.

## Remarks

This function causes only the D3DPOOL_DEFAULT copy of resources to be evicted. The resource copy in system memory is retained. See [D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)