# IFaxJob::get_DisplayName

## Description

The **IFaxJob::get_DisplayName** property is a null-terminated string that contains the user-friendly name to associate with the fax job.

This property is read-only.

## Parameters

## Remarks

You can use the [IFaxJob::get_JobId](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-jobid-vb) property to uniquely identify a fax job because it is possible for multiple fax jobs to have the same **IFaxJob::get_DisplayName** property.

**IFaxJob::get_DisplayName** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJob::get_JobId](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-jobid-vb)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)