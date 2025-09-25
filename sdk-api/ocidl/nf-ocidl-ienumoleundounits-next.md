# IEnumOleUndoUnits::Next

## Description

Retrieves the specified number of items in the enumeration sequence.

## Parameters

### `cElt` [in]

The number of items to be retrieved. If there are fewer than the requested number of items left in the sequence, this method retrieves the remaining elements.

### `rgElt` [out]

An array of enumerated items.

The enumerator is responsible for calling [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), and the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) through each pointer enumerated. If *cElt* is greater than 1, the caller must also pass a non-NULL pointer passed to *pcEltFetched* to know how many pointers to release.

### `pcEltFetched` [out]

The number of items that were retrieved. This parameter is always less than or equal to the number of items requested.

## Return value

If the method retrieves the number of items requested, the return value is S_OK. Otherwise, it is S_FALSE.

## Remarks

The caller is responsible for calling the Release method for each element in the array once this method returns successfully. If cUndoUnits is greater than one, the caller must also pass a non-NULL pointer to pcFetched to get the number of pointers it has to release.

E_NOTIMPL is not allowed as a return value. If an error value is returned, no entries in the rgpcd array are valid on exit and require no release.

## See also

[IEnumOleUndoUnits](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumoleundounits)

[IOleUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundounit)