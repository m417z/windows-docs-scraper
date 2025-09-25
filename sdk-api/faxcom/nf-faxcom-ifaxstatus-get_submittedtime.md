# IFaxStatus::get_SubmittedTime

## Description

Retrieves the **SubmittedTime** property for the [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object of a parent [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object. The **SubmittedTime** property is a number that represents the time the user submitted the active fax job.

This property is read-only.

## Parameters

## Remarks

You can use the **SubmittedTime** property of a [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object in conjunction with the [StartTime](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-starttime-vb) property of the object to provide users with information about a fax job.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)

[IFaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxstatus)

[IFaxStatus::get_Send](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-send-vb)

[IFaxStatus::get_StartTime](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-starttime-vb)