# IDirectWriterLock::WaitForWriteAccess

## Description

The **WaitForWriteAccess** method obtains exclusive write access to a storage object.

## Parameters

### `dwTimeout` [in]

Specifies the time in milliseconds that this method blocks while waiting to obtain exclusive write access to the storage object. If *dwTimeout* is zero, the method does not block waiting for exclusive access for writing. The INFINITE time-out defined in the Platform SDK is allowed for *dwTimeout*.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The caller has successfully obtained exclusive write access to the storage.|
|S_FALSE | This method was called again without an intervening call to IDirectWriterLock::ReleaseWriteAccess.|
|STG_E_INUSE | The specified time-out expired without obtaining exclusive write access.|

## Remarks

When a storage is opened in direct mode (STGM_DIRECT) with the STGM_READWRITE|STGM_SHARE_DENY_WRITE, you can call this method to obtain exclusive write access to the storage.

This method returns immediately if no readers have the storage open. If the storage is still open for reading, this method blocks for the specified *dwTimeout* or until the current readers close the storage.

## See also

[IDirectWriterLock::HaveWriteAccess](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idirectwriterlock-havewriteaccess)

[IDirectWriterLock::ReleaseWriteAccess](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idirectwriterlock-releasewriteaccess)