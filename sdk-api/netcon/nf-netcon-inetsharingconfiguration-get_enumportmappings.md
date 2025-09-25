# INetSharingConfiguration::get_EnumPortMappings

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**get_EnumPortMappings** method retrieves an
[IEnumNetSharingPortMapping](https://learn.microsoft.com/windows/desktop/api/netcon/nn-netcon-ienumnetsharingportmapping) interface. Use this interface to enumerate the port mappings for this connection.

## Parameters

### `Flags` [in]

This parameter must be ICSSC_DEFAULT.

### `ppColl` [out]

Pointer to an interface pointer that, on successful return, points to a
[INetSharingPortMappingCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingportmappingcollection) interface.

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

Use the
[INetSharingManager::get_INetSharingConfigurationForINetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingmanager-get_inetsharingconfigurationforinetconnection) method to obtain an
[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration) interface for a particular connection.

## See also

[IEnumNetSharingPortMapping](https://learn.microsoft.com/windows/desktop/api/netcon/nn-netcon-ienumnetsharingportmapping)

[INetSharingConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingconfiguration)

[INetSharingConfiguration::AddPortMapping](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingconfiguration-addportmapping)

[INetSharingConfiguration::RemovePortMapping](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nf-netcon-inetsharingconfiguration-removeportmapping)

[INetSharingPortMappingCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetsharingportmappingcollection)

[Internet Connection Sharing and Internet Connection Firewall Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-interfaces)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)