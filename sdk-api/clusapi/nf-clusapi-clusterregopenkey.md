# ClusterRegOpenKey function

## Description

Opens an existing [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key.

## Parameters

### `hKey` [in]

Handle to a currently open key. This parameter cannot be **NULL**.

### `lpszSubKey` [in]

Pointer to a null-terminated Unicode string specifying the name of the subkey to be created or opened. The *lpszSubKey* parameter must point to a subkey that:

* Is a child key of the key identified by *hKey*.
* Must not begin with the backslash character ( \ ).
* Must not be **NULL**.

The *lpszSubKey* parameter can point to an empty string, causing [ClusterRegCreateKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatekey) to return a handle to the database key represented by *hKey*.

### `samDesired` [in]

Access mask that specifies the security access needed for the new key.

### `phkResult` [out]

Pointer to a handle to the opened or created key.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Callers should call [ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey) to close the key handle opened by **ClusterRegOpenKey** when they are done with it.

## See also

[ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey)

[ClusterRegCreateKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatekey)