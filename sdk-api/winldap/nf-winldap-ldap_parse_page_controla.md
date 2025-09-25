# ldap_parse_page_controlA function

## Description

The **ldap_parse_page_control** parses the results of a search into pages.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `ServerControls` [in]

An array of controls that includes a page control. The page control contains the cookie and total count fields returned by the server.

### `TotalCount` [out]

A pointer to the total count of entries returned in this page (optional).

### `Cookie` [out]

An opaque cookie, used by the server to determine its location in the result set. Use ber_bvfree to free.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

Use **ldap_parse_page_control** in conjunction with
[ldap_create_page_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_page_control) and
[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result) to implement the simple paging of results by means of controls. After calling **ldap_parse_page_control** to retrieve the server controls and extract the cookie from the search result, call **ldap_parse_result** to parse the results. Then use the cookie to call **ldap_create_page_control** to retrieve the next page of results.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_create_page_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_page_control)

[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result)