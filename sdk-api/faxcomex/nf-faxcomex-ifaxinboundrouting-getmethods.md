# IFaxInboundRouting::GetMethods

## Description

The **IFaxInboundRouting::GetMethods** method retrieves the ordered collection of all the inbound routing methods exposed by all the inbound routing extensions currently registered with the fax service.

## Parameters

### `pFaxInboundRoutingMethods` [out, retval]

Type: **[IFaxInboundRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingmethods)****

Address of a pointer to an [IFaxInboundRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingmethods) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Order is based on the [Priority](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingmethod-priority) property of each routing method. The priority is associated with the order in which the fax service calls the routing method when the service receives a fax job.

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[IFaxInboundRouting](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundrouting)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-routing-extensions-and-routing-methods)