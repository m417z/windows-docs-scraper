# INetSharingConfiguration::EnableSharing

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**EnableSharing** method enables sharing on this connection.

## Parameters

### `Type` [in]

Specifies whether this connection is shared publicly or privately.

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

%programname% is attempting to enable Internet Connection Sharing on the network connection %connectionname%. This will allow other computers on your network to connect to the Internet through a shared public connection. Do you want %programname% to enable Internet Connection Sharing on this connection?

If the calling application specifies that this connection is publicly shared, any previous publicly-shared connection is automatically disabled.

A publicly-shared connection automatically has Internet Connection Firewall enabled. Privately-shared connections retain their existing settings.

Use the
[INetSharingManager::get_INetSharingConfigurationForINetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingmanager-get_inetsharingconfigurationforinetconnection) method to obtain an
[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration) interface for a particular connection.

## See also

[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration)

[INetSharingConfiguration::DisableSharing](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingconfiguration-disablesharing)

[INetSharingConfiguration::get_SharingEnabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingconfiguration-get_sharingenabled)

[Internet Connection Sharing and Internet Connection Firewall Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-interfaces)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)

[SHARINGCONNECTIONTYPE](https://learn.microsoft.com/windows/desktop/api/netcon/ne-netcon-sharingconnectiontype)