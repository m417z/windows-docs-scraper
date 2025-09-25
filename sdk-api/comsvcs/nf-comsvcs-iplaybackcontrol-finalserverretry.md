# IPlaybackControl::FinalServerRetry

## Description

Informs the server-side Exception_CLSID implementation that all attempts to play back the deferred activation have failed. The message is about to be moved to the final resting queue.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

As the message is about to be moved to the final resting queue, the server object may attempt to record the failure, send a mail message to the administrator, or take client-side compensating action (reversing the effect of an earlier transaction). The server object should make every effort to complete this transaction successfully. Otherwise, manual intervention is required to reprocess the message.

If this method is not successful, the message is moved to the final resting queue.

## See also

[IPlaybackControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iplaybackcontrol)