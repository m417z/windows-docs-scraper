# IFaxInboundRoutingMethods::get_Item

## Description

The **IFaxInboundRoutingMethods::get_Item** method returns a [IFaxInboundRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingmethod) object from the [IFaxInboundRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingmethods) collection.

## Parameters

### `vIndex` [in]

Type: **VARIANT**

**VARIANT** that specifies the item to retrieve from the collection.

If this parameter is type VT_I2 or VT_I4, the parameter specifies the index of the item to retrieve from the collection. The index is 1-based. If this parameter is type VT_BSTR, the parameter is a GUID that identifies the fax routing method to retrieve. Other types are not supported.

### `pFaxInboundRoutingMethod` [out, retval]

Type: **[IFaxInboundRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingmethod)****

Address of a pointer to an [IFaxInboundRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingmethod) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFaxInboundRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingmethods)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-routing-extensions-and-routing-methods)