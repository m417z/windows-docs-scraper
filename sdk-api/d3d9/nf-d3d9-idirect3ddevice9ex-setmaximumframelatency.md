# IDirect3DDevice9Ex::SetMaximumFrameLatency

## Description

Set the number of frames that the system is allowed to queue for rendering.

## Parameters

### `MaxLatency` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The maximum number of back buffer frames that a driver can queue. The value is typically 3, but can range from 1 to 20. A value of 0 will reset latency to the default. For multi-head devices, *MaxLatency* is specified per-head.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Possible return values include: D3D_OK or D3DERR_DEVICEREMOVED (see [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr)).

## Remarks

Frame latency is the number of frames that are allowed to be stored in a queue, before submission for rendering. Latency is often used to control how the CPU chooses between responding to user input and frames that are in the render queue.

It is often beneficial for applications that have no user input (for example, video playback) to queue more than 3 frames of data.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)