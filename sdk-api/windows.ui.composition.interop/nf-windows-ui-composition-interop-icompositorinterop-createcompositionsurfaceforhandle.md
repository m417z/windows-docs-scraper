# ICompositorInterop::CreateCompositionSurfaceForHandle (windows.ui.composition.interop.h)

## Description

Creates an instance of CompositionSurface for use with the handle of a swapchain. In order to host media swapchain on a CompositionSurface, use the IMFMediaEngineEx::GetVideoSwapchainHandle method.

## Parameters

### `swapChain` [in]

Type: **HANDLE***

The handle of the swap chain to create the CompositionSurface for.

### `result` [out]

Type: **ICompositionSurface****

The created CompositionSurface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## See also

[ICompositorInterop](https://learn.microsoft.com/windows/desktop/api/windows.ui.composition.interop/nn-windows-ui-composition-interop-icompositorinterop)