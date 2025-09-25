# IAzApplicationGroup::get_MembersName

## Description

The **MembersName** property retrieves the account names of accounts that belong to the application group.

This property is read-only.

## Parameters

## Remarks

This property is ignored unless the [Type](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_type) property is AZ_GROUPTYPE_BASIC.

In JScript, the returned [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) must be converted to the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object.