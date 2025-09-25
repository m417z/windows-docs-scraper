# IADsContainer::Create

## Description

The **IADsContainer::Create** method sets up a request to create a directory object of the specified schema class and a given name in the container. The object is not made persistent until [IADs::SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo) is called on the new object. This allows for setting mandatory properties on the new object.

## Parameters

### `ClassName` [in]

Name of the schema class object to be created. The name is that returned from the [IADs::get_Schema](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads) property method.

### `RelativeName` [in]

Relative name of the object as it is known in the underlying directory and identical to the one retrieved through the [IADs::get_Name](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads) property method.

### `ppObject` [out]

Indirect pointer to the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface on the newly created object.

## Return value

This method supports the standard return values, including S_OK for a successful operation. For more information about error codes, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## See also

[IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer)

[IADsContainer::Delete](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscontainer-delete)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)