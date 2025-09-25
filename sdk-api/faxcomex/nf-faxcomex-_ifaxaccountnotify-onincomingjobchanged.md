# _IFaxAccountNotify::OnIncomingJobChanged

## Description

Called by the fax service when the status of an incoming fax job for a particular fax account changes.

## Parameters

### `pFaxAccount` [in]

Type: **[IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount)***

An [IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount) object.

### `bstrJobId` [in]

Type: **BSTR**

A null-terminated string that contains the ID of the job for which the status has changed.

### `pJobStatus` [in]

Type: **[IFaxJobStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxjobstatus)***

A [FaxJobStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjobstatus) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To implement this functionality in Visual Basic, select and implement the appropriate event procedure.

## See also

[IFaxAccountNotify](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxaccountnotify)