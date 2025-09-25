# IDirectManipulationViewport::Stop

## Description

 Stops the manipulation and returns the viewport to a ready state.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If a mandatory snap point has been configured, the content may animate to the nearest snap point.

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)