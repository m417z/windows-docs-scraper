# _IFaxServerNotify2::OnServerActivityChange

## Description

The fax service calls the **IFaxServerNotify2::OnServerActivityChange** method when the fax service activity and status changes.

## Parameters

### `pFaxServer`

Type: **[IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2)***

A [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) object.

### `lIncomingMessages`

Type: **long**

Long value that indicates the total number of incoming fax jobs that the fax service is currently receiving.

### `lRoutingMessages`

Type: **long**

Long value that indicates the total number of incoming fax jobs that the fax service is currently routing.

### `lOutgoingMessages`

Type: **long**

Long value that indicates the total number of incoming fax jobs that the fax service is currently sending.

### `lQueuedMessages`

Type: **long**

Long value that indicates the total number of fax jobs in the fax queue.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To implement this functionality in Visual Basic, select and implement the appropriate event procedure. For an example, see [Registering for Fax Events](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-registering-for-fax-events).

## See also

[IFaxServerNotify2](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxservernotify2)