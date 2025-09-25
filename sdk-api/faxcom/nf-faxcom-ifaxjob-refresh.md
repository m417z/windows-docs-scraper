# IFaxJob::Refresh

## Description

The **IFaxJob::Refresh** method updates [FaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjob) object information for the associated fax job.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call the **IFaxJob::Refresh** method to poll the fax service for new information about a specified fax job. After you successfully call **IFaxJob::Refresh**, you must call the appropriate [IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob) interface method to retrieve new attribute values that are valid.

It is recommended that you limit calls to this method because frequent calls to **IFaxJob::Refresh** can degrade system performance.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)