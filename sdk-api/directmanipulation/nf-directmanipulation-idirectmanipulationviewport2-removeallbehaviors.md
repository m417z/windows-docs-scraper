# IDirectManipulationViewport2::RemoveAllBehaviors

## Description

Removes all behaviors added to the viewport.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**RemoveAllBehaviors** only returns an error if the removal of a behavior from the viewport was unsuccessful. In the event that a specific behavior is not removed successfully, **RemoveAllBehaviors** removes all remaining behaviors.

## See also

[IDirectManipulationViewport2](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport2)