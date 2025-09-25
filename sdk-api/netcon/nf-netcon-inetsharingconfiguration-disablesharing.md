# INetSharingConfiguration::DisableSharing

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**DisableSharing** method disables sharing on this connection. It also disables all mappings on this connection. It does not disable Internet Connection Firewall or bridge configuration.

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

Calling this method triggers the following notification:

%programname% is attempting to disable Internet Connection Sharing (ICS). The following number of users or computers are currently sharing the Internet connection: %number%. Do you want to allow %programname% to disable ICS?

This method returns successfully when called on a connection that is not enabled for sharing. In this case, the method still disables all mappings on the connection.

Use the
[INetSharingManager::get_INetSharingConfigurationForINetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingmanager-get_inetsharingconfigurationforinetconnection) method to obtain an
[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration) interface for a particular connection.

## See also

[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration)

[INetSharingConfiguration::EnableSharing](https://learn.microsoft.com/windows/desktop/api/netcon/nf-netcon-inetsharingconfiguration-enablesharing)

[INetSharingConfiguration::get_SharingEnabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingconfiguration-get_sharingenabled)

[Internet Connection Sharing and Internet Connection Firewall Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-interfaces)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)