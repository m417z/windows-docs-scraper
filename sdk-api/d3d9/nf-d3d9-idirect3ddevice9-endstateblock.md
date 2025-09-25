# IDirect3DDevice9::EndStateBlock

## Description

Signals Direct3D to stop recording a device-state block and retrieve a pointer to the state block interface.

## Parameters

### `ppSB` [in, retval]

Type: **[IDirect3DStateBlock9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dstateblock9)****

Pointer to a state block interface. See [IDirect3DStateBlock9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dstateblock9).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be
D3DERR_INVALIDCALL.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::BeginStateBlock](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-beginstateblock)

[IDirect3DDevice9::CreateStateBlock](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createstateblock)