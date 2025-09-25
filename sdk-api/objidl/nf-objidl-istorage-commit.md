# IStorage::Commit

## Description

The **Commit** method ensures that any changes made to a storage object open in transacted mode are reflected in the parent storage. For nonroot storage objects in direct mode, this method has no effect. For a root storage, it reflects the changes in the actual device; for example, a file on disk. For a root storage object opened in direct mode, always call the **IStorage::Commit** method prior to [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). **IStorage::Commit** flushes all memory buffers to the disk for a root storage in direct mode and will return an error code upon failure. Although **Release** also flushes memory buffers to disk, it has no capacity to return any error codes upon failure. Therefore, calling **Release** without first calling
**Commit** causes indeterminate results.

## Parameters

### `grfCommitFlags` [in]

Controls how the changes are committed to the storage object. See the
[STGC](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-stgc) enumeration for a definition of these values.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | Changes to the storage object were successfully committed to the parent level. If STGC_CONSOLIDATE was specified, the storage was successfully consolidated, or the storage was already too compact to consolidate further.|
|STG_S_MULTIPLEOPENS | The commit operation succeeded, but the storage could not be consolidated because it had been opened multiple times using the STGM_NOSNAPSHOT flag.|
|STG_S_CANNOTCONSOLIDATE | The commit operation succeeded, but the storage could not be consolidated due to an incorrect storage mode. For compound files, the storage may have been opened using the STGM_NOSCRATCH flag, or the storage may not be the outermost transacted level.|
|STG_S_CONSOLIDATIONFAILED | The commit operation succeeded, but the storage could not be consolidated due to an internal error (for example, a memory allocation failure).|
|E_PENDING | Asynchronous storage only: Part or all of the data to be committed is currently unavailable.|
|STG_E_INVALIDFLAG | The value for the *grfCommitFlags* parameter is not valid.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|
|STG_E_NOTCURRENT | Another open instance of the storage object has committed changes. As a result, the current commit operation may overwrite previous changes.|
|STG_E_MEDIUMFULL | No space left on device to commit.|
|STG_E_TOOMANYOPENFILES | The commit operation could not be completed because there are too many open files.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

**IStorage::Commit** makes permanent changes to a storage object that is in transacted mode, in which changes are accumulated in a buffer, and not reflected in the storage object until there is a call to this method. The alternative is to open an object in direct mode, in which changes are immediately reflected in the storage object. An object opened in the direct mode does not require calling **IStorage::Commit** to make permanent changes in the storage object. Calling the **IStorage::Commit** method on a nonroot storage opened in direct mode has no effect. Opening a root storage object in direct mode ensures that changes in memory buffers are written to the underlying storage device.

The commit operation publishes the current changes in this storage object and its children to the next level up in the storage hierarchy. To undo current changes before committing them, call [IStorage::Revert](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-revert) to roll back to the last-committed version.

Calling **IStorage::Commit** has no effect on currently opened nested elements of this storage object. They remain valid and can be used. However, the **IStorage::Commit** method does not automatically commit changes to these nested elements. The commit operation publishes only known changes to the next higher level in the storage hierarchy. Thus, transactions to nested levels must be committed to this storage object before they can be committed to higher levels.

In commit operations, you need to take steps to ensure that data is protected during the commit process:

* When committing changes to root storage objects, the caller must check the return value to determine whether the operation has been completed successfully, and if not, that the old committed contents of the
  [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) are still intact and can be restored.
* If this storage object was opened with some of its items excluded, the caller is responsible for rewriting them before calling commit. Write mode is required on the storage opening for the commit to succeed.
* Unless prohibiting multiple simultaneous writers on the same storage object, an application calling this method should specify at least STGC_ONLYIFCURRENT in the *grfCommitFlags* parameter to prevent the changes made by one writer from inadvertently overwriting the changes made by another.

If the STGC_CONSOLIDATE flag is not supported by a storage implementation, calling **IStorage::Commit** with STGC_CONSOLIDATE specified in the *grfCommitFlags* parameter returns the value STG_E_INVALIDFLAG.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::Revert](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-revert)

[STGC](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-stgc)