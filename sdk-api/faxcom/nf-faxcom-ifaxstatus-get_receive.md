# IFaxStatus::get_Receive

## Description

Retrieves the **Receive** property for the [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object of a parent [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object. The **Receive** property is a Boolean value that indicates whether a specified fax port is currently receiving a fax.

This property is read-only.

## Parameters

## Remarks

To determine if a specified port is currently sending a fax, you can call the [IFaxStatus::get_Send](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-send-vb) method.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)

[IFaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxstatus)

[IFaxStatus::get_Send](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-send-vb)