# AUTHZ_ACCESS_REQUEST structure

## Description

The **AUTHZ_ACCESS_REQUEST** structure defines an access check request.

## Members

### `DesiredAccess`

The type of access to test for.

### `PrincipalSelfSid`

The [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) to use for the principal self SID in the [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL).

### `ObjectTypeList`

An array of [OBJECT_TYPE_LIST](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-object_type_list) structures in the object tree for the object. Set to **NULL** unless the application checks access at the property level.

### `ObjectTypeListLength`

The number of elements in the *ObjectTypeList* array. This member is necessary only if the application checks access at the property level.

### `OptionalArguments`

A pointer to memory to pass to [AuthzAccessCheckCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzaccesscheckcallback) when checking callback [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs).

## See also

[AuthzAccessCheckCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzaccesscheckcallback)