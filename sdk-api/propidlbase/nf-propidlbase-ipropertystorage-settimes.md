# IPropertyStorage::SetTimes

## Description

The **SetTimes** method sets the modification, access, and creation times of this property set, if supported by the implementation. Not all implementations support all these time values.

## Parameters

### `pctime` [in]

Pointer to the new creation time for the property set. May be **NULL**, indicating that this time is not to be modified by this call.

### `patime` [in]

Pointer to the new access time for the property set. May be **NULL**, indicating that this time is not to be modified by this call.

### `pmtime` [in]

Pointer to the new modification time for the property set. May be **NULL**, indicating that this time is not to be modified by this call.

## Return value

This method supports the standard return value E_UNEXPECTED, in addition to the following:

## Remarks

Sets the modification, access, and creation times of the current open property set, if supported by the implementation (not all implementations support all these time values). Unsupported time stamps are always reported as zero, enabling the caller to test for support. A call to [IPropertyStorage::Stat](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-stat) supplies (among other data) time-stamp information.

Notice that this functionality is provided as an
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) method on a property-storage object that is already open, in contrast to being provided as a method in
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage). Normally, when the
**SetTimes** method is not explicitly called, the access and modification times are updated as a side effect of reading and writing the property set. When
**SetTimes** is used, the latest specified times supersede either default times or time values specified in previous calls to
**SetTimes**.

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IPropertyStorage::Stat](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-stat)