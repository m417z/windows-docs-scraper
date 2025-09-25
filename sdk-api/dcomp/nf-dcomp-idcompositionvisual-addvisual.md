# IDCompositionVisual::AddVisual

## Description

Adds a new child visual to the children list of this visual.

## Parameters

### `visual` [in]

Type: **[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)***

The child visual to add. This parameter must not be NULL.

### `insertAbove` [in]

Type: **BOOL**

TRUE to place the new child visual in front of the visual specified by the *referenceVisual* parameter, or FALSE to place it behind *referenceVisual*.

### `referenceVisual` [in, optional]

Type: **[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)***

The existing child visual next to which the new visual should be added.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

Child visuals are arranged in an ordered list. The contents of a child visual are drawn in front of (or above) the contents of its parent visual, but behind (or below) the contents of its children.

The *referenceVisual* parameter must be an existing child of the parent visual, or it must be NULL. The *insertAbove* parameter indicates whether the new child should be rendered immediately above the reference visual in the Z order, or immediately below it.

If the *referenceVisual* parameter is NULL, the specified visual is rendered above or below all children of the parent visual, depending on the value of the *insertAbove* parameter. If *insertAbove* is TRUE, the new child visual is above no sibling, therefore it is rendered below all of its siblings. Conversely, if *insertAbove* is FALSE, the visual is below no sibling, therefore it is rendered above all of its siblings.

The visual specified by the *visual* parameter cannot be either a child of a single other visual, or the root of a visual tree that is associated with a composition target. If *visual* is already a child of another visual, **AddVisual** fails. The child visual must be removed from the children list of its previous parent before adding it to the children list of the new parent. If *visual* is the root of a visual tree, the visual must be dissociated from that visual tree before adding it to the children list of the new parent. To dissociate the visual from a visual tree, call the [IDCompositionTarget::SetRoot](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiontarget-setroot) method and specify either a different visual or NULL as the *visual* parameter.

A child visual need not have been created by the same [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) interface as its parent. When visuals from different devices are combined in the same visual tree, Microsoft DirectComposition composes the tree as it normally would, except that changes to a particular visual take effect only when [IDCompositionDevice::Commit](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-commit) is called on the device object that created the visual. The ability to combine visuals from different devices enables multiple threads to create and manipulate a single visual tree while maintaining independent devices that can be used to commit changes asynchronously

This method fails if *visual* or *referenceVisual* is an invalid pointer, or if the visual referenced by the *referenceVisual* parameter is not a child of the parent visual. These interfaces cannot be custom implementations; only interfaces created by DirectComposition can be used with this method.

#### Examples

For an example, see [How to Build a Simple Visual Tree](https://learn.microsoft.com/windows/desktop/directcomp/how-to--build-a-visual-tree).

## See also

[IDCompositionDevice::CreateVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createvisual)

[IDCompositionTarget::SetRoot](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiontarget-setroot)

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)

[IDCompositionVisual::RemoveAllVisuals](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-removeallvisuals)

[IDCompositionVisual::RemoveVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-removevisual)