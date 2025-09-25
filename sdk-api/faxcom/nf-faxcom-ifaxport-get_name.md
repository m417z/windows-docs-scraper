# IFaxPort::get_Name

## Description

The **IFaxPort::get_Name** property is a null-terminated string that contains the
user-friendly display name for a fax port.

This property is read-only.

## Parameters

## Remarks

Note that it is possible for multiple fax ports to have the same user-friendly
name. Use the [IFaxPort::get_DeviceId](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxport-get-deviceid-vb) property to uniquely identify a fax port.

**IFaxPort::get_Name** allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPort::get_DeviceId](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxport-get-deviceid-vb)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)