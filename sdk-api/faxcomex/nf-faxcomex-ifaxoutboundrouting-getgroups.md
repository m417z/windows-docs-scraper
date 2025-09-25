# IFaxOutboundRouting::GetGroups

## Description

The **IFaxOutboundRouting::GetGroups** method retrieves an interface that represents a collection of outbound routing groups.

## Parameters

### `pFaxOutboundRoutingGroups` [out, retval]

Type: **[IFaxOutboundRoutingGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroups)****

An address of a pointer that receives an [IFaxOutboundRoutingGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroups) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[IFaxOutboundRouting](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundrouting)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outbound-routing-groups)