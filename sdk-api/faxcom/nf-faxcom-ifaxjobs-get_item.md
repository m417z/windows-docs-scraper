# IFaxJobs::get_Item

## Description

The **IFaxJobs::get_Item** method returns a new [FaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjob) object for a specified fax job. The object allows enumeration of the fax jobs associated with a connected fax server.

## Parameters

### `Index` [in]

Type: **LONG**

Specifies a **LONG** variable that indicates the fax job to retrieve. Valid values for this parameter are in the range from 1 to *n*, where *n* is the number of [FaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjob) objects returned by a call to the [IFaxJobs::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxjobs-get_count) method.

### `pVal` [out]

Type: **VARIANT***

Receives a pointer to a **VARIANT** structure that receives an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer to a [FaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjob) object. The method returns a **ppdispVal** member with a VT_DISPATCH data type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A fax client application can also access the [IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob) interface directly by calling the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to retrieve an **IFaxJob** interface pointer.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[GetJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-getjobs-vb)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)

[IFaxJobs::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxjobs-get_count)

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)