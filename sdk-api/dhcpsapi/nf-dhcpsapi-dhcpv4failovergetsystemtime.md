# DhcpV4FailoverGetSystemTime function

## Description

The **DhcpV4FailoverGetSystemTime** function returns the current time on the DHCP server.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `pTime` [out]

Pointer to a **DWORD** that returns the current time, in seconds, elapsed since midnight, January 1, 1970, Coordinated Universal Time (UTC), on the DHCP server.

### `pMaxAllowedDeltaTime`

The maximum allowed delta time.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |