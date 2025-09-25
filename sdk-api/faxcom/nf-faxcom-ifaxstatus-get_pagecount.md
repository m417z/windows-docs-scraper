# IFaxStatus::get_PageCount

## Description

Retrieves the **PageCount** property for the [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object of a parent [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object. The **PageCount** property represents the total number of pages in an outbound fax transmission.

This property is read-only.

## Parameters

## Remarks

If the page count is not available, the **IFaxStatus::get_PageCount** method returns zero.

You can use the **PageCount** property of a [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object in conjunction with the [CurrentPage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-currentpage-vb) property of the object to provide users with a running page count for an outbound fax job. For example, you could inform a user that the fax server is currently transmitting the second page of a four page transmission.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)

[IFaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxstatus)

[IFaxStatus::get_CurrentPage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-currentpage-vb)