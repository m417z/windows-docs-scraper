# IDCompositionVisual::SetTransformParent

## Description

Sets the TransformParent property of this visual. The TransformParent property establishes the coordinate system relative to which this visual is composed.

## Parameters

### `visual` [in, optional]

Type: **[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)***

The new visual that establishes the base coordinate system for this visual. This parameter can be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The coordinate system of a visual is modified by the OffsetX, OffsetY, and Transform properties. Normally, these properties define the coordinate system of a visual relative to its immediate parent. This method specifies the visual relative to which the coordinate system for this visual is based. The specified visual must be an ancestor of the current visual. If it is not an ancestor, the coordinate system is based on this visual's immediate parent, just as if the TransformParent property were set to NULL. Because visuals can be reparented, this property can take effect again if the specified visual becomes an ancestor of the target visual through a reparenting operation.

If the *visual* parameter is NULL, the coordinate system is always transformed relative to the visual's immediate parent. This is the default behavior if this method is not used.

This method fails if the *visual* parameter is an invalid pointer or if it was not created by the same [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) interface as this visual. The interface cannot be a custom implementation; only interfaces created by Microsoft DirectComposition can be used with this method.

## See also

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)