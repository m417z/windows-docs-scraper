# IFaxJob::get_DeviceStatus

## Description

The **IFaxJob::get_DeviceStatus** property is a null-terminated string that describes the status of the port associated with the fax job.

This property is read-only.

## Parameters

## Remarks

If the job is in the job queue waiting transmission, the fax server has not associated a device with the job. In this instance, **IFaxJob::get_DeviceStatus** is "Unknown".

**IFaxJob::get_DeviceStatus** allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)