# IDCompositionDevice::CreateSurfaceFromHandle

## Description

Creates a new composition surface object that wraps an existing composition surface.

## Parameters

### `handle` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle of an existing composition surface that was created by a call to the [DCompositionCreateSurfaceHandle](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-dcompositioncreatesurfacehandle) function.

### `surface` [out]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsurface)****

The new composition surface object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method enables an application to use a shared composition surface in a composition tree.

## See also

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)

[IDCompositionDevice::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createsurface)

[IDCompositionDevice::CreateSurfaceFromHwnd](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createsurfacefromhwnd)