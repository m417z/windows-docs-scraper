# IFaxOutboundRoutingRules::RemoveByCountryAndArea

## Description

The **IFaxOutboundRoutingRules::RemoveByCountryAndArea** method removes an outbound routing rule ([FaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrule) object) from the collection using the routing rule's country/region code and area code.

## Parameters

### `lCountryCode`

Type: **long**

A **long** value that specifies the country/region code of the outbound routing rule to remove from the collection. Specifying [frrcANY_CODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_routing_rule_code_enum) will remove a rule that applies to all country/region codes.

### `lAreaCode`

Type: **long**

A **long** value that specifies the area code of the outbound routing rule to remove from the collection. Specifying [frrcANY_CODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_routing_rule_code_enum) will remove a rule that applies to all area codes within the specified country/region code.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You cannot set both *lCountryCode* and *lAreaCode* to [frrcANY_CODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_routing_rule_code_enum) because this is equivalent to specifying the default outbound routing rule, which cannot be removed.

## See also

[FaxOutboundRoutingRules](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrules)

[IFaxOutboundRoutingRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrules)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-creating-and-managing-outbound-routing-rules)