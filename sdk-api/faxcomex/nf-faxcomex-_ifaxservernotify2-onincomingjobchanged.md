# _IFaxServerNotify2::OnIncomingJobChanged

## Description

The fax service calls the **IFaxServerNotify2::OnIncomingJobChanged** method when the status of an incoming fax job changes.

## Parameters

### `pFaxServer`

Type: **[IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2)***

A [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) object.

### `bstrJobId`

Type: **BSTR**

Null-terminated string that contains the ID of the job for which the status has changed.

### `pJobStatus`

Type: **[IFaxJobStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxjobstatus)***

A [FaxJobStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjobstatus) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To implement this functionality in Visual Basic, select and implement the appropriate event procedure. For an example, see [Registering for Fax Events](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-registering-for-fax-events).

## See also

[IFaxServerNotify2](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxservernotify2)