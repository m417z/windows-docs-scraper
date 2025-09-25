# LDAPAPIFeatureInfoW structure

## Description

The **LDAPAPIFeatureInfo** structure retrieves data about any supported LDAP API extensions.

## Members

### `ldapaif_info_version`

The version of this structure, which must be set to **LDAP_FEATURE_INFO_VERSION** before the call to [ldap_get_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_option) is performed.

### `ldapaif_name`

A pointer to a null-terminated string that contains the name of the desired API extension. This value is set before the call to [ldap_get_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_option) is performed, and should match one of the strings returned in the **ldapai_extensions** member of [LDAPAPIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapapiinfoa) set from a previous call to **ldap_get_option**.

### `ldapaif_version`

The vendor API extension version number. This implementation returns an integer value in the format of MMnnn, where MM is the major version number * 1000, and nnn is the minor version number. For example, version 1.001 would be returned as the number 1001.

## Remarks

A pointer to this structure is passed, along with the [LDAP_FEATURE_API_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options) session option and the name of the desired API extension, to [ldap_get_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_option), to retrieve detailed data about the LDAP API extension.

> [!NOTE]
> The winldap.h header defines LDAPAPIFeatureInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LDAPAPIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapapiinfoa)

[Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options)

[ldap_get_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_option)