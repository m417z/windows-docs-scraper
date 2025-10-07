# D3DMULTISAMPLE\_TYPE enumeration

Defines the levels of full-scene multisampling that the device can apply.

## Constants

**D3DMULTISAMPLE\_NONE**

No level of full-scene multisampling is available.

**D3DMULTISAMPLE\_NONMASKABLE**

Enables the multisample quality value. See Remarks.

**D3DMULTISAMPLE\_2\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_3\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_4\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_5\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_6\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_7\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_8\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_9\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_10\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_11\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_12\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_13\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_14\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_15\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_16\_SAMPLES**

Level of full-scene multisampling available.

**D3DMULTISAMPLE\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

In addition to enabling full-scene multisampling at [**IDirect3DDevice9::Reset**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-reset) time, there will be render states that turn various aspects on and off at fine-grained levels.

Multisampling is valid only on a swap chain that is being created or reset with the D3DSWAPEFFECT\_DISCARD swap effect.

The multisample antialiasing value can be set with the parameters (or sub-parameters) in the following methods.

| Method | Parameters | Sub-parameters |
|----------------------------------------------------------------------------------------------------|------------------------------------|------------------------------------|
| [**IDirect3D9::CheckDeviceMultiSampleType**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-checkdevicemultisampletype) | MultiSampleType and pQualityLevels | |
| [**IDirect3D9::CreateDevice**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-createdevice) | pPresentationParameters | MultiSampleType and pQualityLevels |
| [**IDirect3DDevice9::CreateAdditionalSwapChain**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createadditionalswapchain) | pPresentationParameters | MultiSampleType and pQualityLevels |
| [**IDirect3DDevice9::CreateDepthStencilSurface**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createdepthstencilsurface) | MultiSampleType and pQualityLevels | |
| [**IDirect3DDevice9::CreateRenderTarget**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createrendertarget) | MultiSampleType and pQualityLevels | |
| [**IDirect3DDevice9::Reset**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-reset) | pPresentationParameters | MultiSampleType and pQualityLevels |

It is not good practice to switch from one multisample type to another to raise the quality of the antialiasing.

D3DMULTISAMPLE\_NONE enables swap effects other than discarding, locking, and so on.

Whether the display device supports maskable multisampling (more than one sample for a multiple-sample render-target format plus antialias support) or just non-maskable multisampling (only antialias support), the driver for the device provides the number of quality levels for the D3DMULTISAMPLE\_NONMASKABLE multiple-sample type. Applications that just use multisampling for antialiasing purposes only need to query for the number of non-maskable multiple-sample quality levels that the driver supports.

The quality levels supported by the device can be obtained with the pQualityLevels parameter of [**IDirect3D9::CheckDeviceMultiSampleType**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-checkdevicemultisampletype). Quality levels used by the application are set with the MultiSampleQuality parameter of [**IDirect3DDevice9::CreateDepthStencilSurface**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createdepthstencilsurface) and [**IDirect3DDevice9::CreateRenderTarget**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createrendertarget).

See D3DRS\_MULTISAMPLEMASK for discussion of maskable multisampling.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DPRESENT\_PARAMETERS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpresent-parameters)

[**D3DSURFACE\_DESC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsurface-desc)

