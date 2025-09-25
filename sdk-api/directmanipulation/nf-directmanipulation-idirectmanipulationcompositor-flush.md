# IDirectManipulationCompositor::Flush

## Description

Commits all pending updates in the compositor to the system for rendering.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method enables [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) to flush any pending changes to its visuals before a system event, such as a process suspension.

## See also

[IDirectManipulationCompositor](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcompositor)