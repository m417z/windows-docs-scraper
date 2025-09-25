# IFaxRoutingMethod::get_DeviceId

## Description

The **IFaxRoutingMethod::get_DeviceId** property is a number representing the line identifier for the fax port.

This property is read-only.

## Parameters

## Remarks

A fax client application can use the **IFaxRoutingMethod::get_DeviceId** property to uniquely identify a fax port. You can call the [IFaxRoutingMethod::get_DeviceName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxroutingmethod-get-devicename-vb) property to retrieve the user-friendly name for a port. Note, however, that it is possible for multiple fax ports to have the same user-friendly name.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)

[IFaxRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxroutingmethod)

[IFaxRoutingMethod::get_DeviceName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxroutingmethod-get-devicename-vb)

[IFaxRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxroutingmethods)