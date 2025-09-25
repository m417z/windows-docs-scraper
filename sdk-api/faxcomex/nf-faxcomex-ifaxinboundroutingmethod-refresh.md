# IFaxInboundRoutingMethod::Refresh

## Description

The **IFaxInboundRoutingMethod::Refresh** method refreshes [IFaxInboundRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingmethod) interface information from the fax server.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the **IFaxInboundRoutingMethod::Refresh** method is called, any configuration changes made after the last [IFaxInboundRoutingMethod::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingmethod-save-vb) method call are lost.

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxInboundRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingmethod)

[IFaxInboundRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingmethod)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-routing-extensions-and-routing-methods)