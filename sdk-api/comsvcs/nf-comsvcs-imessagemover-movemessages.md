# IMessageMover::MoveMessages

## Description

Moves all messages from the source queue to the destination queue.

## Parameters

### `plMessagesMoved` [out]

The number of messages that were moved from the source to the destination queue.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Messages are moved one at a time unless both the source and destination queue are transacted. In this case, [CommitBatchSize](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-imessagemover-get_commitbatchsize) specifies the number of messages that are moved before [Commit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-itransactioncontext-commit) is invoked. There is no provision for moving fewer than all of the messages on the queue.

## See also

[IMessageMover](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imessagemover)