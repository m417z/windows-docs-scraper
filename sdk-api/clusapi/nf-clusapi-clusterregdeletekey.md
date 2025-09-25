# ClusterRegDeleteKey function

## Description

Deletes a [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key.

## Parameters

### `hKey` [in]

Handle to a currently open key.

### `lpszSubKey` [in]

Pointer to a null-terminated Unicode string specifying the name of the key to delete. The key pointed to by
*lpszSubKey* cannot have subkeys;
**ClusterRegDeleteKey** can only delete keys without
subkeys. This parameter cannot be **NULL**.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS** (0).

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **ClusterRegDeleteKey** function cannot delete
a key that has one or more subkeys.

Do not call **ClusterRegDeleteKey** from the
following resource DLL entry point functions:

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ClusterRegDeleteKey** can be safely called from
any other resource DLL entry point function or from a worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[ClusterRegCreateKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatekey)