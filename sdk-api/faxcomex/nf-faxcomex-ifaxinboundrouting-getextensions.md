# IFaxInboundRouting::GetExtensions

## Description

The [GetExtensions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundrouting-getextensions) method retrieves the collection of inbound routing extensions registered with the fax service.

## Parameters

### `pFaxInboundRoutingExtensions` [out, retval]

Type: **[IFaxInboundRoutingExtensions](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingextensions)****

Address of a pointer to an [IFaxInboundRoutingExtensions](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingextensions) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[IFaxInboundRouting](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundrouting)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-routing-extensions-and-routing-methods)