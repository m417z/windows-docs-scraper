# ClusterRegEnumKey function

## Description

Enumerates the subkeys of an open
[cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key.

## Parameters

### `hKey` [in]

**HKEY** specifying a currently open key.

### `dwIndex` [in]

Index used to identify the next subkey to be enumerated. This parameter should be zero for the first call to
**ClusterRegEnumKey** and then incremented for
subsequent calls.

Because subkeys are not ordered, any new subkey has an arbitrary index. This means that
**ClusterRegEnumKey** may return subkeys in any
order.

### `lpszName` [out]

Pointer to a buffer that receives the name of the subkey, including the null-terminating character. The
function copies only the name of the subkey, not the full key hierarchy, to the buffer.

### `lpcchName` [in, out]

Pointer to the size of the *lpszName* buffer as a count of characters. On input,
specify the maximum number of characters the buffer can hold, including the terminating
**NULL**. On output, specifies the number of characters in the resulting name, excluding
the terminating **NULL**.

### `lpftLastWriteTime` [out, optional]

Pointer to the last time the enumerated subkey was modified.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_NO_MORE_ITEMS**<br><br>259 (0x103) | There are no more subkeys to be returned. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | The buffer pointed to by *lpszName* is not big enough to hold the result. The *lpcchName* parameter returns the number of characters in the result, excluding the terminating **NULL**. |
| **[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The operation failed. |

## Remarks

The **ClusterRegEnumKey** function retrieves
information about one subkey each time it is called.

Because **ClusterRegEnumKey** enumerates keys from
the root of the database on the node on which the application is running when *hKey* is
set to **NULL**,
**ClusterRegEnumKey** fails if the node is not part of
a cluster.

## See also

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)

[ClusterRegOpenKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregopenkey)