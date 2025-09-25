# IFaxOutgoingJob::get_ExtendedStatusCode

## Description

The **IFaxOutgoingJob::get_ExtendedStatusCode** property specifies a code describing the job's extended status.

This property is read-only.

## Parameters

## Remarks

If a fax service provider (FSP) provides a proprietary status code, the service loads the code string from the FSP, and passes both the string and the original status code to the client. If the FSP provides a status defined in [FAX_JOB_EXTENDED_STATUS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_extended_status_enum), the service passes only the status code to the client.

A fax client application should check the extended status string first. If the string is not **NULL**/empty, it describes the extended status, and the extended status code is the same code that the FSP passed to the fax service. If the string is **NULL**/Empty, the extended status code is one of those defined in [FAX_JOB_EXTENDED_STATUS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_extended_status_enum).

## See also

[FaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob)

[IFaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outgoing-jobs)