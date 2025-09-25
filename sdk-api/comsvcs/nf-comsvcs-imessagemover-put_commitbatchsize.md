# IMessageMover::put_CommitBatchSize

## Description

Sets the commit batch size. This is the number of messages that should be moved from source to destination queue between commit operations.

## Parameters

### `newVal` [in]

The commit batch size.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IMessageMover](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imessagemover)