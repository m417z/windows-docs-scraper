# IFaxRoutingMethods::get_Item

## Description

The **IFaxRoutingMethods::get_Item** method creates a [FaxRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxroutingmethod) object for a specified fax routing method. The object allows enumeration of fax routing information for a specified [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object.

## Parameters

### `Index` [in]

Type: **LONG**

Specifies a **LONG** variable that indicates the fax routing method to retrieve. Valid values for this parameter are in the range from 1 to *n*, where *n* is the number of fax routing methods returned by a call to the [IFaxRoutingMethods::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxroutingmethods-get_count) method.

### `pVal` [out]

Type: **VARIANT***

Receives a pointer to a **VARIANT** structure that receives an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer to a [FaxRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxroutingmethod) object. The method returns a **ppdispVal** member with a VT_DISPATCH data type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A fax client application can also access the [IFaxRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxroutingmethod) interface directly by calling the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to retrieve an **IFaxRoutingMethod** interface pointer.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[GetRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxport-getroutingmethods-vb)

[IFaxRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxroutingmethod)

[IFaxRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxroutingmethods)

[IFaxRoutingMethods::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxroutingmethods-get_count)