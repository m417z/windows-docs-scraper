# LDAPModW structure

## Description

The **LDAPMod** structure holds data required to perform a modification operation.

## Members

### `mod_op`

Specifies one of the following values to indicate the modification operation to perform.

You can use the bitwise **OR** operator to combine the operation value with **LDAP_MOD_BVALUES** to indicate that the **mod_vals** union uses the **modv_bvals** member. If **LDAP_MOD_BVALUES** is not set, the union uses the **modv_strvals** member.

#### LDAP_MOD_ADD (0x00)

Adds a value to the entry. The supplied values are appended to the existing values in the attribute.

#### LDAP_MOD_DELETE (0x01)

Deletes a value in the entry. The supplied values are deleted from the current attribute values.

#### LDAP_MOD_REPLACE (0x02)

Replaces a value in the entry. The supplied values replace the existing attribute values.

### `mod_type`

Pointer to a null-terminated string that specifies the name of the attribute to modify.

### `mod_vals`

Pointer to an array of values, if any, to add, delete, or replace. If **mop_op** does not include the LDAP_MOD_BVALUES flag, the **modv_strvals** member is a pointer to an array of null-terminated strings. If **mop_op** includes LDAP_MOD_BVALUES, the **modv_bvals** member is a pointer to an array of
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) pointers, which is useful for specifying binary values.

### `mod_vals.modv_strvals`

Pointer to a null-terminated array of null-terminated strings. The last element of the array must be a **NULL** pointer.

### `mod_vals.modv_bvals`

Pointer to a **NULL**-terminated array of [berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) pointers. The last element of the array must be a **NULL** pointer.

##### - mod_op.LDAP_MOD_ADD (0x00)

Adds a value to the entry. The supplied values are appended to the existing values in the attribute.

##### - mod_op.LDAP_MOD_DELETE (0x01)

Deletes a value in the entry. The supplied values are deleted from the current attribute values.

##### - mod_op.LDAP_MOD_REPLACE (0x02)

Replaces a value in the entry. The supplied values replace the existing attribute values.

## Remarks

Assign values to the fields of the **LDAPMod** structure before you call a modification function (
[ldap_add*](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add), or
[ldap_modify*](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify)).

[ldap_modify*](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_s) with the **LDAP_MOD_REPLACE** operation does not delete an attribute when passed a null pointer. However, **LDAP_MOD_DELETE** deletes the entire attribute when **mod_vals** is set to **NULL**.

When passing a **LDAPMod** structure into the [ldap_add*](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add) functions, only the **LDAP_MOD_BVALUES** flag is significant. Creating a new object implies adding values to it.

> [!NOTE]
> The winldap.h header defines LDAPMod as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/data-structures)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)

[ldap_add](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add)

[ldap_modify](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify)

[ldap_modify_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_s)