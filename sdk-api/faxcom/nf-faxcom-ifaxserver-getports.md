## Description

The **GetPorts** method creates and initializes a [FaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxports) object for a specified [FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client) object. The FaxPorts object allows enumeration of fax port configuration information for the connected fax server.

## Parameters

### `retval` [out]

Type: **VARIANT***

Pointer to a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure that receives an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer to a [FaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxports-object-visual-basic-) object. The method returns a pdispVal member with a VT_DISPATCH data type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **IFaxServer::GetPorts** method retrieves an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer to a [FaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxports) object. A fax client application can also access the [IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports) interface directly by calling the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to retrieve an interface pointer.

A fax client application should not call the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function to retrieve an [IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports) interface pointer because it will not be instantiated correctly.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxserver)

[IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q))