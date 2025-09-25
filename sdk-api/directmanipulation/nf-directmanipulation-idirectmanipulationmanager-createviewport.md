# IDirectManipulationManager::CreateViewport

## Description

The factory method that is used to create a new [IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport) object.

The viewport manages the interaction state and mapping of input to output actions.

## Parameters

### `frameInfo` [in, optional]

The frame info provider for the viewport.

### `window` [in]

The handle of the main app window to associate with the viewport.

### `riid` [in]

IID to the interface.

### `object` [out, retval]

The new [IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport) object.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDirectManipulationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationmanager)