# INetSharingConfiguration::AddPortMapping

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**AddPortMapping** method adds a service port mapping for this connection.

## Parameters

### `bstrName` [in]

Pointer to a
[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) variable that contains the name for this port mapping.

### `ucIPProtocol` [in]

Specifies the IP Protocol to set for the port mapping. The IP Protocol is one of the following values:

NAT_PROTOCOL_TCP

NAT_PROTOCOL_UDP

### `usExternalPort` [in]

Specifies the external port for this port mapping.

### `usInternalPort` [in]

Specifies the internal port for this port mapping.

### `dwOptions` [in]

This parameter is reserved and not used at this time.

### `bstrTargetNameOrIPAddress` [in]

Pointer to a
[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) variable that contains the name of the target computer for this port mapping. Specify either the target name or the target IP address, but not both.

### `eTargetType` [in]

Indicates target type.

### `ppMapping` [out]

Pointer to a pointer that, on successful return, points to an
[INetSharingPortMapping](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingportmapping) interface for the port mapping.

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

When first added, the new mapping is in a disabled state. To enable the new mapping, use
[INetSharingPortMapping::Enable](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingportmapping-enable).

After it is added, the new definition appears in the Port Mappings list in the ICS/ICF user interface.

Use the
[INetSharingManager::get_INetSharingConfigurationForINetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingmanager-get_inetsharingconfigurationforinetconnection) method to obtain an
[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration) interface for a particular connection.

## See also

[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration)

[Internet Connection Sharing and Internet Connection Firewall Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-interfaces)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)