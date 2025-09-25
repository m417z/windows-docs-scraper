# _IFaxServerNotify2::OnQueuesStatusChange

## Description

The fax service calls the **IFaxServerNotify2::OnQueuesStatusChange** method when there is a change in the fax job queue status.

## Parameters

### `pFaxServer`

Type: **[IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2)***

A [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) object.

### `bOutgoingQueueBlocked`

Type: **VARIANT_BOOL**

Specifies a Boolean value that indicates whether the job queue for outgoing faxes is blocked. If this parameter is equal to **TRUE**, the outgoing job queue is blocked and the fax service is not accepting requests for outgoing fax transmissions. If this parameter is equal to **FALSE**, the queue is not blocked.

### `bOutgoingQueuePaused`

Type: **VARIANT_BOOL**

Specifies a Boolean value that indicates whether the job queue for outgoing faxes is paused. If this parameter is equal to **TRUE**, the job queue is paused and the fax service is not processing jobs in the queue. If this parameter is equal to **FALSE**, the outgoing queue is not paused.

### `bIncomingQueueBlocked`

Type: **VARIANT_BOOL**

Specifies a Boolean value that indicates whether the job queue for incoming faxes is blocked. If this parameter is equal to **TRUE**, the inbound job queue is blocked and the fax service is not answering incoming fax calls. If this parameter is equal to **FALSE**, the queue is not blocked.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To implement this functionality in Microsoft Visual Basic, select and implement the appropriate event procedure. For an example, see [Registering for Fax Events](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-registering-for-fax-events).

## See also

[IFaxServerNotify2](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxservernotify2)