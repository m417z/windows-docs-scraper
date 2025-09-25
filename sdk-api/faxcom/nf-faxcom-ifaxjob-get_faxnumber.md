# IFaxJob::get_FaxNumber

## Description

The **IFaxJob::get_FaxNumber** property is a null-terminated string that contains the fax number to which the fax server will transmit the fax job. The **IFaxJob::get_FaxNumber** property applies only to outgoing fax transmissions.

This property is read-only.

## Parameters

## Remarks

A fax number is only available for faxes that have a [IFaxJob::get_Type](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-type-vb) property equal to **JT_SEND**. If the fax number is not available, the **IFaxJob::get_FaxNumber** property contains an empty string.

**IFaxJob::get_FaxNumber** allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJob::get_Type](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-type-vb)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)