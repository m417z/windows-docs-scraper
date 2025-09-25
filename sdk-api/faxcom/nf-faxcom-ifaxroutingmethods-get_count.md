# IFaxRoutingMethods::get_Count

## Description

The **IFaxRoutingMethods::get_Count** returns the number of fax routing methods associated with a [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object.

## Parameters

### `pVal` [out]

Type: **LONG***

A pointer to a **LONG** that receives the number of routing methods associated with this fax port.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After calling the **IFaxRoutingMethods::get_Count** method, a fax client application can call the [IFaxRoutingMethods::get_Item](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxroutingmethods-get_item) method to retrieve interface pointers to one or more [FaxRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxroutingmethod) objects.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[GetRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxport-getroutingmethods-vb)

[IFaxRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxroutingmethod)

[IFaxRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxroutingmethods)

[IFaxRoutingMethods::get_Item](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxroutingmethods-get_item)