# IFaxOutboundRoutingRule::get_DeviceId

## Description

The **IFaxOutboundRoutingRule::get_DeviceId** property specifies the device ID if the outbound routing rule points to a single fax device.

This property is read/write.

## Parameters

## Remarks

This property is valid only if the [IFaxOutboundRoutingRule::get_UseDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrule-usedevice-vb) property is equal to **TRUE**.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrule)

[IFaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrule)