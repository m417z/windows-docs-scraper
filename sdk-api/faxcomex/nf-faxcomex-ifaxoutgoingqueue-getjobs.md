# IFaxOutgoingQueue::GetJobs

## Description

The **IFaxOutgoingQueue::GetJobs** method returns a collection of the outbound fax jobs in the job queue.

## Parameters

### `pFaxOutgoingJobs` [out, retval]

Type: **[FaxOutgoingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjobs)****

A [FaxOutgoingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjobs) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) or [farQUERY_JOBS](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

With the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right, users can use this method only for their own faxes. With the [farQUERY_JOBS](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right, users can use this method for all faxes on the server.

## See also

[FaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingqueue)

[IFaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingqueue)

[Managing Outgoing Jobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outgoing-jobs)