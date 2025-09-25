# Direct3DCreate9 function

## Description

Create an IDirect3D9 object and return an interface to it.

## Parameters

### `SDKVersion`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value of this parameter should be D3D_SDK_VERSION. See Remarks.

## Return value

Type: **[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)***

If successful, this function returns a pointer to an [IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9) interface; otherwise, a **NULL** pointer is returned.

## Remarks

The Direct3D object is the first Direct3D COM object that your graphical application needs to create and the last object that your application needs to release. Functions for enumerating and retrieving capabilities of a device are accessible through the Direct3D object. This enables applications to select devices without creating them.

Create an IDirect3D9 object as shown here:

```

LPDIRECT3D9 g_pD3D = NULL;

if( NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
    return E_FAIL;

```

The IDirect3D9 interface supports enumeration of active display adapters and allows the creation of [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) objects. If the user dynamically adds adapters (either by adding devices to the desktop, or by hot-docking a laptop), those devices will not be included in the enumeration. Creating a new IDirect3D9 interface will expose the new devices.

D3D_SDK_VERSION is passed to this function to ensure that the header files against which an application is compiled match the version of the runtime DLL's that are installed on the machine. D3D_SDK_VERSION is only changed in the runtime when a header change (or other code change) would require an application to be rebuilt. If this function fails, it indicates that the header file version does not match the runtime DLL version.

For an example, see [Creating a Device (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/creating-a-device).

## See also

[Direct3D Functions](https://learn.microsoft.com/windows/desktop/direct3d9/dx9-graphics-reference-d3d-functions)