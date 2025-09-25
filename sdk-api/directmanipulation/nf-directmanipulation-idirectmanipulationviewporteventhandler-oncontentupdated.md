# IDirectManipulationViewportEventHandler::OnContentUpdated

## Description

Called when content inside a viewport is updated.

## Parameters

### `viewport` [in]

The viewport that is updated.

### `content` [in]

The content in the viewport that has changed.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called once for each content change in the viewport. This can result in multiple **OnContentUpdated** calls. For instance, when the position of the content is changed, you can use [IDirectManipualtionContent::GetContentTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationcontent-getcontenttransform) to retrieve the new value.

If you have actions that need to be executed once for a viewport update, implement [OnViewportUpdated](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewporteventhandler-onviewportupdated).

## See also

[IDirectManipulationViewportEventHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewporteventhandler)