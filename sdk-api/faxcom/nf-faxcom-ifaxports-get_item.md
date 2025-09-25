# IFaxPorts::get_Item

## Description

The **IFaxPorts::get_Item** method creates a [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object for a specified fax port. The object allows enumeration of port configuration information for a specific connection to a fax server.

## Parameters

### `Index` [in]

Type: **LONG**

Specifies a **LONG** variable that indicates the fax port to retrieve. Valid values for this parameter are in the range from 1 to *n*, where *n* is the number of fax ports returned by a call to the [IFaxPorts::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxports-get_count) method.

### `pVal` [out]

Type: **VARIANT***

Receives a pointer to a **VARIANT** structure that receives an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer to a [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object. The method returns a **ppdispVal** member with a VT_DISPATCH data type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A fax client application can also access the [IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport) interface directly by calling the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to retrieve an **IFaxPort** interface pointer.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport)

[FaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxports)

[GetPorts](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-getports-vb)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)

[IFaxPorts::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxports-get_count)