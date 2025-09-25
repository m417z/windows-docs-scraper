# IFaxOutboundRoutingRules::get_Item

## Description

The **IFaxOutboundRoutingRules::get_Item** method returns a [IFaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrule) interface from the [IFaxOutboundRoutingRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrules) interface using the routing rule's index.

## Parameters

### `lIndex` [in]

Type: **long**

A **long** value that specifies the outbound routing rule to retrieve from the collection. Valid values for this parameter are in the range from 1 to n, where n is the number of items returned by a call to the [IFaxOutboundRoutingRules::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrules-count-vb) method.

### `pFaxOutboundRoutingRule` [out, retval]

Type: **[IFaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrule)****

An address of a pointer that receives the [IFaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrule) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFaxOutboundRoutingRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrules)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-creating-and-managing-outbound-routing-rules)