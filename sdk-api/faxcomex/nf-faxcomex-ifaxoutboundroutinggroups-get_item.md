# IFaxOutboundRoutingGroups::get_Item

## Description

The **IFaxOutboundRoutingGroups::get_Item** method returns a [IFaxOutboundRoutingGroup](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroup) interface from the collection.

## Parameters

### `vIndex` [in]

Type: **VARIANT**

[Variant](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) that specifies the item to retrieve from the collection.

If this parameter is type VT_I2 or VT_I4, the parameter specifies the index of the item to retrieve from the collection. The index is 1-based. If this parameter is type VT_BSTR, the parameter is a unique name that identifies the outbound routing group to retrieve. Other types are not supported.

### `pFaxOutboundRoutingGroup` [out, retval]

Type: **[IFaxOutboundRoutingGroup](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroup)****

An address of a pointer that receives the [IFaxOutboundRoutingGroup](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroup) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To return the group consisting of all of the devices, set *vIndex* equal to the constant [bstrGROUPNAME_ALLDEVICES](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-bstrgroupname-alldevices).

## See also

[IFaxOutboundRoutingGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroups)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outbound-routing-groups)