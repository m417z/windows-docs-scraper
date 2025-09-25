# IAzOperation2::RoleAssignments

## Description

The **RoleAssignments** method returns a collection of the role assignments associated with this operation.

## Parameters

### `bstrScopeName` [in]

The name of the scope in which to check for role assignments. If the value of this parameter is an empty string, the method checks for role assignments at the application level.

### `bRecursive` [in]

**TRUE** if the method checks all scopes within the application; otherwise, **FALSE**. This parameter is ignored if the value of the *bstrScopeName* parameter is not **NULL**.

### `ppRoleAssignments` [out]

The address of a pointer to an [IAzRoleAssignments](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroleassignments) interface that represents the collection of [IAzRoleAssignment](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroleassignment) objects associated with this operation.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).