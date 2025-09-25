# DhcpServerRedoAuthorization function

## Description

The **DhcpServerRedoAuthorization** function attempts to determine whether the DHCP server is authorized and restores leasing operations if it is not.

## Parameters

### `ServerIpAddr` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `dwReserved` [in]

Reserved. This parameter should be set to 0.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

An "authorized" DHCP server is a server currently leasing IP addresses for the subnets it has been set to administer. If a DHCP server has stopped leasing addresses, calling this method attempts to "redo" the authorization, and if **ERROR_SUCCESS** is returned, IP address leasing resumes.