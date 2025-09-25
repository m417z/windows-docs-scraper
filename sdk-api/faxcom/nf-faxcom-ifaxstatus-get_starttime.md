# IFaxStatus::get_StartTime

## Description

Retrieves the **StartTime** property for the [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object of a parent [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object. The **StartTime** property is a number that represents the starting time for an active fax job.

This property is read-only.

## Parameters

## Remarks

You can use the **StartTime** property of a [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object in conjunction with the [ElapsedTime](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-elapsedtime-vb) property of the object to inform users about the transmission length of a fax job.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)

[IFaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxstatus)

[IFaxStatus::get_ElapsedTime](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-elapsedtime-vb)