# IDirectManipulationViewport2::RemoveBehavior

## Description

Removes a behavior from the viewport that matches the given cookie.

## Parameters

### `cookie` [in]

A valid cookie returned from the [AddBehavior](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport2-addbehavior) call on the same viewport.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code. If the behavior has already been removed or if the behavior is not attached to this viewport a failure is returned.

## See also

[IDirectManipulationViewport2](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport2)