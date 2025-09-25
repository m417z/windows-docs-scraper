# IDCompositionDesktopDevice::CreateSurfaceFromHandle

## Description

Creates a new composition surface object that wraps an existing composition surface.

## Parameters

### `handle` [in]

The handle of an existing composition surface that was created by a call to the [DCompositionCreateSurfaceHandle](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-dcompositioncreatesurfacehandle) function.

### `surface` [out]

The new composition surface object. This parameter must not be NULL.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## See also

[IDCompositionDesktopDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondesktopdevice)

[IDCompositionVisual::SetContent](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-setcontent)