# IDirect3D9::RegisterSoftwareDevice

## Description

Registers a pluggable software device. Software devices provide software rasterization enabling applications to access a variety of software rasterizers.

## Parameters

### `pInitializeFunction` [in]

Type: **void***

Pointer to the initialization function for the software device to be registered.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL. The method call is invalid. For example, a method's parameter may have an invalid value: D3DERR_OUTOFVIDEOMEMORY.

## Remarks

If the user's computer provides no special hardware acceleration for 3D operations, your application might emulate 3D hardware in software. Software rasterization devices emulate the functions of color 3D hardware in software. A software device runs more slowly than a hal. However, software devices take advantage of any special instructions supported by the CPU to increase performance. Instruction sets include the AMD 3DNow! instruction set on some AMD processors and the MMX instruction set supported by many Intel processors. Direct3D uses the 3D-Now! instruction set to accelerate transformation and lighting operations and the MMX instruction set to accelerate rasterization.

Software devices communicate with Direct3D through an interface similar to the hardware device driver interface (DDI).

Software devices are loaded by the application and registered with the [IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9) object. Direct3D uses the software device for rendering.

The Direct3D Driver Development Kit (DDK) provides the documentation and headers for developing pluggable software devices.

## See also

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)