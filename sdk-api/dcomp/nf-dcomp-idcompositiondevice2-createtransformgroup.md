# IDCompositionDevice2::CreateTransformGroup

## Description

Creates a 2D transform group object that holds an array of 2D transform objects.

## Parameters

### `transforms` [in]

Type: **[IDCompositionTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontransform)****

An array of 2D transform objects that make up this transform group.

### `elements` [in]

Type: **UINT**

The number of elements in the *transforms* array.

### `transformGroup` [out]

Type: **[IDCompositionTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontransform)****

The new transform group object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The array entries in a transform group cannot be changed. However, each transform in the array can be modified through its own property setting methods. If a transform in the array is modified, the change is reflected in the computed matrix of the transform group.

## See also

[IDCompositionDevice2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice2)

[IDCompositionVisual::SetTransform](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449178(v=vs.85))