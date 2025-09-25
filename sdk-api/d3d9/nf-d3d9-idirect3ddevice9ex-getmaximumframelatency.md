# IDirect3DDevice9Ex::GetMaximumFrameLatency

## Description

Retrieves the number of frames of data that the system is allowed to queue.

## Parameters

### `pMaxLatency` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Returns the number of frames that can be queued for render. The value is typically 3, but can range from 1 to 20.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Possible return values include: D3D_OK, D3DERR_DEVICELOST, D3DERR_DEVICEREMOVED, D3DERR_DRIVERINTERNALERROR, D3DERR_INVALIDCALL, or D3DERR_OUTOFVIDEOMEMORY (see [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr)).

## Remarks

Frame latency is the number of frames that are allowed to be stored in a queue, before submission for rendering. Latency is often used to control how the CPU chooses between responding to user input and frames that are in the render queue.

It is often beneficial for applications that have no user input (for example, video playback) to queue more than 3 frames of data.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)