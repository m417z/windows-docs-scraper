# ClusterRegCreateKey function

## Description

Creates a specified [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key. If the key
already exists in the database,
**ClusterRegCreateKey** opens it without making
changes.

## Parameters

### `hKey` [in]

Handle to an open cluster database key. This parameter cannot be **NULL**.

### `lpszSubKey` [in]

Pointer to a null-terminated Unicode string specifying the name of the subkey to be created or opened. The
*lpszSubKey* parameter must point to a subkey that:

* Is a child key of the key identified by *hKey*.
* Must not begin with the backslash character ( \ ).
* Must not be **NULL**.

The *lpszSubKey* parameter can point to an empty string, causing
**ClusterRegCreateKey** to return a handle to the
database key represented by *hKey*.

### `dwOptions` [in]

Specifies special options for this key. Currently, *dwOptions* can be set to the
following value.

#### REG_OPTION_NON_VOLATILE (0x00000000)

The opened or created key is not volatile; the information is preserved when the system is restarted.

### `samDesired` [in]

Access mask that specifies the needed security access for the new key. The following values are valid.

For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

#### ACCESS_SYSTEM_SECURITY (0x01000000)

Permission to access system security. It is used to indicate access to a
[system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL). This type of
access requires the calling process to have the **SE_SECURITY_NAME** (Manage auditing
and security log) privilege.

#### DELETE (0x00010000)

Permission to delete.

#### KEY_ALL_ACCESS (0x000F003F)

Combination of **KEY_QUERY_VALUE**, **KEY_ENUMERATE_SUB_KEYS**,
**KEY_NOTIFY**, **KEY_CREATE_SUB_KEY**,
**KEY_CREATE_LINK**, and **KEY_SET_VALUE** access.

#### KEY_CREATE_LINK (0x00000020)

Permission to create a symbolic link.

#### KEY_ENUMERATE_SUB_KEYS (0x00000008)

Permission to enumerate subkeys.

#### KEY_EXECUTE (0x00020019)

Permission for read access.

#### KEY_NOTIFY (0x00000010)

Permission for change notification.

#### KEY_QUERY_VALUE (0x00000001)

Permission to query subkey data.

#### KEY_READ (0x00020019)

Combination of **KEY_QUERY_VALUE**, **KEY_ENUMERATE_SUB_KEYS**,
and **KEY_NOTIFY** access.

#### KEY_SET_VALUE (0x00000002)

Permission to change subkey data.

#### KEY_WRITE (0x00020006)

Combination of **KEY_SET_VALUE** and **KEY_CREATE_SUB_KEY**
access.

#### READ_CONTROL (0x00020000)

Permission to read the owner, group, and
[discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly)
(DACL) of the security descriptor.

#### WRITE_DAC (0x00040000)

Permission to write to the DACL.

#### WRITE_OWNER (0x00080000)

Permission to change the owner.

### `lpSecurityAttributes` [in, optional]

This parameter is ignored. To set the security attributes on a new registry key, call the
[ClusterRegSetKeySecurity](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregsetkeysecurity) function after
**ClusterRegCreateKey** has returned
successfully.

### `phkResult` [out]

Pointer to the handle of the opened or created key.

### `lpdwDisposition` [out, optional]

Pointer to a value that describes whether the key pointed to by *lpszSubKey* was
opened or created. The following values are valid.

#### REG_CREATED_NEW_KEY (0x00000001)

The key did not exist and was created.

#### REG_OPENED_EXISTING_KEY (0x00000002)

The key existed and was opened.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Callers should call [ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey) to close
the key handle created by the **ClusterRegCreateKey**
function when they are done with it.

Do not call **ClusterRegCreateKey** from the
following resource DLL entry point functions:

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ClusterRegCreateKey** can be safely called from
any other resource DLL entry point function or from a worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)

[ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey)

[ClusterRegDeleteKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregdeletekey)

[ClusterRegOpenKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregopenkey)