# D3DDEVICE\_CREATION\_PARAMETERS structure

Describes the creation parameters for a device.

## Members

**AdapterOrdinal**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Ordinal number that denotes the display adapter. D3DADAPTER\_DEFAULT is always the primary display adapter. Use this ordinal as the Adapter parameter for any of the [**IDirect3D9**](https://learn.microsoft.com/windows/desktop/api) methods. Note that different instances of Direct3D 9.0 objects can use different ordinals. Adapters can enter or leave a system when users, for example, add or remove monitors from a multiple-monitor system or when they hot-swap a laptop. Consequently, use this ordinal only in a Direct3D 9.0 instance known to be valid, that is, either the Direct3D 9.0 that created this [**IDirect3DDevice9**](https://learn.microsoft.com/windows/desktop/api) interface or the Direct3D 9.0 returned from [**GetDirect3D**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getdirect3d), as called through this **IDirect3DDevice9** interface.

**DeviceType**

Type: **[**D3DDEVTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddevtype)**

Member of the [**D3DDEVTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddevtype) enumerated type. Denotes the amount of emulated functionality for this device. The value of this parameter mirrors the value passed to the [**CreateDevice**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-createdevice) call that created this device.

**hFocusWindow**

Type: **[**HWND**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Window handle to which focus belongs for this Direct3D device. The value of this parameter mirrors the value passed to the [**CreateDevice**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-createdevice) call that created this device.

**BehaviorFlags**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A combination of one or more [D3DCREATE](https://learn.microsoft.com/windows/win32/direct3d9/d3dcreate) constants that control global behavior of the device. These constants mirror the constants passed to [**CreateDevice**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-createdevice) when the device was created.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetCreationParameters**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getcreationparameters)

[**CreateDevice**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-createdevice)

