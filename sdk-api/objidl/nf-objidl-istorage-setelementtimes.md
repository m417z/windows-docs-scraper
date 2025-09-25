# IStorage::SetElementTimes

## Description

The **SetElementTimes** method sets the modification, access, and creation times of the specified storage element, if the underlying file system supports this method.

## Parameters

### `pwcsName` [in]

The name of the storage object element whose times are to be modified. If **NULL**, the time is set on the root storage rather than one of its elements.

### `pctime` [in]

Either the new creation time for the element or **NULL** if the creation time is not to be modified.

### `patime` [in]

Either the new access time for the element or **NULL** if the access time is not to be modified.

### `pmtime` [in]

Either the new modification time for the element or **NULL** if the modification time is not to be modified.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The time values were successfully set.|
|E_PENDING | Asynchronous Storage only: Part or all of the element's data is currently unavailable.|
|STG_E_ACCESSDENIED | The caller does not have enough permissions for changing the element.|
|STG_E_FILENOTFOUND | The element with the specified name does not exist.|
|STG_E_INSUFFICIENTMEMORY | The element was not changed due to a lack of memory.|
|STG_E_INVALIDNAME | Not a valid value for the element name.|
|STG_E_INVALIDPOINTER | The pointer specified for the element was not valid.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|
|STG_E_TOOMANYOPENFILES | The element was not changed because there are too many open files.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

**SetElementTimes** sets time statistics for the specified storage element within this storage object.

Not all file systems support all the time values. This method sets those times that are supported and ignores the rest. Each time-value parameter can be **NULL**; indicating that no modification should occur.

Call the
[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat) method to retrieve these time values.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat)