## Description

Determines whether the calling application has the required [AppContainer](https://learn.microsoft.com/windows/win32/secauthz/appcontainer-for-legacy-applications-) capabilities to make a network connection to a target server. Depending on the resolution of the server name, the function checks for **internetClient**, **internetClientServer**, and **privateNetworkClientServer**. For more info, see [App capability declarations](https://learn.microsoft.com/windows/uwp/packaging/app-capability-declarations).

## Parameters

### `wszServerName`

Type: \_\_in **[LPCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The name of the target server.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**TRUE** if the calling application has the required capabilities for the target server; otherwise, **FALSE**.

## Remarks

## See also