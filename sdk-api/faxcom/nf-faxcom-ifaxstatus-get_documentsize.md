# IFaxStatus::get_DocumentSize

## Description

Retrieves the **DocumentSize** property for the [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object of a parent [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object. The **DocumentSize** property is the size of the fax document associated with the active outbound job on a specific port.

This property is read-only.

## Parameters

## Remarks

You can use the **DocumentSize** property of a [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object in conjunction with the [DocumentName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-documentname-vb) property of the object to inform users about the size of outbound jobs.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)

[IFaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxstatus)

[IFaxStatus::get_DocumentName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-documentname-vb)