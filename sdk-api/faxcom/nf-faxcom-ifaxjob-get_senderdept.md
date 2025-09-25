# IFaxJob::get_SenderDept

## Description

The **IFaxJob::get_SenderDept** property is a null-terminated string that contains the department identifier for the sender of the fax job. The **IFaxJob::get_SenderDept** property applies only to outgoing fax transmissions.

This property is read-only.

## Parameters

## Remarks

If the sender's department is not available, the **IFaxJob::get_SenderDept** property contains an empty string.

The **IFaxJob::get_SenderDept** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)