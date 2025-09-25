# ldap_create_page_control function

## Description

Use the **ldap_create_page_control** function to create a basic control for paging results. Support for controls is available effective with LDAP 3, but whether the page control is supported or not is dependent on the particular server.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `PageSize` [in]

The number of entries to return in each page.

### `Cookie` [in]

Pointer to a
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structure that the server uses to determine its location in the result set. This is an opaque structure that you should not access directly. Set to **NULL** for the first call to **ldap_create_page_control**.

### `IsCritical` [in]

Notifies the server whether this control is critical to the search.

### `Control` [out]

Pointer to the newly created control.

## Return value

This function returns WINLDAPAPI ULONG LDAPAPI.

## Remarks

The **ldap_create_page_control** function creates a simple paged-results control. The control enables the client to specify the rate at which an LDAP server returns the results of a search operation. This is useful when the client has limited resources and may not be able to process the entire result set from a given LDAP query, or when the client/server connection is slow.

To create the paged-results control, specify the number of entries to be returned in a single page. To return results normally, even if it cannot support this control, set the *IsCritical* parameter to **FALSE**.

This function creates the control - it does not verify that the server supports it, and consequently, does not return **LDAP_UNAVAILABLE_CRIT_EXTENSION** if the server does not support the control. However, it can return other standard LDAP return values, such as **LDAP_NO_MEMORY** or **LDAP_PARAM_ERROR**.

When **ldap_create_page_control** returns successfully, include the newly created control to the list of server controls in a call to
[ldap_search_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext) or to
[ldap_search_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext_s). When the server returns the first page of results, call
[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result) to retrieve the first page of results.

Call
[ldap_control_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_control_free) when the control is no longer required.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP_PAGED_RESULT_OID_STRING](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-paged-result-oid-string)

[ldap_control_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_control_free)

[ldap_parse_page_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_page_control)

[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result)

[ldap_search_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext)

[ldap_search_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext_s)