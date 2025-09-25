# IFaxOutboundRoutingRule::Refresh

## Description

The **IFaxOutboundRoutingRule::Refresh** method refreshes [FaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrule) object information from the fax server.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the **IFaxOutboundRoutingRule::Refresh** method is called, any configuration changes made after the last [IFaxOutboundRoutingRule::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrule-save-vb) method call are lost.

## See also

[FaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrule)

[IFaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrule)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-creating-and-managing-outbound-routing-rules)