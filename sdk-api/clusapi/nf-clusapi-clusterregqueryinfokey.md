# ClusterRegQueryInfoKey function

## Description

Returns information about a [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key.

## Parameters

### `hKey` [in]

Handle to a cluster database key. All subsequent parameters describe the contents of the key.

### `lpcSubKeys` [in]

If not **NULL**, pointer to the number of subkeys in the specified key.

### `lpcchMaxSubKeyLen` [in]

If not **NULL**, pointer to the number of characters in the longest subkey name in the specified key. The number does not include the terminating **NULL**.

### `lpcValues` [in]

If not **NULL**, pointer to the number of values in the specified key.

### `lpcchMaxValueNameLen` [in]

If not **NULL**, pointer to the number of characters in the longest value name in the specified key. The number does not include the terminating **NULL**.

### `lpcbMaxValueLen` [in]

If not **NULL**, pointer to the byte size of the largest data value in the specified key.

### `lpcbSecurityDescriptor` [in]

If not **NULL**, pointer to the byte size of the specified key's security descriptor.

### `lpftLastWriteTime` [in]

If not **NULL**, pointer to the time of the most recent modification to the specified key or any of its contents.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[ClusterRegOpenKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregopenkey)