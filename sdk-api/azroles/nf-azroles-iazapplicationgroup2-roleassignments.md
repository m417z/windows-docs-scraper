# IAzApplicationGroup2::RoleAssignments

## Description

The **RoleAssignments** method gets a collection of [IAzRoleAssignment](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazroleassignment) objects associated with this application group.

This property is read-only.

## Parameters

### `bstrScopeName`

Provides a scope name to include in the search for **IAzRoleAssignment** objects. If this parameter is **NULL**, the search is performed in the global scope.

### `bRecursive`

Indicates if the search for **IAzRoleAssignment** objects should be performed recursively.

### `ppRoleAssignments`

The list of [IAzRoleAssignment](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazroleassignment) objects associated with the specified application group.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## See also

[IAzRoleAssignment](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazroleassignment)