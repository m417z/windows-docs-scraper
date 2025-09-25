# IDirectManipulationDeferContactService::CancelDeferral

## Description

Cancel the deferral set in [DeferContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationdefercontactservice-defercontact) and process the scheduled [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact) call for this *pointerId*.

## Parameters

### `pointerId` [in]

The ID of the pointer.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDirectManipulationDeferContactService](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdefercontactservice)