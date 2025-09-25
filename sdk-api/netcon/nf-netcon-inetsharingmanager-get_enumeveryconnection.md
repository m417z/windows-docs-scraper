# INetSharingManager::get_EnumEveryConnection

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**get_EnumEveryConnection** method retrieves an enumeration interface for all the connections in the connection folder.

## Parameters

### `ppColl` [out]

Pointer to a pointer that, on successful return, points to an
[INetSharingEveryConnectionCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingeveryconnectioncollection) interface.

## Return value

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ABORT** | The operation was aborted. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_NOINTERFACE** | A specified interface is not supported. |
| **E_NOTIMPL** | A specified method is not implemented. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |
| **E_UNEXPECTED** | The method failed for unknown reasons. |

## See also

[IEnumNetSharingEveryConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-ienumnetsharingeveryconnection)

[INetSharingEveryConnectionCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingeveryconnectioncollection)

[INetSharingManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingmanager)

[Internet Connection Sharing and Internet Connection Firewall Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-interfaces)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)