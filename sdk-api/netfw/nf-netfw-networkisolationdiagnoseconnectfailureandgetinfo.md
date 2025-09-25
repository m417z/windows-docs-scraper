# NetworkIsolationDiagnoseConnectFailureAndGetInfo function

## Description

The **NetworkIsolationDiagnoseConnectFailureAndGetInfo** function gets information about a network isolation connection failure due to a missing capability. This function can be used to identify the capabilities required to connect to a server.

## Parameters

### `wszServerName` [in]

Type: **LPCWSTR**

Name (or IP address literal string) of the server to which a connection was attempted.

### `netIsoError` [out]

Type: **[NETISO_ERROR_TYPE](https://learn.microsoft.com/windows/desktop/api/networkisolation/ne-networkisolation-netiso_error_type)***

The error that has occurred, indicating which network capability was missing and thus caused the failure.

## Return value

Type: **DWORD**

Returns ERROR_SUCCESS if successful, or an error value otherwise.

## See also

[NETISO_ERROR_TYPE](https://learn.microsoft.com/windows/desktop/api/networkisolation/ne-networkisolation-netiso_error_type)