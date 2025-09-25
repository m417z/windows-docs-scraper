# ID3D11Device1::OpenSharedResourceByName

## Description

Gives a device access to a shared resource that is referenced by name and that was created on a different device. You must have previously created the resource as shared and specified that it uses NT handles (that is, you set the [D3D11_RESOURCE_MISC_SHARED_NTHANDLE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag).

## Parameters

### `lpName` [in]

The name of the resource to open. This parameter cannot be **NULL**.

### `dwDesiredAccess` [in]

The requested access rights to the resource. In addition to the [generic access rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/generic-access-rights), DXGI defines the following values:

* **DXGI_SHARED_RESOURCE_READ** ( 0x80000000L ) - specifies read access to the resource.
* **DXGI_SHARED_RESOURCE_WRITE** ( 1 ) - specifies write access to the resource.

You can combine values by using a bitwise **OR** operation.

### `returnedInterface` [in]

The globally unique identifier (GUID) for the resource interface. For more info, see Remarks.

### `ppResource` [out]

A pointer to a variable that receives a pointer to the interface for the shared resource object to access.

## Return value

This method returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues). This method also returns E_ACCESSDENIED if the permissions to access the resource aren't valid.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **OpenSharedResourceByName** fails with E_NOTIMPL because NTHANDLES are used. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

The behavior of **OpenSharedResourceByName** is similar to the behavior of the [ID3D11Device1::OpenSharedResource1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-opensharedresource1) method; each call to **OpenSharedResourceByName** to access a resource creates a new resource object. In other words, if you call **OpenSharedResourceByName** twice and pass the same resource name to *lpName*, you receive two resource objects with different [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointers.

**To share a resource between two devices**

1. Create the resource as shared and specify that it uses NT handles, by setting the [D3D11_RESOURCE_MISC_SHARED_NTHANDLE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag.
2. Obtain the REFIID, or GUID, of the interface to the resource by using the __uuidof() macro. For example, __uuidof([ID3D11Texture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11texture2d)) retrieves the GUID of the interface to a 2D texture.
3. Query the resource for the [IDXGIResource1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiresource1) interface.
4. Call the [IDXGIResource1::CreateSharedHandle](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiresource1-createsharedhandle) method to obtain the unique handle to the resource. In this **IDXGIResource1::CreateSharedHandle** call, you must pass a name for the resource if you want to subsequently call **OpenSharedResourceByName** to access the resource by name.

#### Examples

``` syntax
ID3D11Device1* pDevice;
ID3D11Texture2D* pTexture2D;

pDevice->OpenSharedResourceByName(
          "MySurface",
          DXGI_SHARED_RESOURCE_READ,
          __uuidof(ID3D11Texture2D),
         (void**)&pTexture2D);

```

## See also

[ID3D11Device1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11device1)