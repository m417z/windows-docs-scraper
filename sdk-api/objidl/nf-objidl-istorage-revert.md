# IStorage::Revert

## Description

The **Revert** method discards all changes that have been made to the storage object since the last commit operation.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The revert operation was successful.|
|E_PENDING | Asynchronous Storage only: Part or all of the storage's data is currently unavailable. |
|STG_E_INSUFFICIENTMEMORY | The revert operation could not be completed due to a lack of memory.|
|STG_E_TOOMANYOPENFILES | The revert operation could not be completed because there are too many open files.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

For storage objects opened in transacted mode, the **IStorage::Revert** method discards any uncommitted changes to this storage object or changes that have been committed to this storage object from nested elements.

After this method returns, any existing elements (substorages or streams) that were opened from the reverted storage object are invalid and can no longer be used. Specifying these reverted elements in any call except [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) returns the error STG_E_REVERTED

This method has no effect on storage objects opened in direct mode.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit)