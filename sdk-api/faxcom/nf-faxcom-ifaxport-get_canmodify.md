# IFaxPort::get_CanModify

## Description

The **IFaxPort::get_CanModify** property is a Boolean value that indicates whether the user has permission to modify configuration information for the fax port.

This property is read-only.

## Parameters

## Remarks

To ensure that the client has permission to modify the specified fax port, a fax client application can call the **IFaxPort::get_CanModify** property before calling any method that begins with **IFaxPort::put_**. For more information, see [Fax Device Management](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-device-management).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)