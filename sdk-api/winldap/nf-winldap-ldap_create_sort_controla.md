# ldap_create_sort_controlA function

## Description

The **ldap_create_sort_control** function is used to format a list of sort keys into a search control. Support for controls is available effective with LDAP 3, but whether the sort control is supported or not is dependent on the particular server.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `SortKeys` [in]

Pointer to an array of
[LDAPSortKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapsortkeya) structures. Each structure in the array specifies the name of an attribute to use as a sort key, the matching rule for that key, and whether the sort order is ascending or descending.

### `IsCritical` [in]

Notifies the server whether this control is critical to the search. 0 ==> FALSE, !0 ==> TRUE.

### `Control` [out]

Pointer to the newly created control.

## Return value

This function returns WINLDAPAPI ULONG LDAPAPI.

## Remarks

The **ldap_create_sort_control** function creates a basic sort control. Such a control is useful when the LDAP client has limited functionality and cannot sort results, yet needs them sorted.

The sort controls allow a server to return a result code for the sorting of the results that is independent of the result code returned for the search operation.

This function creates the control — it does not verify that the server supports it, and consequently, does not return LDAP_UNAVAILABLE_CRIT_EXTENSION if the server does not support the control. However, it can return other standard LDAP return values, such as LDAP_NO_MEMORY or LDAP_PARAM_ERROR.

To free the control when it is no longer required, call
[ldap_control_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_control_free).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAPSortKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapsortkeya)

[LDAP_SERVER_SORT_OID](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-server-sort-oid)

[ldap_control_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_control_free)