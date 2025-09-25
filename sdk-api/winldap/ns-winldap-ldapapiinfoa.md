# LDAPAPIInfoA structure

## Description

The **LDAPAPIInfo** structure retrieves data about the API and implementations used.

## Members

### `ldapai_info_version`

The version of this structure, which must be set to **LDAP_API_INFO_VERSION** before a call to [ldap_get_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_option).

### `ldapai_api_version`

The current revision number of this LDAP API library.

### `ldapai_protocol_version`

The latest LDAP version supported by this LDAP API library.

### `ldapai_extensions`

Pointer to an array of null-terminated strings that indicate what API extensions are supported.

### `ldapai_vendor_name`

Pointer to a null-terminated string that contains the name of the API vendor. This implementation returns the string ""Microsoft Corporation."".

### `ldapai_vendor_version`

The API vendor version number. This implementation returns an integer value in the format of MMnn, where MM is the major version number * 100, and nn is the minor version number. For example, version 5.10 is returned as 510.

## Remarks

A pointer to this structure is passed with the [LDAP_OPT_API_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options) session option, to [ldap_get_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_option), to retrieve data about this LDAP API library. The data returned includes a list of any API extensions supported by the implementation. When the structure data is no longer required, the caller must free the individual strings and string arrays returned in this structure by using the [ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree) and [ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free) functions.

> [!NOTE]
> The winldap.h header defines LDAPAPIInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options)

[ldap_get_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_option)

[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree)

[ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free)