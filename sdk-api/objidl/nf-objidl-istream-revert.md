# IStream::Revert

## Description

The **Revert** method discards all changes that have been made to a transacted stream since the last
[IStream::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-commit) call. On streams open in direct mode and streams using the COM compound file implementation of **IStream::Revert**, this method has no effect.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The stream was successfully reverted to its previous version.|
|E_PENDING | Asynchronous Storage only: Part or all of the stream's data is currently unavailable. |

## Remarks

The **Revert** method discards changes made to a transacted stream since the last commit operation.

## See also

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)

[IStream::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-commit)