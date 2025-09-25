# DhcpGetVersion function

## Description

The **DhcpGetVersion** function returns the major and minor version numbers of the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `MajorVersion` [out]

Specifies the major version number of the DHCP server.

### `MinorVersion` [out]

Specifies the minor version number of the DHCP server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).