# IComponentTypes::get__NewEnum

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get__NewEnum** enumeration method supports `For...Each` loops in Automation clients.

## Parameters

### `ppNewEnum` [out]

Address of an interface pointer to an **IEnumVARIANT** object that will receive the new collection.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This method is provided to enable scripting and Visual Basic applications to iterate through the collection in a `For...Each` loop. C++ applications should use the [IComponentTypes::EnumComponentTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-icomponenttypes-enumcomponenttypes) method.

The returned **IEnumVARIANT** interface is not thread safe, because it is intended primarily for use by Automation clients. Clients should not call methods on the interface from more than one thread.

## See also

[IComponentTypes Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttypes)