# IFaxIncomingJob::get_Status

## Description

Retrieves the **Status** property of a [FaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob) object. The **Status** property is a number that indicates the current status of an inbound fax job in the job queue.

## Parameters

### `pStatus` [out, retval]

Type: **[FAX_JOB_STATUS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_status_enum)***

Pointer to a value from the [FAX_JOB_STATUS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_status_enum) enumeration that specifies the current status of an inbound fax job in the job queue.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FAX_JOB_STATUS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_status_enum)

[IFaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjob)

[Status](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob-status)