# IStorage::SetClass

## Description

The **SetClass** method assigns the specified class identifier (CLSID) to this storage object.

## Parameters

### `clsid` [in]

The CLSID that is to be associated with the storage object.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The CLSID was successfully assigned.|
|E_PENDING | Asynchronous Storage only: Part or all of the storage's data is currently unavailable.|
|STG_E_ACCESSDENIED | The caller does not have enough permissions for assigning a CLSID to the storage object.|
|STG_E_MEDIUMFULL | Not enough space was left on device to complete the operation.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

When first created, a storage object has an associated CLSID of CLSID_NULL. Call **SetClass** to assign a CLSID to the storage object.

Call the
[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat) method to retrieve the current CLSID of a storage object.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat)