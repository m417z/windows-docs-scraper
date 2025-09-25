# IDirectManipulationViewport::AddContent

## Description

Adds secondary content, such as a panning indicator, to a viewport.

## Parameters

### `content` [in]

The content to add to the viewport.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Secondary content is created by calling [CreateContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationmanager-createcontent). Once added, the secondary content will move relative to the primary content in response to a manipulation. Its motion is determined by rules associated with each type of secondary content.

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)