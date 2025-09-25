# INetSharingManager::get_INetSharingConfigurationForINetConnection

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**get_INetSharingConfigurationForINetConnection** method retrieves an
[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration) interface for the specified connection.

## Parameters

### `pNetConnection`

Pointer to an
[INetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetconnection) interface for an Internet connection.

### `ppNetSharingConfiguration` [out]

Pointer to an interface pointer that, on successful return, points to an
[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration) interface for the connection specified by the *pNetConnection* parameter.

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

[INetSharingManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingmanager)

[Internet Connection Sharing and Internet Connection Firewall Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-interfaces)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)