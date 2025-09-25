# ISecurityObjectTypeInfo::GetInheritSource

## Description

The **GetInheritSource** method provides a means of determining the source of inherited [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) in [discretionary access control lists](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACLs) and [system access control lists](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACLs).

## Parameters

### `si` [in]

A [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure that represents the security information of the object.

### `pACL` [in]

A pointer to an [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure that represents the [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) of the object.

### `ppInheritArray` [out]

A pointer to a pointer to an [INHERITED_FROM](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-inherited_froma) structure that receives an array of **INHERITED_FROM** structures. The length of this array is the same as the number of [ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace) in the ACL referenced by *pACL*. Each **INHERITED_FROM** entry in *ppInheritArray* provides inheritance information for the corresponding **ACE** entry in *pACL*.

## Return value

If the function is successful, the return value is S_OK.

If the function fails, the return value is an **HRESULT** that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).