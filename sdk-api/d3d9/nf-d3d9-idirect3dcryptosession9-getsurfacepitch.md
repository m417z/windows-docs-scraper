# IDirect3DCryptoSession9::GetSurfacePitch

## Description

Gets the stride of a protected surface.

## Parameters

### `pSrcSurface`

Pointer to the protected surface.

### `pSurfacePitch`

Receives the stride, in bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A protected surface cannot be locked, so this method provides a way to get the surface stride without locking the surface.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DCryptoSession9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dcryptosession9)