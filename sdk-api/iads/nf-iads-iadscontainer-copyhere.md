# IADsContainer::CopyHere

## Description

The **IADsContainer::CopyHere** method creates a copy of the specified directory object in this container.

## Parameters

### `SourceName` [in]

The ADsPath of the object to copy.

### `NewName` [in]

Optional name of the new object within the container. If a new name is not specified for the object, set to **NULL**; the new object will have the same name as the source object.

### `ppObject` [out]

Indirect pointer to the [IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads) interface on the copied object.

## Return value

This method supports the standard return values, including **S_OK** for a successful operation. For more information and error code information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The destination container must be in the same directory service as the source container. An object cannot be copied across a directory service implementation.

The providers supplied with ADSI return the **E_NOTIMPL** error message.

## See also

[IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

[IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer)

[IADsContainer::MoveHere](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscontainer-movehere)