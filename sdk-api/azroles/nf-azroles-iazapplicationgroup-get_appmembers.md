# IAzApplicationGroup::get_AppMembers

## Description

The **AppMembers** property retrieves the application groups that belong to this application group.

This property is read-only.

## Parameters

## Remarks

This property allows the nesting of [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) objects within another **IAzApplicationGroup** object.

In JScript, the returned [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) must be converted to the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object.