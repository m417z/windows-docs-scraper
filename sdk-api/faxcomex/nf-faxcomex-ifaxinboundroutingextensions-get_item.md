# IFaxInboundRoutingExtensions::get_Item

## Description

The **IFaxInboundRoutingExtensions::get_Item** method returns a [IFaxInboundRoutingExtension](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingextension) interface from the [IFaxInboundRoutingExtensions](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingextensions) collection.

## Parameters

### `vIndex` [in]

Type: **VARIANT**

**VARIANT** that specifies the item to retrieve from the collection.

If this parameter is type VT_I2 or VT_I4, the parameter specifies the index of the item to retrieve from the collection. The index is 1-based. If this parameter is type VT_BSTR, the parameter is a string containing the unique name of the fax routing extension to retrieve. Other types are not supported.

### `pFaxInboundRoutingExtension` [out, retval]

Type: **[IFaxInboundRoutingExtension](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingextension)****

Address of a pointer to an [IFaxInboundRoutingExtension](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingextension) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFaxInboundRoutingExtensions](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxinboundroutingextensions)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-routing-extensions-and-routing-methods)