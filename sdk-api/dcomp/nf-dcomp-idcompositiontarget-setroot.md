# IDCompositionTarget::SetRoot

## Description

Sets a visual object as the new root object of a visual tree.

## Parameters

### `visual` [in, optional]

Type: **[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)***

The visual object that is the new root of this visual tree. This parameter can be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A visual can be either the root of a single visual tree, or a child of another visual, but it cannot be both at the same time. This method fails if the *visual* parameter is already the root of another visual tree, or is a child of another visual.

If *visual* is NULL, the visual tree is empty. If there was a previous non-NULL root visual, that visual becomes available for use as the root of another visual tree, or as a child of another visual.

#### Examples

For an example, see [How to Build a Simple Visual Tree](https://learn.microsoft.com/windows/desktop/directcomp/how-to--build-a-visual-tree).

## See also

[IDCompositionDevice::CreateVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createvisual)

[IDCompositionTarget](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontarget)