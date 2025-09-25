# IDirect3DDevice9::GetLight

## Description

Retrieves a set of lighting properties that this device uses.

## Parameters

### `Index` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index of the lighting property set to retrieve. This method will fail if a lighting property has not been set for this index by calling the [IDirect3DDevice9::SetLight](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setlight) method.

### `unnamedParam2` [out]

Type: **[D3DLight9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlight9)***

Pointer to a [D3DLIGHT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlight9) structure that is filled with the retrieved lighting-parameter set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

This method will not return device state for a device that is created using D3DCREATE_PUREDEVICE. If you want to use this method, you must create your device with any of the other values in [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate).

Retrieve all the properties for an existing light source by calling the **IDirect3DDevice9::GetLight** method for the device. When calling the **IDirect3DDevice9::GetLight** method, pass the zero-based index of the light source for which the properties will be retrieved as the first parameter, and supply the address of a [D3DLIGHT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dlight9) structure as the second parameter. The device fills the **D3DLIGHT9** structure to describe the lighting properties it uses for the light source at that index.

```

// Assume d3dDevice is a valid pointer to an IDirect3DDevice9 interface.
HRESULT hr;
D3DLight9 light;

// Get the property information for the first light.
hr = pd3dDevice->GetLight(0, &light);
if (SUCCEEDED(hr))
    // Handle Success
else
    // Handle failure

```

If you supply an index outside the range of the light sources assigned in the device, the **IDirect3DDevice9::GetLight** method fails, returning D3DERR_INVALIDCALL.

When you assign a set of light properties for a light source in a scene, the light source can be activated by calling the [IDirect3DDevice9::LightEnable](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-lightenable) method for the device. New light sources are disabled by default. The **IDirect3DDevice9::LightEnable** method accepts two parameters. Set the first parameter to the zero-based index of the light source to be affected by the method, and set the second parameter to **TRUE** to enable the light or **FALSE** to disable it. The following code example illustrates the use of this method by enabling the first light source in the device's list of light source properties.

```

// Assume d3dDevice is a valid pointer to an IDirect3DDevice9 interface.
HRESULT hr;

hr = pd3dDevice->LightEnable(0, TRUE);
if (SUCCEEDED(hr))
    // Handle Success
else
    // Handle failure

```

Check the MaxActiveLights member of the [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure when you retrieve device capabilities to determine the maximum number of active lights supported by that device.

If you enable or disable a light that has no properties that are set with [IDirect3DDevice9::SetLight](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setlight), the [IDirect3DDevice9::LightEnable](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-lightenable) method creates a light source with the properties listed in following table and enables or disables it.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetLightEnable](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getlightenable)

[IDirect3DDevice9::LightEnable](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-lightenable)

[IDirect3DDevice9::SetLight](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setlight)