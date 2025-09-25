# Direct3DCreate9Ex function

## Description

Creates an [IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex) object and returns an interface to it.

## Parameters

### `SDKVersion` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value of this parameter should be **D3D_SDK_VERSION**. See Remarks.

### `unnamedParam2` [out]

Type: **[IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex)****

Address of a pointer to an [IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex) interface, representing the
created **IDirect3D9Ex** object. If the function fails, **NULL** is inserted here.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

* **D3DERR_NOTAVAILABLE** if Direct3DEx features are not supported (no WDDM driver is
  installed) or if the **SDKVersion** does not match the version of the DLL.
* **D3DERR_OUTOFMEMORY** if out-of-memory conditions are detected when creating the
  enumerator object.
* **S_OK** if the creation of the enumerator object is successful.

## Remarks

The [IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex) object is the first object that the application creates and the
last object that the application releases. Functions for enumerating and retrieving
capabilities of a device are accessible through the **IDirect3D9Ex** object.
This enables applications to select devices without creating them.

The [IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex) interface supports enumeration of active display adapters
and allows the creation of **IDirect3D9Ex** objects. If the user dynamically adds
adapters (either by adding devices to the desktop, or by hot-docking a laptop), these
devices are not included in the enumeration. Creating a new **IDirect3D9Ex** interface will expose the new devices.

Pass the **D3D_SDK_VERSION** flag to this function to ensure that header files used in the
compiled application match the version of the installed runtime DLLs. **D3D_SDK_VERSION** is changed in the runtime only when a header or another code change would require
rebuilding the application. If this function fails, it indicates that the versions of the
header file and the runtime DLL do not match.

**Note** **Direct3DCreate9Ex** is supported only in Windows Vista, Windows Server 2008, and Windows 7.
Earlier versions of the D3D9.dll library do not include [Direct3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex) and **Direct3DCreate9Ex**.

#### Examples

Creating an IDirect3D9Ex object.

The following code example demonstrates how to create an [IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex) object
using **Direct3DCreate9Ex**. This example then uses the **IDirect3D9Ex** object to
create an [IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex) object, which is returned as an out parameter to
the function.

```cpp
HRESULT InitD3D9Ex( /* IN */ HWND hWnd, /* OUT */ IDirect3DDevice9Ex ** ppD3DDevice )
{
    HRESULT hr = E_FAIL;
    IDirect3D9Ex * pD3D = NULL;
    IDirect3DDevice9Ex * pDevice = NULL;

    if(ppD3DDevice == NULL)
    {
        return hr;
    }

    // Create the D3D object, which is needed to create the D3DDevice.
    if(FAILED(hr = Direct3DCreate9Ex( D3D_SDK_VERSION, &pD3D )))
    {
        *ppD3DDevice = NULL;
        return hr;
    }

    // Set up the structure used to create the D3DDevice.
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp, sizeof(d3dpp) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

    // Create the Direct3D device.
    if( FAILED( hr = pD3D->CreateDeviceEx( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, NULL, &pDevice ) ) )

    {
        *ppD3DDevice = NULL;
        return hr;
    }

    // Device state would normally be set here

    *ppD3DDevice = pDevice;

    return hr;
}

```

Checking for Direct3D9Ex.

The following code example demonstrates how to check for the existence of **Direct3DCreate9Ex** and fail on platforms that do not support it. You can use this code in a game launcher to present
an error message to the user or to load a renderer that uses the [IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9) interface instead.

To check for **Direct3DCreate9Ex**, this example explicitly loads the D3D9.dll
library using the Win32 [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function. The example then assigns the
address of **Direct3DCreate9Ex** to a pointer by using the Win32 [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function. If **Direct3DCreate9Ex** is not present, the function pointer is **NULL**,
and the code example returns an **ERROR_NOT_SUPPORTED** **HRESULT** value.
However, if **Direct3DCreate9Ex** is present, it returns an **S_OK** value.

```cpp
HRESULT CheckD3D9Ex( void )
{
    HRESULT hr = E_FAIL;
    HMODULE libHandle = NULL;

    // Manually load the d3d9.dll library.
    libHandle = LoadLibrary(L"d3d9.dll");

    if(libHandle != NULL)
    {
        // Define a function pointer to the Direct3DCreate9Ex function.
        typedef HRESULT (WINAPI *LPDIRECT3DCREATE9EX)( UINT, void **);

        // Obtain the address of the Direct3DCreate9Ex function.
        LPDIRECT3DCREATE9EX Direct3DCreate9ExPtr = NULL;

        Direct3DCreate9ExPtr = (LPDIRECT3DCREATE9EX)GetProcAddress( libHandle, "Direct3DCreate9Ex" );

        if ( Direct3DCreate9ExPtr != NULL)
        {
            // Direct3DCreate9Ex is supported.
            hr = S_OK;
        }
        else
        {
            // Direct3DCreate9Ex is not supported on this
            // operating system.
            hr = ERROR_NOT_SUPPORTED;
        }

        // Free the library.
        FreeLibrary( libHandle );

    }

    return hr;
}

```

Note that you may cast an [IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex) interface pointer to an [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface pointer because the extended version is inherited. This makes it possible to use the extended device with existing Direct3D 9 code, except where the new device changes the semantics of the interface. For more information about differences between the two interfaces, see [device behavior changes](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh).

## See also

[Direct3D Functions](https://learn.microsoft.com/windows/desktop/direct3d9/dx9-graphics-reference-d3d-functions)