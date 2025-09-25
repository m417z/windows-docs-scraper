# ClusterRegSetKeySecurity function

## Description

Sets the security attributes for a [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database)
key.

## Parameters

### `hKey` [in]

Handle to a cluster database key.

### `SecurityInformation` [in]

A [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure that
indicates the content of the security descriptor pointed to by
*pSecurityDescriptor*.

### `pSecurityDescriptor` [in]

Pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure
that describes the security attributes to set for the key corresponding to *hKey*.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS** (0).

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **ClusterRegSetKeySecurity** function
generates a **CLUSTER_CHANGE_REGISTRY_ATTRIBUTES** event for all registered notification
ports.

Do not call **ClusterRegSetKeySecurity** from
the following resource DLL entry point functions:

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ClusterRegSetKeySecurity** can be safely
called from any other resource DLL entry point function or from a worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[ClusterRegOpenKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregopenkey)