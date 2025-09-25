# IFaxOutgoingJob::Pause

## Description

The **IFaxOutgoingJob::Pause** method pauses the outbound fax job.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use the [IFaxOutgoingJob::Resume](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob-resume-vb) method to resume a fax job after it has been paused.

To use this method, a user must have the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) or **farMANAGE_JOBS** access right. With the **farSUBMIT_LOW** access right, users will be able to use this method only for their own faxes. With the **farMANAGE_JOBS** access right, users will be able to use this method for all faxes on the server.

## See also

[IFaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob)