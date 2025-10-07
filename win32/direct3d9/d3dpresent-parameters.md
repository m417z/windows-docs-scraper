# D3DPRESENT\_PARAMETERS structure

Describes the presentation parameters.

## Members

**BackBufferWidth**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of the new swap chain's back buffers, in pixels. If **Windowed** is **FALSE** (the presentation is full-screen), this value must equal the width of one of the enumerated display modes found through [**EnumAdapterModes**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-enumadaptermodes). If **Windowed** is **TRUE** and either **BackBufferWidth** or **BackBufferHeight** is zero, the corresponding dimension of the client area of the **hDeviceWindow** (or the focus window, if **hDeviceWindow** is **NULL**) is taken.

**BackBufferHeight**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of the new swap chain's back buffers, in pixels. If **Windowed** is **FALSE** (the presentation is full-screen), this value must equal the height of one of the enumerated display modes found through [**EnumAdapterModes**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-enumadaptermodes). If **Windowed** is **TRUE** and either **BackBufferWidth** or **BackBufferHeight** is zero, the corresponding dimension of the client area of the **hDeviceWindow** (or the focus window, if **hDeviceWindow** is **NULL**) is taken.

**BackBufferFormat**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

The back buffer format. For more information about formats, see [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat). This value must be one of the render-target formats as validated by [**CheckDeviceType**](https://learn.microsoft.com/windows/desktop/api). You can use [**GetDisplayMode**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getdisplaymode) to obtain the current format.

In fact, D3DFMT\_UNKNOWN can be specified for the **BackBufferFormat** while in windowed mode. This tells the runtime to use the current display-mode format and eliminates the need to call [**GetDisplayMode**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getdisplaymode).

For windowed applications, the back buffer format no longer needs to match the display-mode format because color conversion can now be done by the hardware (if the hardware supports color conversion). The set of possible back buffer formats is constrained, but the runtime will allow any valid back buffer format to be presented to any desktop format. (There is the additional requirement that the device be operable in the desktop; devices typically do not operate in 8 bits per pixel modes.)

Full-screen applications cannot do color conversion.

**BackBufferCount**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

This value can be between 0 and [D3DPRESENT\_BACK\_BUFFERS\_MAX](https://learn.microsoft.com/windows/win32/direct3d9/d3dpresent-back-buffers) (or [D3DPRESENT\_BACK\_BUFFERS\_MAX\_EX](https://learn.microsoft.com/windows/win32/direct3d9/d3dpresent-back-buffers) when using Direct3D 9Ex). Values of 0 are treated as 1. If the number of back buffers cannot be created, the runtime will fail the method call and fill this value with the number of back buffers that could be created. As a result, an application can call the method twice with the same D3DPRESENT\_PARAMETERS structure and expect it to work the second time.

The method fails if one back buffer cannot be created. The value of **BackBufferCount** influences what set of swap effects are allowed. Specifically, any D3DSWAPEFFECT\_COPY swap effect requires that there be exactly one back buffer.

**MultiSampleType**

Type: **[**D3DMULTISAMPLE\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmultisample-type)**

Member of the [**D3DMULTISAMPLE\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmultisample-type) enumerated type. The value must be D3DMULTISAMPLE\_NONE unless **SwapEffect** has been set to D3DSWAPEFFECT\_DISCARD. Multisampling is supported only if the swap effect is D3DSWAPEFFECT\_DISCARD.

**MultiSampleQuality**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Quality level. The valid range is between zero and one less than the level returned by pQualityLevels used by [**CheckDeviceMultiSampleType**](https://learn.microsoft.com/windows/desktop/api). Passing a larger value returns the error D3DERR\_INVALIDCALL. Paired values of render targets or of depth stencil surfaces and [**D3DMULTISAMPLE\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmultisample-type) must match.

**SwapEffect**

Type: **[**D3DSWAPEFFECT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dswapeffect)**

Member of the [**D3DSWAPEFFECT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dswapeffect) enumerated type. The runtime will guarantee the implied semantics concerning buffer swap behavior; therefore, if **Windowed** is **TRUE** and **SwapEffect** is set to D3DSWAPEFFECT\_FLIP, the runtime will create one extra back buffer and copy whichever becomes the front buffer at presentation time.

D3DSWAPEFFECT\_COPY requires that **BackBufferCount** be set to 1.

D3DSWAPEFFECT\_DISCARD will be enforced in the debug runtime by filling any buffer with noise after it is presented.

Differences between Direct3D9 and Direct3D9Ex:

- In Direct3D9Ex, D3DSWAPEFFECT\_FLIPEX is added to designate when an application is adopting flip mode. That is, when an application's frame is passed in window's mode (instead of copied) to the Desktop Window Manager(DWM) for composition. Flip mode provides more efficient memory bandwidth and enables an application to take advantage of full-screen-present statistics. It does not change full screen behavior. Flip mode behavior is available beginning with Windows 7.

**hDeviceWindow**

Type: **[**HWND**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The device window determines the location and size of the back buffer on screen. This is used by Direct3D when the back buffer contents are copied to the front buffer during [**Present**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-present).

- For a full-screen application, this is a handle to the top window (which is the focus window).

 For applications that use multiple full-screen devices (such as a multimonitor system), exactly one device can use the focus window as the device window. All other devices must have unique device windows.

- For a windowed-mode application, this handle will be the default target window for [**Present**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-present). If this handle is **NULL**, the focus window will be taken.

Note that no attempt is made by the runtime to reflect user changes in window size. The back buffer is not implicitly reset when this window is reset. However, the [**Present**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-present) method does automatically track window position changes.

**Windowed**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**TRUE** if the application runs windowed; **FALSE** if the application runs full-screen.

**EnableAutoDepthStencil**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If this value is **TRUE**, Direct3D will manage depth buffers for the application. The device will create a depth-stencil buffer when it is created. The depth-stencil buffer will be automatically set as the render target of the device. When the device is reset, the depth-stencil buffer will be automatically destroyed and recreated in the new size.

If EnableAutoDepthStencil is **TRUE**, then AutoDepthStencilFormat must be a valid depth-stencil format.

**AutoDepthStencilFormat**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type. The format of the automatic depth-stencil surface that the device will create. This member is ignored unless **EnableAutoDepthStencil** is **TRUE**.

**Flags**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

One of the [D3DPRESENTFLAG](https://learn.microsoft.com/windows/win32/direct3d9/d3dpresentflag) constants.

**FullScreen\_RefreshRateInHz**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The rate at which the display adapter refreshes the screen. The value depends on the mode in which the application is running:

- For windowed mode, the refresh rate must be 0.
- For full-screen mode, the refresh rate is one of the refresh rates returned by [**EnumAdapterModes**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-enumadaptermodes).

**PresentationInterval**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The maximum rate at which the swap chain's back buffers can be presented to the front buffer. For a detailed explanation of the modes and the intervals that are supported, see [D3DPRESENT](https://learn.microsoft.com/windows/win32/direct3d9/d3dpresent).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**CreateDevice**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-createdevice)

[**CreateAdditionalSwapChain**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createadditionalswapchain)

[**Present**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-present)

[**Reset**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-reset)

