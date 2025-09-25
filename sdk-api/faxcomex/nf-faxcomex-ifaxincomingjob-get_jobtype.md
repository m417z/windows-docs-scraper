# IFaxIncomingJob::get_JobType

## Description

Retrieves the **JobType** property of a [FaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob) object. The [JobType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob-jobtype) property describes the type of fax job; for example, the job can be a receive job, a send job, or a routing job.

## Parameters

### `pJobType` [out, retval]

Type: **[FAX_JOB_TYPE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_type_enum)***

Pointer to a value from the [FAX_JOB_TYPE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_type_enum) enumeration that specifies the fax job type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjob)

[JobType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob-jobtype)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-incoming-queue)