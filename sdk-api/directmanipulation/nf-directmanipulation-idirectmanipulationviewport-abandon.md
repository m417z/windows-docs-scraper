# IDirectManipulationViewport::Abandon

## Description

 Releases all resources that are used by the viewport and prepares it for destruction from memory.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Once **Abandon** has been called, do not make subsequent function calls on the viewport. If a function is called after **Abandon**, **E_INVALID_STATE** will be returned.

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)