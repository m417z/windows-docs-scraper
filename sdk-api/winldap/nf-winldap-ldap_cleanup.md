# ldap_cleanup function

## Description

**Warning**

The **ldap_cleanup** function may cause unpredictable
behavior at DLL unload time so, there is no way to safely clean up resources when dynamically loading and
unloading the wldap32.dll.

Because of this, resource leaks can occur on unload of the library. Use of
**ldap_cleanup** is therefore not recommended and, is at
your own risk.

## Parameters

### `hInstance`

This parameter is ignored.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

**Warning** The **ldap_cleanup** function may cause
unpredictable behavior at the DLL unload time. Use is not recommended and is at your own risk.