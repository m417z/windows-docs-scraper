# SetSecurityDescriptorControl function

## Description

The **SetSecurityDescriptorControl** function sets the control bits of a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The function can set only the control bits that relate to automatic inheritance of ACEs. To set the other control bits of a security descriptor, use the functions, such as
[SetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl), for modifying the components of a security descriptor.

## Parameters

### `pSecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure whose control and revision information are set.

### `ControlBitsOfInterest` [in]

A
[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control) mask that indicates the control bits to set.

### `ControlBitsToSet` [in]

A
[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control) mask that indicates the new values for the control bits specified by the *ControlBitsOfInterest* mask.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **SetSecurityDescriptorControl** function specifies the control bit or bits to modify, and whether the bits are on or off.

#### Examples

The following example marks the DACL on the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) as protected.

```cpp
    SetSecurityDescriptorControl( &SecDesc,
            SE_DACL_PROTECTED, SE_DACL_PROTECTED );

```

The following example marks the DACL as not protected.

```cpp
    SetSecurityDescriptorControl( &SecDesc,
            SE_DACL_PROTECTED, 0 );

```

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GetSecurityDescriptorControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorcontrol)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control)

[SetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl)