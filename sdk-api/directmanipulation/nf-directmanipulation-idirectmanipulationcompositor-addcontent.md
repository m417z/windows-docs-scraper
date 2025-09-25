# IDirectManipulationCompositor::AddContent

## Description

Associates content (owned by the caller) with the compositor, assigns a composition device to the content, and specifies the position of the content in the composition tree relative to other composition visuals.

## Parameters

### `content` [in]

The content to add to the composition tree.

*content* is placed between *parentVisual* and *childVisual* in the composition tree.

### `device` [in, optional]

The device used to compose the content.

**Note** *device* is created by the application.

### `parentVisual` [in]

The parent visuals in the composition tree of the content being added.

*parentVisual* must also be a parent of *childVisual* in the composition tree.

### `childVisual` [in]

The child visuals in the composition tree of the content being added.

*parentVisual* must also be a parent of *childVisual* in the composition tree.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method inserts a small visual tree (owned by the [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) device) between the *parentVisual* and the *childVisual*. Transforms can then be applied to the inserted content.

All content, regardless of type, must be added to the compositor. This can be primary content, obtained from the viewport by calling [GetPrimaryContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-getprimarycontent), or secondary content, such as a panning indicator, created by calling [CreateContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationmanager-createcontent).

If the application uses a system-provided [IDirectManipulationCompositor](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcompositor):

* *device* must be an [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) object, and parent and child visuals must be [IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual) objects.
* *device*, *parentVisual*, and *childVisual* cannot be NULL.
* *device*, *parentVisual*, and *childVisual* objects are created and owned by the application.
* When content is added to the composition tree using this method, the new composition visuals are inserted between *parentVisual* and *childVisual*. The new visuals should not be destroyed until they are disassociated from the compositor with [RemoveContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationcompositor-removecontent).

If the application uses a custom implementation of [IDirectManipulationCompositor](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcompositor):

* *device*, *parentVisual*, and *childVisual* must be a valid type for the compositor. They do not have to be [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) or [IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual) objects.
* *device*, *parentVisual*, and *childVisual* can be NULL, depending on the compositor.

## See also

[IDirectManipulationCompositor](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcompositor)