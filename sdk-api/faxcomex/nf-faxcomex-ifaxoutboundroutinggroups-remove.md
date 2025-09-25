# IFaxOutboundRoutingGroups::Remove

## Description

The **Remove** method removes an item from the [FaxOutboundRoutingGroups](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutinggroups) collection.

**Note** You cannot remove the special **All Devices** routing group.

## Parameters

### `vIndex`

Type: **VARIANT**

[Variant](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) that specifies the item to remove from the collection.

If this parameter is type VT_I2 or VT_I4, it specifies the index of the item to remove from the collection. Valid values for this parameter are in the range from 1 to n, where n is the number of objects returned by a call to the [IFaxOutboundRoutingGroups::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutinggroups-count-vb) method. The index is 1-based. If this parameter is type VT_BSTR, the parameter is a unique name that identifies the outbound routing group to remove. Other types are not supported.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutboundRoutingGroups](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutinggroups)

[IFaxOutboundRoutingGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroups)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outbound-routing-groups)