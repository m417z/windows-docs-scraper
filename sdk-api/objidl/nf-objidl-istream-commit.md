# IStream::Commit

## Description

The **Commit** method ensures that any changes made to a stream object open in transacted mode are reflected in the parent storage. If the stream object is open in direct mode, **IStream::Commit** has no effect other than flushing all memory buffers to the next-level storage object. The COM compound file implementation of streams does not support opening streams in transacted mode.

## Parameters

### `grfCommitFlags` [in]

Controls how the changes for the stream object are committed. See the
[STGC](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-stgc) enumeration for a definition of these values.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | Changes to the stream object were successfully committed to the parent level.|
|E_PENDING | Asynchronous Storage only: Part or all of the stream's data is currently unavailable. |
|STG_E_MEDIUMFULL | The commit operation failed due to lack of space on the storage device.|
|STG_E_REVERTED | The object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

The **Commit** method ensures that changes to a stream object opened in transacted mode are reflected in the parent storage. Changes that have been made to the stream since it was opened or last committed are reflected to the parent storage object. If the parent is opened in transacted mode, the parent may revert at a later time, rolling back the changes to this stream object. The compound file implementation does not support the opening of streams in transacted mode, so this method has very little effect other than to flush memory buffers. For more information, see
[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation).

If the stream is open in direct mode, this method ensures that any memory buffers have been flushed out to the underlying storage object. This is much like a flush in traditional file systems.

The **IStream::Commit** method is useful on a direct mode stream when the implementation of the
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface is a wrapper for underlying file system APIs. In this case, **IStream::Commit** would be connected to the file system's flush call.

## See also

[IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit)

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)