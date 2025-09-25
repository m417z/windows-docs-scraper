# IAzApplicationGroup::get_LdapQuery

## Description

The **LdapQuery** property sets or retrieves the [Lightweight Directory Access Protocol](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LDAP) query used to define membership for an LDAP query application group.

This property is read/write.

## Parameters

## Remarks

This property is ignored unless the [Type](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_type) property is AZ_GROUPTYPE_LDAP_QUERY.

The maximum length of this property is 4,096 characters.