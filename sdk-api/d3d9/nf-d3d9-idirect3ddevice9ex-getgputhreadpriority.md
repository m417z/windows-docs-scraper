# IDirect3DDevice9Ex::GetGPUThreadPriority

## Description

Get the priority of the GPU thread.

## Parameters

### `pPriority`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Current GPU priority. Valid values range from -7 to 7.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Possible return values include: D3D_OK or D3DERR_DEVICEREMOVED (see [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr)).

## Remarks

Use [IDirect3DDevice9Ex::SetGPUThreadPriority](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-setgputhreadpriority) to set the priority of a thread.

This method will retrieve the priority of the thread stored with the Direct3D device even if it was created with the [D3DCREATE_PUREDEVICE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate) flag.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)