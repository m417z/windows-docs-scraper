# IDirectWriterLock::HaveWriteAccess

## Description

The **HaveWriteAccess** method indicates whether the write lock has been taken.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The storage object is currently locked for write access.|
|S_FALSE | The storage object is not currently locked for write access.|

## See also

[IDirectWriterLock::ReleaseWriteAccess](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idirectwriterlock-releasewriteaccess)

[IDirectWriterLock::WaitForWriteAccess](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idirectwriterlock-waitforwriteaccess)