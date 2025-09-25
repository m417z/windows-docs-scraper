# IAzApplicationGroup::get_NonMembers

## Description

The **NonMembers** property retrieves the [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs), in text form, of accounts that are refused membership in the application group.

This property is read-only.

## Parameters

## Remarks

The application group will never have an account specified by this property as a member, even if that account is specified directly or indirectly by the [Members](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_members) property.

This property is ignored unless the [Type](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-get_type) property is AZ_GROUPTYPE_BASIC.

In JScript, the returned [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) must be converted to the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object.

Denying membership to an account in an application group does not prevent that account from being assigned to a role through a different application group, nor from being granted permission to a resource through assignment to any other role.