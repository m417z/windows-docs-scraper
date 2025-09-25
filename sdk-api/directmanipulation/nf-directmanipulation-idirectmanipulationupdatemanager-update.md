# IDirectManipulationUpdateManager::Update

## Description

Updates [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) at the current time.

## Parameters

### `frameInfo` [in, optional]

The frame info provider used to predict the position of the content and compensate for latency during composition.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the application provides its own implementation of [IDirectManipulationCompositor](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcompositor), this implementation should call **Update** whenever there is a compositor update. Frame timing information can be provided to [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) through the [IDirectManipulationFrameInfoProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationframeinfoprovider) interface.

## See also

[IDirectManipulationUpdateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationupdatemanager)