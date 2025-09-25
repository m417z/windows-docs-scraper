# IFaxOutgoingJob::get_ExtendedStatus

## Description

The **IFaxOutgoingJob::get_ExtendedStatus** property is a null-terminated string that describes the job's extended status.

This property is read-only.

## Parameters

## Remarks

The **IFaxOutgoingJob::get_ExtendedStatus** property can have a value only if the fax service provider (FSP) returns a proprietary status code in the [IFaxOutgoingJob::get_ExtendedStatusCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob-extendedstatuscode-vb) property. Otherwise, the **IFaxOutgoingJob::get_ExtendedStatus** property will contain an empty string. Similarly, an FSP may choose not to provide values for the **IFaxOutgoingJob::get_ExtendedStatus** property, and the property will thus contain an empty string. This is the case for the T.30 FSP provided with the fax service.

If an FSP provides a proprietary status code, the service loads the code string from the FSP, and passes both the string and the original status code to the client. If the FSP provides a status defined in [FAX_JOB_EXTENDED_STATUS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_extended_status_enum), the service passes only the status code to the client.

A fax client application should check the extended status string first. If the string is not **NULL**/empty, it describes the extended status, and the extended status code is the same code that the FSP passed to the fax service. If the string is **NULL**/empty, the extended status code is one of those defined in [FAX_JOB_EXTENDED_STATUS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_extended_status_enum).

## See also

[FaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob)

[IFaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outgoing-jobs)