# IFaxOutgoingJob::Restart

## Description

The **IFaxOutgoingJob::Restart** method restarts the failed outbound fax job. For example, if the fax job has exceeded the number of retries, **IFaxOutgoingJob::Restart** will restart the fax job.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) or **farMANAGE_JOBS** access right. With the **farSUBMIT_LOW** access right, users will be able to use this method only for their own faxes. With the **farMANAGE_JOBS** access right, users will be able to use this method for all faxes on the server.

## See also

[FaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob)

[IFaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outgoing-jobs)