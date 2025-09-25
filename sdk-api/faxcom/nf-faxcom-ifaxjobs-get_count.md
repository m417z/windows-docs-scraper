# IFaxJobs::get_Count

## Description

The **IFaxJobs::get_Count** method returns the number of queued fax jobs associated with the connected fax server.

## Parameters

### `pVal` [out]

Type: **LONG***

A pointer to a **LONG** that receives the number of fax jobs associated with the connected fax server.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After calling the **IFaxJobs::get_Count** method, a fax client application can call the [IFaxJobs::get_Item](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxjobs-get_item) method to retrieve interface pointers to one or more [FaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjob) objects.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[GetJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-getjobs-vb)

[IFaxJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjob)

[IFaxJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxjobs)

[IFaxJobs::get_Item](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nf-faxcom-ifaxjobs-get_item)