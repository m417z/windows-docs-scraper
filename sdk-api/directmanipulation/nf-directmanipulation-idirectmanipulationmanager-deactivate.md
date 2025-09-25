# IDirectManipulationManager::Deactivate

## Description

Deactivates [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) for processing input and handling callbacks on the specified window.

## Parameters

### `window` [in]

The window in which to deactivate input.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The manipulation manager is deactivated by default. The manager does not receive or respond to input until [Activate](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationmanager-activate) is called. The manipulation manager should be deactivated when the app does not receive or respond to input. For example, when the app is minimized.

Calls to [Activate](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationmanager-activate) and **Deactivate** are reference counted.

## See also

[IDirectManipulationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationmanager)