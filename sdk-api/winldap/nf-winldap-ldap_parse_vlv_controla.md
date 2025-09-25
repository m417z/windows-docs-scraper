# ldap_parse_vlv_controlA function

## Description

The **ldap_parse_vlv_control** function is used to find and parse VLV search results.

## Parameters

### `ExternalHandle` [in]

The LDAP session handle.

### `Control` [in]

The address of a NULL-terminated array of [LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola) structures, typically obtained by a call to
[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result).

### `TargetPos` [out]

The numeric position of the target entry in the result set list, as provided by the targetPosition element of the BER-encoded response control ([LDAP_CONTROL_VLVRESPONSE](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvresponse)). If this parameter is **NULL**, the target position is not returned.

### `ListCount` [out]

The server estimate of the number of entries in the list as provided by the contentCount element of the BER-encoded response control ([LDAP_CONTROL_VLVRESPONSE](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvresponse)). If this parameter is **NULL**, the size is not returned.

### `Context` [out]

The server-generated context identifier. If the server does not return a context identifier, this parameter will be set to **NULL**. If **NULL** is passed for contextp, the context identifier is not returned.

### `ErrCode` [out]

The VLV result code, as provided by the virtualListViewResult element of the BER-encoded response control ([LDAP_CONTROL_VLVRESPONSE](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvresponse)). If this parameter is **NULL**, the result code is not returned.

## Return value

This function returns an
[LDAP error code](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) that indicates whether a VLV result control was found and parsed successfully. **LDAP_SUCCESS** is returned if all goes well, **LDAP_CONTROL_MISSING** is returned if the *ctrls* array does not include a response control ([LDAP_CONTROL_VLVRESPONSE](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvresponse)), and another LDAP error code is returned if a parsing error or other issue occurs.

VLV uses the following LDAP return value codes:

**LDAP_OPERATIONS_ERROR**

**LDAP_UNWILLING_TO_PERFORM**

**LDAP_INSUFFICIENT_ACCESS**

**LDAP_BUSY**

**LDAP_TIMELIMIT_EXCEEDED**

**LDAP_ADMINLIMIT_EXCEEDED**

**LDAP_OTHER**

In addition, the following two codes have been added to support VLV:

## Remarks

This control parses the search results returned by the server in the response control ([LDAP_CONTROL_VLVRESPONSE](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvresponse)). A context identifier is passed from the server to the client to identify the control, which must be freed at the end of the session by calling
[ber_bvfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_bvfree).

For more information and a code example, see
[Example Code for Using LDAP VLV](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/example-code-for-using-ldap-vlv).

> [!NOTE]
> The winldap.h header defines ldap_parse_vlv_control as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola)

[LDAPVLVInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapvlvinfo)

[LDAP_CONTROL_VLVREQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvrequest)

[LDAP_CONTROL_VLVRESPONSE](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvresponse)

[Searching with the LDAP VLV Control](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/searching-with-the-ldap-vlv-control)

[ldap_create_sort_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_sort_control)

[ldap_create_vlv_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_vlv_controla)

[ldap_search_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext)

[ldap_search_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext_s)