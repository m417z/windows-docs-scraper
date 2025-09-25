# IPlaybackControl::FinalClientRetry

## Description

Informs the client-side exception handling component that all Message Queuing attempts to deliver the message to the server were rejected. The message ended up on the client-side Xact dead letter queue.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

As messages arrive on the Xact dead letter queue, COM+ attempts to invoke a client-side exception handler related to the server class to deliver this notification. This exception object might take exceptional action, such as recording the failure, sending a mail message to the administrator, or taking client-side compensating action (reversing the effect of an earlier transaction).

If this method is not successful, the message is left on the Xact dead letter queue.

## See also

[IPlaybackControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iplaybackcontrol)