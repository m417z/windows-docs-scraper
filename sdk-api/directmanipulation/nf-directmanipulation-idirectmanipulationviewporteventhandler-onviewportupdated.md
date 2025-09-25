# IDirectManipulationViewportEventHandler::OnViewportUpdated

## Description

Called after all content in the viewport has been updated.

## Parameters

### `viewport` [in]

The viewport that has been updated.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you have actions that need to be executed once for a viewport update, implement **OnViewportUpdated**. [OnContentUpdated](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewporteventhandler-oncontentupdated) is called once for each content change in the viewport. This can result in multiple **OnContentUpdated** calls.

## See also

[IDirectManipulationViewportEventHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewporteventhandler)