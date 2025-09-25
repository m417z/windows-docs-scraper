# IDirect3DDevice9::LightEnable

## Description

Enables or disables a set of lighting parameters within a device.

## Parameters

### `Index` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index of the set of lighting parameters that are the target of this method.

### `Enable` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value that indicates if the set of lighting parameters are being enabled or disabled. Set this parameter to **TRUE** to enable lighting with the parameters at the specified index, or **FALSE** to disable it.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

If a value for LightIndex is outside the range of the light property sets assigned within the device, the **IDirect3DDevice9::LightEnable** method creates a light source represented by a [D3DLIGHT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlight9) structure with the following properties and sets its enabled state to the value specified in bEnable.

| Member | Default |
| --- | --- |
| Type | D3DLIGHT_DIRECTIONAL |
| Diffuse | (R:1, G:1, B:1, A:0) |
| Specular | (R:0, G:0, B:0, A:0) |
| Ambient | (R:0, G:0, B:0, A:0) |
| Position | (0, 0, 0) |
| Direction | (0, 0, 1) |
| Range | 0 |
| Falloff | 0 |
| Attenuation0 | 0 |
| Attenuation1 | 0 |
| Attenuation2 | 0 |
| Theta | 0 |
| Phi | 0 |

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetLight](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getlight)

[IDirect3DDevice9::GetLightEnable](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getlightenable)

[IDirect3DDevice9::SetLight](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setlight)