# IFaxPort::get_Rings

## Description

The **IFaxPort::get_Rings** property represents the number of rings an incoming fax call should wait before the fax port answers the call.

This property is read/write.

## Parameters

## Remarks

**Note** Before setting a value for this property, a fax client application can call the [IFaxPort::get_CanModify](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxport-get-canmodify-vb) property to ensure that the client has permission to modify configuration information for the specified fax port.

The fax server ignores the **IFaxPort::get_Rings** property unless the specified fax port is enabled to receive faxes.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)