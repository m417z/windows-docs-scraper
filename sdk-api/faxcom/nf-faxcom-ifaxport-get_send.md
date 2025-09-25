# IFaxPort::get_Send

## Description

The **IFaxPort::get_Send** property is a Boolean value that indicates whether a fax port is enabled to send faxes.

This property is read/write.

## Parameters

## Remarks

**Note** Before setting a value for this property, a fax client application can call the [IFaxPort::get_CanModify](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxport-get-canmodify-vb) property to ensure that the client has permission to modify configuration information for the specified fax port.

The **IFaxPort::get_Send** property returns a value of **TRUE** if the fax port is enabled to send faxes. If a fax client application passes a value of **TRUE** to the property, it enables the fax port to send faxes.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)