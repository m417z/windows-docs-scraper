# IFaxJob::get_PageCount

## Description

The **IFaxJob::get_PageCount** property is a number that represents the total number of pages in a fax transmission. The **IFaxJob::get_PageCount** property applies only to outgoing fax transmissions.

This property is read-only.

## Parameters

## Remarks

The total page count is only available for faxes where [IFaxJob::get_Type](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-type-vb) returns JT_SEND. If the page count is not available, **IFaxJob::get_PageCount** returns zero.

The total page count is only available for faxes that have a [IFaxJob::get_Type](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-type-vb) property equal to JT_SEND. If the page count is not available, the **IFaxJob::get_PageCount** property is zero.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJob::get_Type](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxjob-get-type-vb)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)