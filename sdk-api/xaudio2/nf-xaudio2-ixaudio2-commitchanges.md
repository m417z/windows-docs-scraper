# IXAudio2::CommitChanges

## Description

Atomically applies a set of operations that are tagged with a given identifier.

## Parameters

### `OperationSet` [in]

Identifier of the set of operations to be applied. To commit all pending operations, pass **XAUDIO2_COMMIT_ALL**.

## Return value

Returns S_OK if successful; returns an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

**CommitChanges** does nothing if no operations are tagged with the given identifier.

See the [XAudio2 Operation Sets](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-operation-sets) overview about working with **CommitChanges** and XAudio2 interface methods that may be deferred.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2)