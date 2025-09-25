# IDXGISwapChain1::SetRotation

## Description

Sets the rotation of the back buffers for the swap chain.

## Parameters

### `Rotation` [in]

A [DXGI_MODE_ROTATION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173065(v=vs.85))-typed value that specifies how to set the rotation of the back buffers for the swap chain.

## Return value

**SetRotation** returns:

* S_OK if it successfully set the rotation.
* DXGI_ERROR_INVALID_CALL if the swap chain is bit-block transfer (bitblt) model. The swap chain must be flip model to successfully call **SetRotation**.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **SetRotation** fails with DXGI_ERROR_INVALID_CALL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

You can only use **SetRotation** to rotate the back buffers for flip-model swap chains that you present in windowed mode.

**SetRotation** isn't supported for rotating the back buffers for flip-model swap chains that you present in full-screen mode. In this situation, **SetRotation** doesn't fail, but you must ensure that you specify no rotation ([DXGI_MODE_ROTATION_IDENTITY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173065(v=vs.85))) for the swap chain. Otherwise, when you call [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) or [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present) to present a frame, the presentation fails.

## See also

[IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1)