# ISecurityInformation::GetObjectInformation

## Description

The **GetObjectInformation** method requests information that the access control editor uses to initialize its pages and to determine the editing options available to the user.

## Parameters

### `pObjectInfo` [out]

A pointer to an
[SI_OBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-si_object_info) structure. Your implementation must fill this structure to pass information back to the access control editor.

## Return value

Returns S_OK if successful.

Returns a nonzero error code if an error occurs.

## Remarks

The system does not free the string pointers that you return in the
[SI_OBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-si_object_info) structure.

## See also

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)

[SI_OBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-si_object_info)