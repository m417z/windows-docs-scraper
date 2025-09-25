# IDirect3DDevice9::CreateStateBlock

## Description

Creates a new state block that contains the values for all device states, vertex-related states, or pixel-related states.

## Parameters

### `Type` [in]

Type: **[D3DSTATEBLOCKTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dstateblocktype)**

Type of state data that the method should capture. This parameter can be set to a value defined in the [D3DSTATEBLOCKTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dstateblocktype) enumerated type.

### `ppSB` [out, retval]

Type: **[IDirect3DStateBlock9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dstateblock9)****

Pointer to a state block interface. See [IDirect3DStateBlock9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dstateblock9).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, D3DERR_OUTOFVIDEOMEMORY, E_OUTOFMEMORY.

## Remarks

Vertex-related device states typically refer to those states that affect how the system processes vertices. Pixel-related states generally refer to device states that affect how the system processes pixel or depth-buffer data during rasterization. Some states are contained in both groups.

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 10:<br><br>In Direct3D 9, a state block contains state data, for the states it was requested to capture, when the object is created. To change the value of the state block, call [IDirect3DStateBlock9::Capture](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dstateblock9-capture) or [IDirect3DDevice9::BeginStateBlock](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-beginstateblock)/[IDirect3DDevice9::EndStateBlock](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endstateblock). There is no state saved when a state block object is created in Direct3D 10. |

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::BeginStateBlock](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-beginstateblock)

[IDirect3DDevice9::EndStateBlock](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endstateblock)