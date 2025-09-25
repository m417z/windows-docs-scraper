# IDirectManipulationDeferContactService::DeferContact

## Description

Specifies the amount of time to defer the execution of a call to [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact) for this *pointerId*.

**DeferContact** must be called before [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact).

## Parameters

### `pointerId` [in]

The ID of the pointer.

### `timeout` [in]

The duration of the deferral, in milliseconds. The maximum value is 500.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDirectManipulationDeferContactService](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdefercontactservice)