# IDXGISwapChain1::GetRotation

## Description

Gets the rotation of the back buffers for the swap chain.

## Parameters

### `pRotation` [out]

A pointer to a variable that receives a [DXGI_MODE_ROTATION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173065(v=vs.85))-typed value that specifies the rotation of the back buffers for the swap chain.

## Return value

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **GetRotation** fails with DXGI_ERROR_INVALID_CALL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## See also

[IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1)