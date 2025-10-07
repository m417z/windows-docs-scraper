# D3DDEVTYPE enumeration

Defines device types.

## Constants

**D3DDEVTYPE\_HAL**

Hardware rasterization. Shading is done with software, hardware, or mixed transform and lighting.

**D3DDEVTYPE\_NULLREF**

Initialize Direct3D on a computer that has neither hardware nor reference rasterization available, and enable resources for 3D content creation. See Remarks.

**D3DDEVTYPE\_REF**

Direct3D features are implemented in software; however, the reference rasterizer does make use of special CPU instructions whenever it can.

The reference device is installed by the Windows SDK 8.0 or later and is intended as an aid in debugging for development only.

**D3DDEVTYPE\_SW**

A pluggable software device that has been registered with [**IDirect3D9::RegisterSoftwareDevice**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-registersoftwaredevice).

**D3DDEVTYPE\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

All methods of the [**IDirect3D9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3d9) interface that take a **D3DDEVTYPE** device type will fail if D3DDEVTYPE\_NULLREF is specified. To use these methods, substitute D3DDEVTYPE\_REF in the method call.

A D3DDEVTYPE\_REF device should be created in D3DPOOL\_SCRATCH memory, unless vertex and index buffers are required. To support vertex and index buffers, create the device in D3DPOOL\_SYSTEMMEM memory.

If D3dref9.dll is installed, Direct3D will use the reference rasterizer to create a D3DDEVTYPE\_REF device type, even if D3DDEVTYPE\_NULLREF is specified. If D3dref9.dll is not available and D3DDEVTYPE\_NULLREF is specified, Direct3D will neither render nor present the scene.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**IDirect3D9::CheckDeviceFormat**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-checkdeviceformat)

[**IDirect3D9::CheckDeviceMultiSampleType**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-checkdevicemultisampletype)

[**IDirect3D9::CheckDeviceType**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-checkdevicetype)

[**IDirect3D9::CreateDevice**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-createdevice)

[**IDirect3D9::GetDeviceCaps**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3d9-getdevicecaps)

[**D3DDEVICE\_CREATION\_PARAMETERS**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddevice-creation-parameters)

