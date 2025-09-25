# IDXGISwapChain4::SetHDRMetaData

## Description

> [!WARNING]
> It is no longer recommended for apps to explicitly set HDR metadata on their swap chain using **SetHDRMetaData**. Windows does not guarantee that swap chain metadata is sent to the monitor, and monitors do not handle HDR metadata consistently. Therefore it's recommended that apps always tone-map content into the range reported by the monitor. For more details on how to write apps that react dynamically to monitor capabilities, see [Using DirectX with high dynamic range displays and Advanced Color](https://learn.microsoft.com/windows/win32/direct3darticles/high-dynamic-range).
>
> See Remarks for more details.

This method sets High Dynamic Range (HDR) and Wide Color Gamut (WCG) header metadata.

## Parameters

### `Type` [in]

Type: **[DXGI_HDR_METADATA_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ne-dxgi1_5-dxgi_hdr_metadata_type)**

Specifies one member of the [DXGI_HDR_METADATA_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ne-dxgi1_5-dxgi_hdr_metadata_type) enum.

### `Size` [in]

Type: **UINT**

Specifies the size of *pMetaData*, in bytes.

### `pMetaData` [in, optional]

Type: **void***

Specifies a void pointer that references the metadata, if it exists. Refer to the [DXGI_HDR_METADATA_HDR10](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ns-dxgi1_5-dxgi_hdr_metadata_hdr10) structure.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## Remarks

This method sets metadata to enable a monitor's output to be adjusted depending on its capabilities. However it does not change how pixel values are interpreted by Windows or monitors. To adjust the color space of the swap chain, use [**SetColorSpace1**](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nf-dxgi1_4-idxgiswapchain3-setcolorspace1) instead.

Applications should not rely on the metadata being sent to the monitor as the metadata may be ignored. Monitors do not consistently process HDR metadata, resulting in varied appearance of your content across different monitors. In order to ensure more consistent output across a range of monitors, devices, and use cases, it is recommended to not use **SetHDRMetaData** and to instead tone-map content into the gamut and luminance range supported by the monitor. See [IDXGIOutput6::GetDesc1](https://learn.microsoft.com/windows/win32/api/dxgi1_6/nf-dxgi1_6-idxgioutput6-getdesc1) to retrieve the monitor's supported gamut and luminance range. Monitors adhering to the VESA DisplayHDR standard will automatically perform a form of clipping for content outside of the monitor's supported gamut and luminance range.

For more details on how to write apps that react dynamically to monitor capabilities, see [Using DirectX with high dynamic range displays and Advanced Color](https://learn.microsoft.com/windows/win32/direct3darticles/high-dynamic-range).

## See also

[DXGI 1.5 Improvements](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-1-5-improvements)

[IDXGISwapChain4](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nn-dxgi1_5-idxgiswapchain4)