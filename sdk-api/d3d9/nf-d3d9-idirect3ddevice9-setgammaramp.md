# IDirect3DDevice9::SetGammaRamp

## Description

Sets the gamma correction ramp for the implicit swap chain. This method will affect the entire screen (not just the active window if you are running in windowed mode).

## Parameters

### `iSwapChain` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Unsigned integer specifying the swap chain.

### `Flags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates whether correction should be applied. Gamma correction results in a more consistent display, but can incur processing overhead and should not be used frequently. Short-duration effects, such as flashing the whole screen red, should not be calibrated, but long-duration gamma changes should be calibrated. One of the following values can be set:

| Item | Description |
| --- | --- |
| D3DSGR_CALIBRATE | If a gamma calibrator is installed, the ramp will be modified before being sent to the device to account for the system and monitor response curves. If a calibrator is not installed, the ramp will be passed directly to the device. |
| D3DSGR_NO_CALIBRATION | No gamma correction is applied. The supplied gamma table is transferred directly to the device. |

### `pRamp` [in]

Type: **const [D3DGAMMARAMP](https://learn.microsoft.com/windows/desktop/direct3d9/d3dgammaramp)***

Pointer to a [D3DGAMMARAMP](https://learn.microsoft.com/windows/desktop/direct3d9/d3dgammaramp) structure, representing the gamma correction ramp to be set for the implicit swap chain.

## Remarks

There is always at least one swap chain (the implicit swap chain) for each device, because Direct3D 9 has one swap chain as a property of the device. The gamma ramp takes effect immediately; there is no wait for a vertical sync.

If the device does not support gamma ramps in the swap chain's current presentation mode (full-screen or windowed), no error return is given. Applications can check the D3DCAPS2_FULLSCREENGAMMA and D3DCAPS2_CANCALIBRATEGAMMA capability bits in the Caps2 member of the D3DCAPS9 structure to determine the capabilities of the device and whether a calibrator is installed.

For windowed gamma correction presentation, use [IDirect3DSwapChain9::Present](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dswapchain9-present) if the hardware supports the feature. In DirectX 8, SetGammaRamp will set the gamma ramp only on a full-screen mode application. For more information about gamma correction, see [Gamma (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/gamma).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetGammaRamp](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getgammaramp)

[IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9)