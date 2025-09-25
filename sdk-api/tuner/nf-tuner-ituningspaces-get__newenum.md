# ITuningSpaces::get__NewEnum

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get__NewEnum** method returns an enumerator for the collection.

This method is provided to enable scripting and Visual Basic applications to iterate through the collection in a `For...Each` loop. C++ applications should use the [ITuningSpaces::get_EnumTuningSpaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspaces-get_enumtuningspaces) method.

## Parameters

### `NewEnum` [out]

Pointer to a variable that receives an **IEnumVARIANT** interface pointer. The caller must release the interface.

## Return value

Returns S_OK if successful.

## Remarks

The returned **IEnumVARIANT** interface is not thread safe, because it is intended primarily for use by Automation clients. Clients should not call methods on the interface from more than one thread.

## See also

[ITuningSpaces Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspaces)