# LDAPSortKeyA structure

## Description

The **LDAPSortKey** structure stores sorting criteria for use by sort controls.

## Members

### `sk_attrtype`

Pointer to a null-terminated string that specifies the name of the attribute to use as a sort key. Use multiple **LDAPSortKey** structures to specify multiple sort keys. Be aware that Active Directory supports only a single sort key.

### `sk_matchruleoid`

Pointer to a null-terminated string that specifies the object identifier of the matching rule for the sort. Should be set to **NULL** if you do not want to explicitly specify a matching rule for the sort. Specifying an explicitly set matching rule is supported only by Windows Server 2003.

### `sk_reverseorder`

If **TRUE**, specifies that the sort be ordered from lowest to highest. If **FALSE**, the sort order is from highest to lowest.

## Remarks

The
[ldap_create_sort_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_sort_control) and
[ldap_search_init_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_init_page) functions use this structure to specify how results should be sorted before being returned to the client.

> [!NOTE]
> The winldap.h header defines LDAPSortKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/data-structures)

[LDAP_SERVER_SORT_OID](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-server-sort-oid)

[Using Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-controls)

[ldap_create_sort_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_sort_control)

[ldap_search_init_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_init_page)