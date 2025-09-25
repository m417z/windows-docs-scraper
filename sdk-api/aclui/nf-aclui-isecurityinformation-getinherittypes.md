# ISecurityInformation::GetInheritTypes

## Description

The **GetInheritTypes** method requests information about how ACEs can be inherited by child objects. For more information, see
[ACE Inheritance](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace-inheritance).

## Parameters

### `ppInheritTypes` [out]

A pointer to a variable you should set to a pointer to an array of
[SI_INHERIT_TYPE](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-si_inherit_type) structures. The array should include one entry for each combination of inheritance flags and child object type that you support.

### `pcInheritTypes` [out]

A pointer to a variable that you should set to indicate the number of entries in the *ppInheritTypes* array.

## Return value

Returns S_OK if successful.

Returns a nonzero error code if an error occurs.

## Remarks

The access control editor does not free the pointer returned in *ppInheritTypes*.

## See also

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateSecurityPage](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-createsecuritypage)

[EditSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-editsecurity)

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)

[SI_INHERIT_TYPE](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-si_inherit_type)