# NetworkIsolationEnumAppContainers function

## Description

The **NetworkIsolationEnumAppContainers** function enumerates all of the app containers that have been created in the system.

## Parameters

### `Flags` [in]

Type: **DWORD**

May be set to **NETISO_FLAG_FORCE_COMPUTE_BINARIES** to ensure that all binaries are computed before the app container is returned. This flag should be set if the caller requires up-to-date and complete information on app container binaries. If this flag is not set, returned data may be stale or incomplete.

See [NETISO_FLAG](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/ne-netfw-netiso_flag) for more information.

### `pdwNumPublicAppCs` [out]

Type: **DWORD***

The number of app containers in the **ppPublicAppCs** member.

### `ppPublicAppCs` [out]

Type: **[PINET_FIREWALL_APP_CONTAINER](https://learn.microsoft.com/windows/desktop/api/netfw/ns-netfw-inet_firewall_app_container)***

The list of app container structure elements.

## Return value

Type: **DWORD**

Returns ERROR_SUCCESS if successful, or an error value otherwise.

ERROR_OUTOFMEMORY will be returned if memory is unavailable.

## Remarks

If no app containers are installed on the system, ERROR_SUCCESS will still be returned (and *ppPublicAppCs* will be empty). If ppPublicAppCs is not empty, [NetworkIsolationFreeAppContainers](https://docs.microsoft.com/en-us/windows/win32/api/netfw/nf-netfw-networkisolationfreeappcontainers) should be used to free the memory when you are done using it.

## See also

[INET_FIREWALL_APP_CONTAINER](https://learn.microsoft.com/windows/desktop/api/netfw/ns-netfw-inet_firewall_app_container)

[NETISO_FLAG](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/ne-netfw-netiso_flag)