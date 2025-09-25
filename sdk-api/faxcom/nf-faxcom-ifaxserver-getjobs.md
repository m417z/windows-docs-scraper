## Description

The **GetJobs** method creates and initializes a [FaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjobs-object-visual-basic-) object for a specified [FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client) object. The [FaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjobs) object allows enumeration of the current queued jobs for the connected fax server.

## Parameters

### `retval` [out]

Type: **VARIANT***

Pointer to a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure that receives an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer to a [FaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjobs) object. The method returns a pdispVal member with a VT_DISPATCH data type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **IFaxServer::GetJobs** method retrieves an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer to a [FaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjobs) object. A fax client application can also access the [IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs) interface directly by calling the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to retrieve an interface pointer.

A fax client application should not call the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function to retrieve an [IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs) interface pointer because it will not be instantiated correctly.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxserver)

[IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q))