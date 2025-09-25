# IFaxOutboundRoutingGroups::Add

## Description

The **IFaxOutboundRoutingGroups::Add** method adds an outbound routing group to the collection represented by the [IFaxOutboundRoutingGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroups) interface.

## Parameters

### `bstrName` [in]

Type: **BSTR**

Null-terminated string that indicates the name of the group to add. Note that you cannot add the special **All Devices** routing group.

### `pFaxOutboundRoutingGroup` [out, retval]

Type: **[IFaxOutboundRoutingGroup](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroup)****

Address of a pointer that receives a [IFaxOutboundRoutingGroup](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroup) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[IFaxOutboundRoutingGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroups)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outbound-routing-groups)