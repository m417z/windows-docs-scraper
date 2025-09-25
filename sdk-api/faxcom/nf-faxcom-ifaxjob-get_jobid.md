# IFaxJob::get_JobId

## Description

The **IFaxJob::get_JobId** property is a number that uniquely identifies the specified fax job.

This property is read-only.

## Parameters

## Remarks

You can use the **IFaxJob::get_JobId** property to uniquely identify a fax job because it is possible for multiple fax jobs to have the same [IFaxJob::get_DisplayName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-displayname-vb) property. Note that the fax job identifier can be different from the identifier of a fax print job.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJob::get_DisplayName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-displayname-vb)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)