# IDXGIKeyedMutex::AcquireSync

## Description

Using a key, acquires exclusive rendering access to a shared resource.

## Parameters

### `Key`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that indicates which device to give access to. This method will succeed when the device that currently owns the surface calls
the [IDXGIKeyedMutex::ReleaseSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-releasesync) method using the same value. This value can be any UINT64 value.

### `dwMilliseconds`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The time-out interval, in milliseconds. This method will return if the interval elapses, and the keyed mutex has not been released using the specified *Key*.
If this value is set to zero, the **AcquireSync** method will test to see if the keyed mutex has been released and returns immediately.
If this value is set to INFINITE, the time-out interval will never elapse.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Return S_OK if successful.

If the owning device attempted to create another keyed mutex on the same shared resource, **AcquireSync** returns E_FAIL.

**AcquireSync** can also return the following [DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) constants. Therefore, you should explicitly check for these constants. If you only use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) macro on the return value to determine if **AcquireSync** succeeded, you will not catch these constants.

* WAIT_ABANDONED - The shared surface and keyed mutex are no longer in a consistent state.
  If **AcquireSync** returns this value, you should release and recreate both the keyed mutex and the shared surface.
* WAIT_TIMEOUT - The time-out interval elapsed before the specified key was released.

## Remarks

The **AcquireSync** method creates a lock to a surface that is shared between multiple devices, allowing only one device to render to a surface at a time.
This method uses a key to determine which device currently has exclusive access to the surface.

When a surface is created using the **D3D10_RESOURCE_MISC_SHARED_KEYEDMUTEX** value of the [D3D10_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_resource_misc_flag) enumeration,
you must call the **AcquireSync** method before rendering to the surface. You must call the [ReleaseSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-releasesync) method when you are done
rendering to a surface.

To acquire a reference to the keyed mutex object of a shared resource, call the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method of the resource and pass in
the **UUID** of the [IDXGIKeyedMutex](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgikeyedmutex) interface. For more information about acquiring this reference, see the following code example.

The **AcquireSync** method uses the key as follows, depending on the state of the surface:

* On initial creation, the surface is unowned and any device can call the **AcquireSync** method to gain access.
  For an unowned device, only a key of 0 will succeed. Calling the **AcquireSync** method for any other key will stall the
  calling CPU thread.
* If the surface is owned by a device when you call the **AcquireSync** method, the CPU thread that called
  the **AcquireSync** method will stall until the owning device calls the [ReleaseSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-releasesync) method
  using the same Key.
* If the surface is unowned when you call the **AcquireSync** method (for example, the last owning device has already called
  the [ReleaseSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-releasesync) method), the **AcquireSync** method will succeed if you specify the same key
  that was specified when the **ReleaseSync** method was last called. Calling the **AcquireSync**
  method using any other key will cause a stall.
* When the owning device calls the [ReleaseSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-releasesync) method with a particular key, and more than one device is waiting after
  calling the **AcquireSync** method using the same key, any one of the waiting devices could be woken up first.
  The order in which devices are woken up is undefined.
* A keyed mutex does not support recursive calls to the **AcquireSync** method.

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

[IDXGIKeyedMutex::ReleaseSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-releasesync)