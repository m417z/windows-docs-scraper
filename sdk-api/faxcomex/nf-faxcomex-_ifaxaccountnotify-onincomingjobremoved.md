# _IFaxAccountNotify::OnIncomingJobRemoved

## Description

Called by the fax service when an incoming fax job is removed from the job queue of a particular fax account.

## Parameters

### `pFaxAccount` [in]

Type: **[IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount)***

An [IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount) object.

### `bstrJobId` [in]

Type: **BSTR**

A null-terminated string that contains the ID of the job removed from the job queue.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To implement this functionality in Visual Basic, select and implement the appropriate event procedure.

## See also

[IFaxAccountNotify](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxaccountnotify)