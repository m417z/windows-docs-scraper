# IFaxPort::get_Tsid

## Description

The **IFaxPort::get_Tsid** property is a null-terminated string that contains the transmitting station identifier (TSID) associated with the fax port.

This property is read/write.

## Parameters

## Remarks

**Note** Before setting a value for this property, a fax client application can call the [IFaxPort::get_CanModify](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxport-get-canmodify-vb) property to ensure that the client has permission to modify configuration information for the specified fax port.

Only printable characters such as English letters, numeric symbols, and punctuation marks (ASCII range 0x20 to 0x7F) can be used in a called station identifier (CSID).

When the fax service receives a fax on a port, the service transmits the TSID to the receiving device.

The T.30 specification of the International Telecommunication Union (ITU) restricts the value of a TSID to 20 ASCII characters. If a fax client application specifies a TSID that contains non-ASCII characters, the fax service removes them. If the TSID exceeds 20 characters, the service truncates the extra characters.

**IFaxPort::get_Tsid** allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxport)

[IFaxPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxports)