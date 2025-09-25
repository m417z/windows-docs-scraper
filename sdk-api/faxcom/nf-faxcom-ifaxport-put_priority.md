# IFaxPort::put_Priority

## Description

The **IFaxPort::get_Priority** property is a number representing the transmission priority designated for a specified fax port. Priority determines the relative order in which available fax devices send outgoing transmissions.

This property is read/write.

## Parameters

## Remarks

**Note** Before setting a value for this property, a fax client application can call the [IFaxPort::get_CanModify](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxport-get-canmodify-vb) property to ensure that the client has permission to modify configuration information for the specified fax port.

When the fax server initiates an outgoing fax transmission, it chooses the fax port with the highest priority and send capability. If that port is not available, the server selects the next available port that follows in rank order, and so on. When a client application changes the priority for a fax port, the fax service adjusts the priority for the other fax ports attached to the server. The **IFaxPort::get_Priority** property has no effect on incoming transmissions.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)