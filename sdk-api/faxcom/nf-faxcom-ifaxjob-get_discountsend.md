# IFaxJob::get_DiscountSend

## Description

The **IFaxJob::get_DiscountSend** property is a Boolean value that indicates whether the fax server will transmit the fax job during the discount rate period. The discount period applies only to outgoing fax transmissions.

This property is read-only.

## Parameters

## Remarks

To determine the period during which the discount rate applies, you can use the following IFaxServer properties.

* [DiscountRateStartMinute](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountratestartminute-vb)
* [DiscountRateEndMinute](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountrateendminute-vb)
* [DiscountRateStartHour](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountratestarthour-vb)
* [DiscountRateEndHour](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountrateendhour-vb)

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)

[Managing Fax Jobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-jobs)