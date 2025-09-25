# ILockBytes::Flush

## Description

The
**Flush** method ensures that any internal buffers maintained by the
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) implementation are written out to the underlying physical storage.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The flush operation was successful.|
|STG_E_ACCESSDENIED | The caller does not have permission to access the byte array.|
|STG_E_MEDIUMFULL | The flush operation is not completed because there is no space left on the storage device.|
|E_FAIL | General failure writing data.|
|STG_E_TOOMANYFILESOPEN | Under certain circumstances, the **Flush** method executes a download-and-closeto flush, which can lead to a return value of STG_E_TOOMANYFILESOPEN if no file handles are available.|
|STG_E_INVALIDHANDLE | An underlying file has been prematurely closed, or the correct floppy disk has been replaced by an invalid one.|

## Remarks

**ILockBytes::Flush** flushes internal buffers to the underlying storage device.

The COM-provided implementation of compound files calls this method during a transacted commit operation to provide a two-phase commit process that protects against loss of data.

## See also

[ILockBytes - File-Based Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-file-based-implementation)

[ILockBytes - Global Memory Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-global-memory-implementation)

[IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit)