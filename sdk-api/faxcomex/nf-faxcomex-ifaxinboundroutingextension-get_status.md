# IFaxInboundRoutingExtension::get_Status

## Description

The **IFaxInboundRoutingExtension::get_Status** property is a value that indicates whether the fax routing extension loaded and initialized successfully.

This property is read-only.

## Parameters

## Remarks

If the extension did not load successfully, the property indicates the reason for the failure, and [IFaxInboundRoutingExtension::get_InitErrorCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingextension-initerrorcode-vb) holds the last error code value. For more information, see [FAX_PROVIDER_STATUS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_provider_status_enum).

## See also

[FaxInboundRoutingExtension](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingextension)

[IFaxInboundRoutingExtension](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingextension)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-routing-extensions-and-routing-methods)