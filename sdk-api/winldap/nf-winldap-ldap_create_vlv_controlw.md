# ldap_create_vlv_controlW function

## Description

The **ldap_create_vlv_control** function is used to create the request control ([LDAP_CONTROL_VLVREQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvrequest)) on the server.

## Parameters

### `ExternalHandle` [in]

An LDAP session handle, as obtained from a call to [ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init).

### `VlvInfo` [in]

The address of an [LDAPVLVInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapvlvinfo) structure whose contents are used to construct the value of the control created.

### `IsCritical` [in]

If this value is not zero, the control created will have its criticality set to **TRUE**.

### `Control` [out]

A result parameter assigned the address of an [LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola) structure that contains the request control ([LDAP_CONTROL_VLVREQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvrequest)) created by this function.

## Return value

The **ldap_create_vlv_control** function returns an
[LDAP error code](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) to indicate failure, or LDAP_SUCCESS if successful.

## Remarks

When a VLV search is conducted, the client must use this function to create a new VLV control that can be included in the search request sent to the server. The server will assign a contextID for this VLV search, passed to the client. When the VLV search is completed, you should use [ldap_control_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_control_free) to free the control returned by **ldap_create_vlv_control**, and [ldap_controls_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_controls_free) to free the array of controls, including the VLV response control, returned by [ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result).

For more information, and a code example for this function, see
[Example Code for Using LDAP VLV](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/example-code-for-using-ldap-vlv).

> [!NOTE]
> The winldap.h header defines ldap_create_vlv_control as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola)

[LDAPVLVInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapvlvinfo)

[LDAP_CONTROL_VLVREQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvrequest)

[LDAP_CONTROL_VLVRESPONSE](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvresponse)

[Searching with the LDAP VLV Control](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/searching-with-the-ldap-vlv-control)

[ldap_create_sort_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_sort_control)

[ldap_parse_vlv_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_vlv_controla)

[ldap_search_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext)

[ldap_search_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext_s)