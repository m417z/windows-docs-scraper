# IEnumExtraSearch::Clone

## Description

Used to request a duplicate of the enumerator object to preserve its current state.

## Parameters

### `ppenum`

Type: **[IEnumExtraSearch](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumextrasearch)****

A pointer to the [IEnumExtraSearch](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumextrasearch) interface of a new enumerator object.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error code otherwise.

## Remarks

The new enumerator should be created with the same state as the current one. Use the [IEnumExtraSearch::Skip](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ienumextrasearch-skip) method to advance the enumeration index to the appropriate value before returning.