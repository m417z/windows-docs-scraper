# IPropertyStorage::Stat

## Description

The **Stat** method retrieves information about the current open property set.

## Parameters

### `pstatpsstg` [out]

Pointer to a
[STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structure, which contains statistics about the current open property set.

## Return value

This method supports the standard return value E_UNEXPECTED, in addition to the following:

## Remarks

**IPropertyStorage::Stat** fills in and returns a pointer to a
[STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structure, containing statistics about the current property set.

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[IPropertySetStorage::Enum](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-enum)

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg)