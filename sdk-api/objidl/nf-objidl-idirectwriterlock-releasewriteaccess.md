# IDirectWriterLock::ReleaseWriteAccess

## Description

The **ReleaseWriteAccess** method releases the write lock previously obtained.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The write lock was successfully released.|

## Remarks

The writer calls this method to release exclusive access to the storage object previously taken by calling [IDirectWriterLock::WaitForWriteAccess](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idirectwriterlock-waitforwriteaccess).

After the writer calls this method, it is safe to allow readers to reopen the storage again until the next call to [IDirectWriterLock::WaitForWriteAccess](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idirectwriterlock-waitforwriteaccess).

## See also

[IDirectWriterLock::HaveWriteAccess](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idirectwriterlock-havewriteaccess)

[IDirectWriterLock::WaitForWriteAccess](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idirectwriterlock-waitforwriteaccess)