# IFaxJob::get_SenderName

## Description

The **IFaxJob::get_SenderName** property is a null-terminated string that contains the name of the sender who initiated the fax job. The **IFaxJob::get_SenderName** property applies only to outgoing fax transmissions.

This property is read-only.

## Parameters

## Remarks

If the sender's name is not available, the **IFaxJob::get_SenderName** property contains an empty string.

You can call the [IFaxJob::get_UserName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-username-vb) method to retrieve the name of the account that queued the fax job.

**IFaxJob::get_SenderName** allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJob::get_UserName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-username-vb)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)