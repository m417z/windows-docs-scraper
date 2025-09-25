## Description

The **IFaxOutboundRoutingRules::get_ItemByCountryAndArea** method returns an outbound routing rule ([FaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrule) object) from the collection using the routing rule's country/region code and area code.

## Parameters

### `lCountryCode`

Type: **long**

A **long** value that specifies the country/region code of the outbound routing rule to retrieve. Specifying [frrcANY_CODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_routing_rule_code_enum) will return a rule for any country/region code.

### `lAreaCode`

Type: **long**

A **long** value that specifies the area code of the outbound routing rule to retrieve. Specifying [frrcANY_CODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_routing_rule_code_enum) will return a rule for any area code within the specified country/region code.

### `pFaxOutboundRoutingRule`

Type: **[FaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrule)****

A [FaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrule) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FaxOutboundRoutingRules](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrules)

[IFaxOutboundRoutingRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrules)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-creating-and-managing-outbound-routing-rules)