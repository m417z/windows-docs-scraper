# IPropertyStorage::Revert

## Description

The **Revert** method discards all changes to the named property set since it was last opened or discards changes that were last committed to the property set. This method has no effect on a direct-mode property set.

## Return value

This method supports the standard return value E_UNEXPECTED, in addition to the following:

## Remarks

For transacted-mode property sets, this method discards all changes that have been made in this property set since the set was opened or since the time it was last committed, (whichever is later). After this operation, any existing storage- or stream-valued properties that have been opened from the property set being reverted are no longer valid and cannot be used. The error STG_E_REVERTED will be returned on all calls, except those to **Release**, using these streams or storages.

For direct-mode property sets, this request is ignored and returns S_OK.

## See also

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IPropertyStorage::Commit](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-commit)