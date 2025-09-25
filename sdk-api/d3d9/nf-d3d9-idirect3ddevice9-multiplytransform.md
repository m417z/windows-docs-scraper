# IDirect3DDevice9::MultiplyTransform

## Description

Multiplies a device's world, view, or projection matrices by a specified matrix.

## Parameters

### `unnamedParam1` [in]

Type: **[D3DTRANSFORMSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtransformstatetype)**

Member of the [D3DTRANSFORMSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtransformstatetype) enumerated type, or the [D3DTS_WORLDMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dts-worldmatrix) macro that identifies which device matrix is to be modified. The most common setting, **D3DTS_WORLDMATRIX**(0), modifies the world matrix, but you can specify that the method modify the view or projection matrices, if needed.

### `unnamedParam2` [in]

Type: **const [D3DMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmatrix)***

Pointer to a [D3DMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmatrix) structure that modifies the current transformation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL if one of the arguments is invalid.

## Remarks

The multiplication order is pMatrix times State.

An application might use the **IDirect3DDevice9::MultiplyTransform** method to work with hierarchies of transformations. For example, the geometry and transformations describing an arm might be arranged in the following hierarchy.

```

    shoulder_transformation

    upper_arm geometry

    elbow transformation

    lower_arm geometry

    wrist transformation

    hand geometry

```

An application might use the following series of calls to render this hierarchy. Not all the parameters are shown in this pseudocode.

```

IDirect3DDevice9::SetTransform(D3DTS_WORLDMATRIX(0),
                               shoulder_transform)
IDirect3DDevice9::DrawPrimitive(upper_arm)
IDirect3DDevice9::MultiplyTransform(D3DTS_WORLDMATRIX(0),
                                    elbow_transform)
IDirect3DDevice9::DrawPrimitive(lower_arm)
IDirect3DDevice9::MultiplyTransform(D3DTS_WORLDMATRIX(0),
                                    wrist_transform)
IDirect3DDevice9::DrawPrimitive(hand)
```

## See also

[D3DTS_WORLD](https://learn.microsoft.com/windows/desktop/direct3d9/d3dts-world)

[D3DTS_WORLDMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dts-worldmatrix)

[D3DTS_WORLDn](https://learn.microsoft.com/windows/desktop/direct3d9/d3dts-worldn)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::DrawPrimitive](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-drawprimitive)

[IDirect3DDevice9::SetTransform](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settransform)