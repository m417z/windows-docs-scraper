# IDirect3DDevice9::SetLight

## Description

Assigns a set of lighting properties for this device.

## Parameters

### `Index` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index of the set of lighting properties to set. If a set of lighting properties exists at this index, it is overwritten by the new properties specified in pLight.

### `unnamedParam2` [in]

Type: **const [D3DLIGHT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlight9)***

Pointer to a [D3DLIGHT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlight9) structure, containing the lighting parameters to set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

Set light properties by preparing a [D3DLIGHT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlight9) structure and then calling the **IDirect3DDevice9::SetLight** method. The **IDirect3DDevice9::SetLight** method accepts the index at which the device should place the set of light properties to its internal list of light properties, and the address of a prepared **D3DLIGHT9** structure that defines those properties. You can call **IDirect3DDevice9::SetLight** with new information as needed to update the light's illumination properties.

The system allocates memory to accommodate a set of lighting properties each time you call the **IDirect3DDevice9::SetLight** method with an index that has never been assigned properties. Applications can set a number of lights, with only a subset of the assigned lights enabled at a time. Check the MaxActiveLights member of the [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure when you retrieve device capabilities to determine the maximum number of active lights supported by that device. If you no longer need a light, you can disable it or overwrite it with a new set of light properties.

The following example prepares and sets properties for a white point-light whose emitted light will not attenuate over distance.

```

// Assume d3dDevice is a valid pointer to an IDirect3DDevice9 interface.
D3DLIGHT9 d3dLight;
HRESULT   hr;

// Initialize the structure.
ZeroMemory(&d3dLight, sizeof(d3dLight));

// Set up a white point light.
d3dLight.Type = D3DLIGHT_POINT;
d3dLight.Diffuse.r  = 1.0f;
d3dLight.Diffuse.g  = 1.0f;
d3dLight.Diffuse.b  = 1.0f;
d3dLight.Ambient.r  = 1.0f;
d3dLight.Ambient.g  = 1.0f;
d3dLight.Ambient.b  = 1.0f;
d3dLight.Specular.r = 1.0f;
d3dLight.Specular.g = 1.0f;
d3dLight.Specular.b = 1.0f;

// Position it high in the scene and behind the user.
// Remember, these coordinates are in world space, so
// the user could be anywhere in world space, too.
// For the purposes of this example, assume the user
// is at the origin of world space.
d3dLight.Position.x = 0.0f;
d3dLight.Position.y = 1000.0f;
d3dLight.Position.z = -100.0f;

// Don't attenuate.
d3dLight.Attenuation0 = 1.0f;
d3dLight.Range        = 1000.0f;

// Set the property information for the first light.
hr = d3dDevice->SetLight(0, &d3dLight);
if (SUCCEEDED(hr))
    // Handle Success
else
    // Handle failure

```

Enable a light source by calling the [IDirect3DDevice9::LightEnable](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-lightenable) method for the device.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetLight](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getlight)

[IDirect3DDevice9::GetLightEnable](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getlightenable)

[IDirect3DDevice9::LightEnable](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-lightenable)