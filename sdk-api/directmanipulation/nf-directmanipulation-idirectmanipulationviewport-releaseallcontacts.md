# IDirectManipulationViewport::ReleaseAllContacts

## Description

Removes all contacts that are associated with the viewport. Inertia is started if the viewport supports inertia.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is equivalent to calling [ReleaseContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-releasecontact) on every contact associated with the viewport. The outcome is equivalent to the user removing all touch points from the viewport.

If supported, inertia will be started after calling this method.

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)