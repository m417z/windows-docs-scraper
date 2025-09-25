# IFaxOutgoingJob::Cancel

## Description

The **IFaxOutgoingJob::Cancel** method cancels the outbound fax job.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When you cancel a job that is not part of a broadcast or when you cancel an entire broadcast, the [Count](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjobs-count-vb) property is updated to reflect the change in the number of outgoing jobs. However, if you cancel a single fax from a broadcast, the **Count** property does not reflect the change. The canceled fax remains in the outgoing queue, so that you can view the status of all faxes from the broadcast.

To use this method, a user must have the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) or **farMANAGE_JOBS** access right. With the **farSUBMIT_LOW** access right, users will be able to use this method only for their own faxes. With the **farMANAGE_JOBS** access right, users will be able to use this method for all faxes on the server.

## See also

[FaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob)

[IFaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outgoing-jobs)