# IDXGISwapChain1::IsTemporaryMonoSupported

## Description

Determines whether a swap chain supports “temporary mono.”

## Return value

Indicates whether to use the swap chain in temporary mono mode. **TRUE** indicates that you can use temporary-mono mode; otherwise, **FALSE**.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **IsTemporaryMonoSupported** always returns FALSE because stereoscopic 3D display behavior isn’t available with the Platform Update for Windows 7. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

Temporary mono is a feature where a stereo swap chain can be presented using only the content in the left buffer. To present using the left buffer as a mono buffer, an application calls the [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) method with the [DXGI_PRESENT_STEREO_TEMPORARY_MONO](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present)
flag. All windowed swap chains support temporary mono. However, full-screen swap chains optionally support temporary mono because not all hardware supports temporary mono on full-screen swap chains efficiently.

## See also

[IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1)