# IFaxPort::get_DeviceId

## Description

The **IFaxPort::get_DeviceId** property is a number representing the permanent line identifier for the fax port.

This property is read-only.

## Parameters

## Remarks

A fax client application can use the **IFaxPort::get_DeviceId** property to uniquely identify a fax port. A fax client can call the [IFaxPort::get_Name](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxport-get-name-vb) property to retrieve the user-friendly name for the fax port. Note, however, that it is possible for multiple fax ports to have the same user-friendly name.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPort::get_Name](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxport-get-name-vb)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)