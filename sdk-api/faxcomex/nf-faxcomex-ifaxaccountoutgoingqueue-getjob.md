# IFaxAccountOutgoingQueue::GetJob

## Description

Returns an outgoing fax job in the job queue of the current fax account according to the job's ID.

## Parameters

### `bstrJobId` [in]

Type: **BSTR**

Specifies the job ID.

### `pFaxOutgoingJob` [out, retval]

Type: **[IFaxOutgoingJob2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob2)****

A [FaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FaxAccountOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountoutgoingqueue)

[IFaxAccountOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountoutgoingqueue)