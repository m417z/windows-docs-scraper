# IFaxInboundRoutingMethod::get_Priority

## Description

The [Priority](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingmethod-priority) property is a value associated with the order in which the fax service calls the routing method when the service receives a fax job.

This property is read/write.

## Parameters

## Remarks

Valid values for this property are 1 through *n*, where 1 is the highest priority.

You should assign a unique priority value to each routing method. After you call the [IFaxInboundRoutingMethod::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingmethod-save-vb) method, the fax service sorts the routing methods by priority. If two routing methods have the same priority, the fax service will choose which will have a higher priority.

If you want a particular routing method to have the lowest possible priority, specify a very large value, such as 999999, and then call the [IFaxInboundRoutingMethod::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingmethod-save-vb) method.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxInboundRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingmethod)

[IFaxInboundRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingmethod)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-routing-extensions-and-routing-methods)