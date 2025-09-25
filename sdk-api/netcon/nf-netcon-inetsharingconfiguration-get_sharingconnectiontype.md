# INetSharingConfiguration::get_SharingConnectionType

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**get_SharingConnectionType** method determines the type of sharing that is enabled on this connection.

## Parameters

### `pType` [out]

Pointer to a variable of type
[SHARINGCONNECTIONTYPE](https://learn.microsoft.com/windows/desktop/api/netcon/ne-netcon-sharingconnectiontype) that specifies whether this connection is shared publicly or privately.

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

To determine whether connection sharing is supported on the currently-installed operating system, use
[INetSharingManager::get_SharingInstalled](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingmanager-get_sharinginstalled).

Use the
[INetSharingManager::get_INetSharingConfigurationForINetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingmanager-get_inetsharingconfigurationforinetconnection) method to obtain an
[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration) interface for a particular connection.

## See also

[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration)

[INetSharingConfiguration::DisableSharing](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingconfiguration-disablesharing)

[INetSharingConfiguration::EnableSharing](https://learn.microsoft.com/windows/desktop/api/netcon/nf-netcon-inetsharingconfiguration-enablesharing)

[Internet Connection Sharing and Internet Connection Firewall Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-interfaces)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)

[SHARINGCONNECTIONTYPE](https://learn.microsoft.com/windows/desktop/api/netcon/ne-netcon-sharingconnectiontype)