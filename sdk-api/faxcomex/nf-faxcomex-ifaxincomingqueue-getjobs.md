# IFaxIncomingQueue::GetJobs

## Description

The **GetJobs** method returns the collection of inbound fax jobs in the queue.

## Parameters

### `pFaxIncomingJobs` [out, retval]

Type: **[IFaxIncomingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjobs)****

A [FaxIncomingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjobs) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farQUERY_JOBS](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) and [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access rights.

## See also

[FaxIncomingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingqueue)

[IFaxIncomingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingqueue)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-incoming-queue)