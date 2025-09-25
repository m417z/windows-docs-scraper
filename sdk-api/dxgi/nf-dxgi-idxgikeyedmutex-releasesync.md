# IDXGIKeyedMutex::ReleaseSync

## Description

Using a key, releases exclusive rendering access to a shared resource.

## Parameters

### `Key`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that indicates which device to give access to. This method succeeds when the device that currently owns the surface calls the **ReleaseSync** method using the same value. This value can be any UINT64 value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful.

If the device attempted to release a keyed mutex that is not valid or owned by the device, **ReleaseSync** returns E_FAIL.

## Remarks

The **ReleaseSync** method releases a lock to a surface that is shared between multiple devices. This method uses a key to determine which device currently has exclusive access to the surface.

When a surface is created using the **D3D10_RESOURCE_MISC_SHARED_KEYEDMUTEX** value of the [D3D10_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_resource_misc_flag) enumeration,
you must call the [IDXGIKeyedMutex::AcquireSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-acquiresync) method before rendering to the surface. You must call the **ReleaseSync** method when you are done
rendering to a surface.

After you call the **ReleaseSync** method, the shared resource is unset from the rendering pipeline.

To acquire a reference to the keyed mutex object of a shared resource, call the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method of the resource and pass in
the **UUID** of the [IDXGIKeyedMutex](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgikeyedmutex) interface. For more information about acquiring this reference, see the following code example.

#### Examples

**Acquiring a Keyed Mutex**

The following code example demonstrates how to acquire a lock to a shared resource and how to specify a key upon release.

```

// pDesc has already been set up with texture description.
pDesc.MiscFlags = D3D10_RESOURCE_MISC_SHARED_KEYEDMUTEX;

// Create a shared texture resource.
pD3D10DeviceD->CreateTexture2D(pDesc, NULL, pD3D10Texture);

// Acquire a reference to the keyed mutex.
pD3D10Texture->QueryInterface(_uuidof(IDXGIKeyedMutex), pDXGIKeyedMutex);

// Acquire a lock to the resource.
pDXGIKeyedMutex->AcquireSync(0, INFINITE);

// Release the lock and specify a key.
pDXGIKeyedMutex->ReleaseSync(1);

```

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIKeyedMutex](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgikeyedmutex)

[IDXGIKeyedMutex::AcquireSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-acquiresync)