# IDXGIDevice1::GetMaximumFrameLatency

## Description

Gets the number of frames that the system is allowed to queue for rendering.

## Parameters

### `pMaxLatency` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

This value is set to the number of frames that can be queued for render.
This value defaults to 3, but can range from 1 to 16.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the following members of the [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr) enumerated type:

* **D3DERR_DEVICELOST**
* **D3DERR_DEVICEREMOVED**
* **D3DERR_DRIVERINTERNALERROR**
* **D3DERR_INVALIDCALL**
* **D3DERR_OUTOFVIDEOMEMORY**

## Remarks

This method is not supported by DXGI 1.0, which shipped in Windows Vista and Windows Server 2008. DXGI 1.1 support is required, which is available on
Windows 7, Windows Server 2008 R2, and as an update to Windows Vista with Service Pack 2 (SP2) ([KB 971644](https://support.microsoft.com/topic/application-compatibility-update-for-windows-vista-windows-server-2008-windows-7-and-windows-server-2008-r2-february-2010-3eb7848b-9a76-85fe-98d0-729e3827ea60)) and Windows Server 2008 ([KB 971512](https://support.microsoft.com/kb/971512/)).

Frame latency is the number of frames that are allowed to be stored in a queue before submission for rendering. Latency is often
used to control how the CPU chooses between responding to user input and frames that are in the render queue. It is often beneficial for applications
that have no user input (for example, video playback) to queue more than 3 frames of data.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIDevice1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice1)

[IDXGIDevice1::SetMaximumFrameLatency](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgidevice1-setmaximumframelatency)