# IFaxAccountOutgoingQueue::GetJobs

## Description

Returns the collection of outbound fax jobs in the queue for the current fax account.

## Parameters

### `pFaxOutgoingJobs` [out, retval]

Type: **[IFaxOutgoingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjobs)****

A [FaxOutgoingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjobs) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FaxAccountOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountoutgoingqueue)

[IFaxAccountOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountoutgoingqueue)