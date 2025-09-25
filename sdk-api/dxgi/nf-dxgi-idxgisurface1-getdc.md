# IDXGISurface1::GetDC

## Description

Returns a device context (DC) that allows you to render to a Microsoft DirectX Graphics Infrastructure (DXGI) surface using Windows Graphics Device Interface (GDI).

## Parameters

### `Discard`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean value that specifies whether to preserve Direct3D contents in the GDI DC. **TRUE** directs the runtime not to preserve Direct3D contents in the GDI DC; that is, the runtime discards the Direct3D contents. **FALSE** guarantees that Direct3D contents are available in the GDI DC.

### `phdc` [out]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to an [HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) handle that represents the current device context for GDI rendering.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, an error code.

## Remarks

This method is not supported by DXGI 1.0, which shipped in Windows Vista and Windows Server 2008. DXGI 1.1 support is required, which is available on
Windows 7, Windows Server 2008 R2, and as an update to Windows Vista with Service Pack 2 (SP2) ([KB 971644](https://support.microsoft.com/topic/application-compatibility-update-for-windows-vista-windows-server-2008-windows-7-and-windows-server-2008-r2-february-2010-3eb7848b-9a76-85fe-98d0-729e3827ea60)) and Windows Server 2008 ([KB 971512](https://support.microsoft.com/kb/971512/)).

After you use the **GetDC** method to retrieve a DC, you can render to the DXGI surface by using GDI.
The **GetDC** method readies the surface for GDI rendering and allows inter-operation between DXGI and GDI technologies.

Keep the following in mind when using this method:

* You must create the surface by using the [D3D11_RESOURCE_MISC_GDI_COMPATIBLE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag for a surface or by using the [DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag) flag for swap chains,
  otherwise this method fails.
* You must release the device and call the [IDXGISurface1::ReleaseDC](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgisurface1-releasedc) method before you issue any new Direct3D commands.
* This method fails if an outstanding DC has already been created by this method.
* The format for the surface or swap chain must be [DXGI_FORMAT_B8G8R8A8_UNORM_SRGB](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) or [DXGI_FORMAT_B8G8R8A8_UNORM](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format).
* On **GetDC**, the render target in the output merger of the Direct3D pipeline is unbound from the surface.
  You must call the [ID3D11DeviceContext::OMSetRenderTargets](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omsetrendertargets) method on the device prior to Direct3D rendering after GDI rendering.
* Prior to resizing buffers you must release all outstanding DCs.

You can also call **GetDC** on the back buffer at index 0 of a swap chain by obtaining an [IDXGISurface1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface1) from the swap chain.
The following code illustrates the process.

```

IDXGISwapChain* g_pSwapChain = NULL;
IDXGISurface1* g_pSurface1 = NULL;
...
//Setup the device and the swapchain
g_pSwapChain->GetBuffer(0, __uuidof(IDXGISurface1), (void**) &g_pSurface1);
g_pSurface1->GetDC( FALSE, &g_hDC );
...
//Draw on the DC using GDI
...
//When finish drawing release the DC
g_pSurface1->ReleaseDC( NULL );

```

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGISurface1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface1)