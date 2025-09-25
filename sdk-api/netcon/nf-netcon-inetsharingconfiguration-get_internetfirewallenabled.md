# INetSharingConfiguration::get_InternetFirewallEnabled

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**get_InternetFirewallEnabled** method determines whether Internet Connection Firewall is enabled on this connection.

## Parameters

### `pbEnabled` [out]

Pointer to a **VARIANT_BOOL** variable that, on successful return, specifies whether Internet Connection Firewall is enabled. If Internet Connection Firewall is enabled, this value is **TRUE**. Otherwise, it is **FALSE**.

## Return value

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ABORT** | The operation was stopped. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_NOINTERFACE** | A specified interface is not supported. |
| **E_NOTIMPL** | A specified method is not implemented. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |
| **E_UNEXPECTED** | The method failed for unknown reasons. |

## Remarks

Use the
[INetSharingManager::get_INetSharingConfigurationForINetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingmanager-get_inetsharingconfigurationforinetconnection) method to obtain an
[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration) interface for a particular connection.

**Windows XP with SP2:**  The resulting firewall status is determined by the combination of two levels: First check the global operation mode, then the mode on the interface of interest. Use the procedure [Checking the Effective Firewall Status](https://learn.microsoft.com/previous-versions/windows/desktop/ics/checking-the-effective-firewall-status) to determine the overall operational state.

## See also

[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration)

[INetSharingConfiguration::DisableInternetFirewall](https://learn.microsoft.com/windows/desktop/api/netcon/nf-netcon-inetsharingconfiguration-disableinternetfirewall)

[INetSharingConfiguration::EnableInternetFirewall](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingconfiguration-enableinternetfirewall)

[Internet Connection Sharing and Internet Connection Firewall Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-interfaces)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)