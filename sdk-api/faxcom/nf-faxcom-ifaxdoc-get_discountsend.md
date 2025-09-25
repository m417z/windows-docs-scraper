# IFaxDoc::get_DiscountSend

## Description

Sets or retrieves the **DiscountSend** property for a [FaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdoc) object. The **DiscountSend** property is a Boolean value that indicates whether the fax server transmits faxes during the discount period.

This property is read/write.

## Parameters

## Remarks

To determine the period during which the discount rate applies, you can call the following [IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxserver) methods: [DiscountRateStartMinute](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountratestartminute-vb), [DiscountRateEndMinute](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountrateendminute-vb), [DiscountRateStartHour](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountratestarthour-vb), and [DiscountRateEndHour](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountrateendhour-vb).

## See also

[DiscountRateEndHour](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountrateendhour-vb)

[DiscountRateEndMinute](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountrateendminute-vb)

[DiscountRateStartHour](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountratestarthour-vb)

[DiscountRateStartMinute](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-get-discountratestartminute-vb)

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxdoc)