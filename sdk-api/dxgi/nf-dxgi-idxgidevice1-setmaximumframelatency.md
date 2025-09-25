# IDXGIDevice1::SetMaximumFrameLatency

## Description

Sets the number of frames that the system is allowed to queue for rendering.

## Parameters

### `MaxLatency`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The maximum number of back buffer frames that a driver can queue. The value defaults to 3, but
can range from 1 to 16. A value of 0 will reset latency to the default. For multi-head devices, this value is specified per-head.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, DXGI_ERROR_DEVICE_REMOVED if the device was removed.

## Remarks

This method is not supported by DXGI 1.0, which shipped in Windows Vista and Windows Server 2008. DXGI 1.1 support is required, which is available on
Windows 7, Windows Server 2008 R2, and as an update to Windows Vista with Service Pack 2 (SP2) ([KB 971644](https://support.microsoft.com/topic/application-compatibility-update-for-windows-vista-windows-server-2008-windows-7-and-windows-server-2008-r2-february-2010-3eb7848b-9a76-85fe-98d0-729e3827ea60)) and Windows Server 2008 ([KB 971512](https://support.microsoft.com/kb/971512/)).

Frame latency is the number of frames that are allowed to be stored in a queue before submission for rendering. Latency is often used to
control how the CPU chooses between responding to user input and frames that are in the render queue. It is often beneficial for applications that
have no user input (for example, video playback) to queue more than 3 frames of data.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIDevice1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice1)

[IDXGIDevice1::GetMaximumFrameLatency](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgidevice1-getmaximumframelatency)