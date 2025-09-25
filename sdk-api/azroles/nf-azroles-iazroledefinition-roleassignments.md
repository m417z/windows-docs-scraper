# IAzRoleDefinition::RoleAssignments

## Description

The **RoleAssignments** function retrieves a collection of [IAzRoleAssignment](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazroleassignment) objects that represent the role assignments associated with this [IAzRoleDefinition](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazroledefinition) object.

This property is read-only.

## Parameters

### `bstrScopeName`

Provides a scope name to include in the search for **IAzRoleAssignment** objects. If this parameter is **NULL**, the search is performed in the global scope.

### `bRecursive`

Indicates if the search for **IAzRoleAssignment** objects should be performed recursively.

### `ppRoleAssignments`

The collection of **IAzRoleAssignment** objects that represent the role assignments associated with this **IAzRoleDefinition** object.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## See also

[IAzRoleAssignment](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazroleassignment)

[IAzRoleDefinition](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazroledefinition)