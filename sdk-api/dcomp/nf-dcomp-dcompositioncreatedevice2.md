# DCompositionCreateDevice2 function

## Description

Creates a new device object that can be used to create other Microsoft DirectComposition objects.

## Parameters

### `renderingDevice` [in, optional]

An optional pointer to a DirectX device to be used to create DirectComposition surface objects. Must be a pointer to an object implementing the [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) or [ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device) interfaces.

### `iid` [in]

The identifier of the interface to retrieve. This must be one of __uuidof(IDCompositionDevice) or __uuidof(IDCompositionDesktopDevice).

### `dcompositionDevice` [out]

Receives an interface pointer to the newly created device object. The pointer is of the type specified by the *iid* parameter. This parameter must not be NULL.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A device object serves as the factory for all other DirectComposition objects. It also controls transactional composition through the IDCompositionDevice2::Commit method.

The *renderingDevice* parameter may point to a [DXGI](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dx-graphics-dxgi), Direct3D, Direct2D device object, or it may be NULL. This parameter affects the behavior of the IDCompositionDevice2::CreateSurface, IDCompositionDevice2::CreateVirtualSurface and IDCompositionSurface::BeginDraw methods.

If the *renderingDevice* parameter is NULL then the returned DirectComposition device cannot directly create DirectComposition surface objects. In particular, IDCompositionDevice2::CreateSurface and IDCompositionDevice2::CreateVirtualSurface methods return E_INVALIDARG, regardless of the supplied parameters. However, such a DirectComposition device object can still be used to indirectly create surfaces if the application creates a surface factory object via the IDCompositionDevice2::CreateSurfaceFactory method.

If the *renderingDevice* parameter points to a DXGI device, that device is used to allocate all video memory needed by the IDCompositionDevice2::CreateSurface and IDCompositionDevice2::CreateVirtualSurface methods. Moreover, the IDCompositionSurface::BeginDraw method returns an interface pointer to a DXGI surface that belongs to that same DXGI device.

If the *renderingDevice* parameter points to a Direct2D device object, DirectComposition extracts from it the underlying DXGI device object and uses it as if that DXGI device object had been passed in as the *renderingDevice* parameter. However, passing in a Direct2D object further causes IDCompositionSurface::BeginDraw to accept __uuidof(ID2D1DeviceContext) for its *iid* parameter for any objects created with the IDCompositionDevice2::CreateSurface or IDCompositionDevice2::CreateVirtualSurface methods. In that case, the Direct2D device context object returned by IDCompositionSurface::BeginDraw will belong to the same Direct2D device passed as the *renderingDevice* parameter.

If the *iid* parameter is __uuidof(IDCompositionDevice), then the dcompositionDevice parameter receives a pointer to a Version 1 IDCompositionDevice interface, but the underlying object is a Version 2 desktop device object. The application can later obtain a pointer to either the IDCompositionDevice2 or IDCompositionDesktopDevice interfaces by calling the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method on that device. Similarly, all DirectComposition objects created from such a device are Version 2 objects under the covers. For example, the IDCompositionDevice::CreateVisual method will return an IDCompositionVisual interface to the created visual, but the application can obtain a pointer to the IDCompositionVisual2 interface via the QueryInterface method. This behavior allows an application written to the DirectComposition V1 API to incrementally adopt DirectComposition V2 features by changing the device creation method from DCompositionCreateDevice to DCompositionCreateDevice2, while still requesting the IDCompositionDevice2 interface. This allows the rest of the code to remain unchanged, while allowing the application to use QueryInterface in just the places where new functionality is needed.

## See also

IDCompositionDesktopDevice

IDCompositionDevice2

IDCompositionDevice2::CreateSurface

IDCompositionDevice2::CreateSurfaceFactory

IDCompositionDevice2::CreateVirtualSurface

IDCompositionSurface::BeginDraw