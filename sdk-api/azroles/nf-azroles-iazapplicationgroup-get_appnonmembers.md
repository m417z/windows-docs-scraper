# IAzApplicationGroup::get_AppNonMembers

## Description

The **AppNonMembers** property retrieves the application groups that are refused membership in this application group.

This property is read-only.

## Parameters

## Remarks

Denying membership to an account in an application group does not prevent that account from being assigned to a role through a different application group, nor from being granted permission to a resource through assignment to any other role.

In JScript, the returned [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) must be converted to the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object.