## Description

Opens a handle for shared primary surfaces, shared fences, and source presentation handles.

## Parameters

### `NTHandle`

Type: **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

An NT handle for a shared primary surface, shared fence, or source presentation handle.

### `riid`

Type: **REFIID**

A reference to the interface identifier (IID) for the default interface of one of the following Windows Runtime classes. An IID is a **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**.

* [IDisplaySurface](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displaysurface)
* [IDisplayFence](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displayfence)
* [IDisplaySource](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displaysource)

### `ppvObj`

Type: **void\*\***

A pointer to a memory block that receives a pointer to the interface specified by the *riid* argument.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** on success, or a failure code describing the problem on failure.

## Remarks

You can use this method to open any shared fence, but you can open a surface only if it was created as primary. Primary surfaces are surfaces intended to be used directly by the display hardware to scan out. Most typical Direct3D surfaces are not created as primaries unless they were created for use in a swap-chain back buffer. [DisplayDevice.CreatePrimary](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displaydevice.createprimary) always creates a surface as a primary, since it is always intended to be used to scan out.

Opening a source presentation handle is similar to calling [CreateScanoutSource](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displaydevice.createscanoutsource) for the target of the presentation handle, except that it isn't necessary to have created the [DisplayDevice](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displaydevice) from the same [DisplayManager](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displaymanager) that created the handle. This allows fine-grained access control of scanout.

## See also

* [CreateSharedHandle](https://learn.microsoft.com/windows/win32/api/windows.devices.display.core.interop/nf-windows-devices-display-core-interop-idisplaydeviceinterop-createsharedhandle)