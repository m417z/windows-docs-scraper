# IDirect3DDevice9Ex::SetGPUThreadPriority

## Description

Set the priority on the GPU thread.

## Parameters

### `Priority` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The thread priority, ranging from -7 to 7.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Possible return values include: D3D_OK, D3DERR_INVALIDCALL, or D3DERR_DEVICEREMOVED (see [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr)).

## Remarks

GPU thread priority is not reset when a device is lost. The effects of calls to this method are not recorded in state blocks.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)