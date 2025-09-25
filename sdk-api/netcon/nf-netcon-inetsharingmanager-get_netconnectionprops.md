# INetSharingManager::get_NetConnectionProps

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**get_NetConnectionProps** method retrieves a properties interface for the specified connection.

## Parameters

### `pNetConnection` [in]

Pointer to an
[INetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetconnection) interface for the connection for which to retrieve the properties interface.

### `ppProps` [out]

Pointer to an interface pointer that, on successful return, points to an
[INetConnectionProps](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetconnectionprops) interface for the connection.

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

## Remarks

Not all connections can be configured for sharing. Retrieve the properties for the connection to verify that the connection can be shared before calling
[INetSharingManager::get_INetSharingConfigurationForINetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingmanager-get_inetsharingconfigurationforinetconnection).

## See also

[INetSharingManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingmanager)

[INetSharingManager::get_INetSharingConfigurationForINetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingmanager-get_inetsharingconfigurationforinetconnection)

[Internet Connection Sharing and Internet Connection Firewall Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-interfaces)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)