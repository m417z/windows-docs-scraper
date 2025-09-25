# ADS_SORTKEY structure

## Description

The **ADS_SORTKEY** structure specifies how to sort a query.

## Members

### `pszAttrType`

The null-terminated Unicode string that contains the attribute type.

### `pszReserved`

Reserved.

### `fReverseorder`

Reverse the order of the sorted results.

## Remarks

In Active Directory, if **TRUE**, the **fReverseorder** member specifies that the sort results be ordered from the lowest to the highest.

When using the LDAP system provider, the **pszReserved** member corresponds to the **sk_matchruleoid** of the [LDAPSortKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapsortkeya) structure and may be set to a NULL-terminated string that specifies the object identifier (OID) of the matching rule for the sort. For more information, see **LDAPSortKey**.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)