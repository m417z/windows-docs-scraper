# IFaxServer::put_DiscountRateEndHour

## Description

Sets or retrieves the **DiscountRateEndHour** property for a [FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client) object. The **DiscountRateEndHour** property is a number that represents the hour the discount period ends. The discount period applies only to outgoing fax transmissions.

This property is read/write.

## Parameters

## Remarks

To save on transmission costs, a user can queue a fax job and request that the fax server send the transmission during the discount rate period. For more information, see [IFaxDoc::DiscountSend Property](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-discountsend-vb).

The [DiscountRateStartHour](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountratestarthour-vb), [DiscountRateStartMinute](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountratestartminute-vb), **DiscountRateEndHour**, and [DiscountRateEndMinute](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountrateendminute-vb) properties represent local time.

If the time the discount rate period ends is less than the time the discount rate period begins, the discount rate period extends into the next day. For example, if the discount rate period begins at 9:00 P.M. and ends at 7:00 A.M., the discount rate period begins in the evening and continues until the morning of the following day.

## See also

[DiscountSend](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-discountsend-vb)

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxserver)

[IFaxServer::get_DiscountRateEndMinute](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountrateendminute-vb)

[IFaxServer::get_DiscountRateStartHour](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountratestarthour-vb)

[IFaxServer::get_DiscountRateStartMinute](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountratestartminute-vb)