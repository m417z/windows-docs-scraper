# IDirectManipulationManager3::GetService

## Description

Retrieves an [IDirectManipulationDeferContactService](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdefercontactservice) object.

## Parameters

### `clsid` [in]

 The [IDirectManipulationDeferContactService](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdefercontactservice) CLSID.

### `riid` [in]

The IID of the [IDirectManipulationDeferContactService](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdefercontactservice) to retrieve.

### `object` [out, retval]

The [IDirectManipulationDeferContactService](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdefercontactservice) object.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDirectManipulationManager3](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationmanager3)