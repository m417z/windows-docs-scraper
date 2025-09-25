# IDirectManipulationViewport::ReleaseContact

## Description

Removes a contact that is associated with a viewport.

## Parameters

### `pointerId` [in]

The ID of the pointer.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method releases a contact from a specific [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) viewport (equivalent to the user removing a touch point).

The viewport state is not affected unless the last remaining contact on the viewport is removed, in which case the viewport will transition to inertia, if supported.

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)