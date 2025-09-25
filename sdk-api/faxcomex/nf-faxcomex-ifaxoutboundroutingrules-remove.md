# IFaxOutboundRoutingRules::Remove

## Description

The **IFaxOutboundRoutingRules::Remove** method removes an outbound routing rule ([FaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrule) object) from the [FaxOutboundRoutingRules](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrules) collection using the routing rule's index.

## Parameters

### `lIndex`

Type: **long**

A **long** value that specifies the index of the outbound routing rule to remove from the collection. Valid values for this parameter are in the range from 1 to n, where n is the number of rules returned by a call to the [IFaxOutboundRoutingRules::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrules-count-vb) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default outbound routing rule cannot be removed.

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutboundRoutingRules](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrules)

[IFaxOutboundRoutingRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrules)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-creating-and-managing-outbound-routing-rules)