# IDirectManipulationViewport::GetPrimaryContent

## Description

Gets the primary content of a viewport that implements [IDirectManipulationContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcontent) and [IDirectManipulationPrimaryContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationprimarycontent).

Primary content is an element that gets transformed (e.g. moved, scaled, rotated) in response to a user interaction. Primary content is created at the same time as the viewport and cannot be added or removed.

## Parameters

### `riid` [in]

IID to the interface.

### `object` [out, retval]

The primary content object.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 This method gets the content of the viewport that implements [IDirectManipulationContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcontent) and [IDirectManipulationPrimaryContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationprimarycontent).

#### Examples

The following example shows how to use this method.

```
IDirectManipulationPrimaryContent *pContent;

HRESULT hr = pRegion->GetPrimaryContent(IID_PPV_ARGS(&pContent));

```

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)