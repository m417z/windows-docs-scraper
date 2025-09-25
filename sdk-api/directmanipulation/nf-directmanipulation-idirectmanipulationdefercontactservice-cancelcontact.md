# IDirectManipulationDeferContactService::CancelContact

## Description

Cancel all scheduled calls to [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact) for this *pointerId*.

## Parameters

### `pointerId` [in]

The ID of the pointer.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function fails if the timeout specified in [DeferContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationdefercontactservice-defercontact) has already been reached.

## See also

[IDirectManipulationDeferContactService](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdefercontactservice)