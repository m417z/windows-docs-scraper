# IFaxReceiptOptions::get_UseForInboundRouting

## Description

The **IFaxReceiptOptions::get_UseForInboundRouting**  property sets or retrieves whether to use the [FaxReceiptOptions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxreceiptoptions) settings for the Microsoft Routing Extension, which allows incoming faxes to be routed to email addresses.

This property is read/write.

## Parameters

## Remarks

If the settings are not used (property is set to **FALSE**), then the Microsoft Routing Extension is disabled, and users will not be able to receive faxes to email addresses. If the settings are used (property is set to **TRUE**), then the Microsoft Routing Extension is enabled, and users will be able to receive faxes to email addresses.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxReceiptOptions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxreceiptoptions)

[IFaxReceiptOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxreceiptoptions)

[Setting Receipt Options](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-setting-receipt-options)