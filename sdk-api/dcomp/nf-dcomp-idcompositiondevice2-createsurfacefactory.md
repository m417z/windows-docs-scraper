# IDCompositionDevice2::CreateSurfaceFactory

## Description

Creates a Microsoft DirectComposition surface factory object, which can be used to create other DirectComposition surface or virtual surface objects

## Parameters

### `renderingDevice` [in]

A pointer to a DirectX device to be used to create DirectComposition surface objects. Must be a pointer to an object implementing the [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) or [ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device) interfaces. This parameter must not be NULL.

### `surfaceFactory` [out]

The newly created surface factory object. This parameter must not be NULL.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A surface factory allows an application to simultaneously use more than one single DXGI or Direct2D device with DirectComposition. Each surface factory has a permanent association with one DXGI or Direct2D device, but a DirectComposition device may have any number of surface factories.

Each surface factory manages resources independently from the others. In particular, DirectComposition pools surface allocations to mitigate surface allocation and deallocation costs. This pool is done on a per-surface factory basis.

If the [DCompositionCreateDevice2](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-dcompositioncreatedevice2) function is called with a non-NULL *renderingDevice* parameter, the returned DirectComposition device object has an implicit surface factory under the covers associated with the given rendering device. This implicit surface factory is used to service the [IDCompositionDevice::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createsurface), [IDCompositionDevice::CreateVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createvirtualsurface), [IDCompositionDevice2::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-createsurface) and [IDCompositionDevice2::CreateVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-createvirtualsurface) methods.

A surface object remains alive as long as any of the surfaces or virtual surfaces that it created remain alive, either directly because the application holds a direct reference, or indirectly because one or more such surfaces are associated with one or more visual objects.

## See also

[IDCompositionDevice2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice2)

[IDCompositionDevice2::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-createsurface)

[IDCompositionDevice2::CreateVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-createvirtualsurface)