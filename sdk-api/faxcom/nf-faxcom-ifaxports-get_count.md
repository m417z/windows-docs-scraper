# IFaxPorts::get_Count

## Description

The **IFaxPorts::get_Count** method retrieves the number of fax ports attached to the connected fax server.

## Parameters

### `pVal` [out]

Type: **LONG***

A pointer to a **LONG** that receives the number of fax ports attached to the connected fax server.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After calling the **IFaxPorts::get_Count** method, a fax client application can call the [IFaxPorts::get_Item](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxports-get_item) method to retrieve an interface pointer to one or more [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) objects.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[GetPorts](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-getports-vb)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)

[IFaxPorts::get_Item](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxports-get_item)