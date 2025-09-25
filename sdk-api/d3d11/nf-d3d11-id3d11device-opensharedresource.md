# ID3D11Device::OpenSharedResource

## Description

Give a device access to a shared resource created on a different device.

## Parameters

### `hResource` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A resource handle. See remarks.

### `ReturnedInterface` [in]

Type: **REFIID**

The globally unique identifier (GUID) for the resource interface. See remarks.

### `ppResource` [out, optional]

Type: **void****

Address of a pointer to the resource we are gaining access to.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The REFIID, or GUID, of the interface to the resource can be obtained by using the __uuidof() macro. For example, __uuidof(ID3D11Buffer) will get the GUID of the interface to a buffer resource.

The unique handle of the resource is obtained differently depending on the type of device that originally created the resource.

To share a resource between two Direct3D 11 devices the resource must have been created with the
[D3D11_RESOURCE_MISC_SHARED](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag, if it was created using the ID3D11Device interface.
If it was created using a DXGI device interface, then the resource is always shared.

The REFIID, or GUID, of the interface to the resource can be obtained by using the __uuidof() macro.
For example, __uuidof(ID3D11Buffer) will get the GUID of the interface to a buffer resource.

When sharing a resource between two Direct3D 10/11 devices the unique handle of the resource can be obtained by querying the resource for the [IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource) interface and then calling [GetSharedHandle](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiresource-getsharedhandle).

```

IDXGIResource* pOtherResource(NULL);
hr = pOtherDeviceResource->QueryInterface( __uuidof(IDXGIResource), (void**)&pOtherResource );
HANDLE sharedHandle;
pOtherResource->GetSharedHandle(&sharedHandle);

```

The only resources that can be shared are 2D non-mipmapped textures.

To share a resource between a Direct3D 9 device and a Direct3D 11 device the texture must have been created using
the *pSharedHandle* argument of [CreateTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createtexture).
The shared Direct3D 9 handle is then passed to OpenSharedResource in the *hResource* argument.

The following code illustrates the method calls involved.

```

sharedHandle = NULL; // must be set to NULL to create, can use a valid handle here to open in D3D9
pDevice9->CreateTexture(..., pTex2D_9, &sharedHandle);
...
pDevice11->OpenSharedResource(sharedHandle, __uuidof(ID3D11Resource), (void**)(&tempResource11));
tempResource11->QueryInterface(__uuidof(ID3D11Texture2D), (void**)(&pTex2D_11));
tempResource11->Release();
// now use pTex2D_11 with pDevice11

```

Textures being shared from D3D9 to D3D11 have the following restrictions.

* Textures must be 2D
* Only 1 mip level is allowed
* Texture must have default usage
* Texture must be write only
* MSAA textures are not allowed
* Bind flags must have SHADER_RESOURCE and RENDER_TARGET set
* Only R10G10B10A2_UNORM, R16G16B16A16_FLOAT and R8G8B8A8_UNORM formats are allowed

If a shared texture is updated on one device [ID3D11DeviceContext::Flush](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-flush) must be called on that device.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)