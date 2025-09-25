# IEnumOleUndoUnits::Clone

## Description

Creates a new enumerator that contains the same enumeration state as the current one.

This method makes it possible to record a particular point in the enumeration sequence and then return to that point at a later time. The caller must release this new enumerator separately from the first enumerator.

## Parameters

### `ppEnum` [out]

A pointer to the [IEnumOleUndoUnits](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumoleundounits) interface pointer on the newly created enumerator. The caller must release this enumerator separately from the one from which it was cloned.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_INVALIDARG** | The specified enumerator is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory available for this operation. |

## See also

[IEnumOleUndoUnits](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumoleundounits)