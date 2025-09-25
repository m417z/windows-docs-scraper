# IPropertyStorage::DeleteMultiple

## Description

The **DeleteMultiple** method deletes as many of the indicated properties as exist in this property set.

## Parameters

### `cpspec` [in]

The numerical count of properties to be deleted. The value of this parameter can legally be set to zero, however that defeats the purpose of the method as no properties are thereby deleted, regardless of the value set in *rgpspec*.

### `rgpspec` [in]

Properties to be deleted. A mixture of property identifiers and string-named properties is permitted. There may be duplicates, and there is no requirement that properties be specified in any order.

## Return value

This method supports the standard return value E_UNEXPECTED, in addition to the following:

## Remarks

**IPropertyStorage::DeleteMultiple** must delete as many of the indicated properties as are in the current property set. If a deletion of a stream- or storage-valued property occurs while that property is open, the deletion will succeed and place the previously returned
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) or
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer in the reverted state.