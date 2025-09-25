# IFaxIncomingJob::get_ExtendedStatusCode

## Description

Retrieves the **ExtendedStatusCode** property of a [FaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob) object. The **ExtendedStatusCode** property specifies a code describing the job's extended status.

## Parameters

### `pExtendedStatusCode` [out, retval]

Type: **[FAX_JOB_EXTENDED_STATUS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_extended_status_enum)***

Pointer to a value from the [FAX_JOB_EXTENDED_STATUS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_extended_status_enum) enumeration that specifies the extended job status.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ExtendedStatusCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob-extendedstatuscode)

[IFaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjob)