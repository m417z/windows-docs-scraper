# IFaxDevice::get_UsedRoutingMethods

## Description

The **IFaxDevice::get_UsedRoutingMethods** property is an array of strings that contains the GUIDs associated with the routing methods that the device uses, where each GUID represents an inbound routing method ([FaxInboundRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingmethod)).

This property is read-only.

## Parameters

## Remarks

To add a routing method to or remove a routing method from the array of routing method GUIDs, call the [IFaxDevice::UseRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice-useroutingmethod-vb) method.

To read this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice)

[IFaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdevice)

[IFaxDevice::UseRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice-useroutingmethod-vb)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-fax-device-collection)