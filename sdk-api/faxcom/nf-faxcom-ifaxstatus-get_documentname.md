# IFaxStatus::get_DocumentName

## Description

Retrieves the **DocumentName** property for the [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object of a parent [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object. The **DocumentName** property is a null-terminated string that contains the user-friendly name associated with an active fax document.

This property is read-only.

## Parameters

## Remarks

You can use the **DocumentName** property of a [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object in conjunction with the [DocumentSize](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-documentsize-vb) property of the object to inform users about the size of outbound jobs.

The **IFaxStatus::get_DocumentName** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)

[IFaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxstatus)

[IFaxStatus::get_DocumentSize](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-documentsize-vb)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)