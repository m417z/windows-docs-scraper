# SECURITY_OBJECT structure

## Description

The **SECURITY_OBJECT** structure contains the security object information.

## Members

### `pwszName`

A pointer to the name.

### `pData`

A pointer to the security data.

### `cbData`

The size, in bytes, of the data pointed to by the **pData** member. This may be zero if **pData** contains the data, such as when the data is an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer, a handle, or data specific to the resource manager that can be stored in **pData** directly without a memory allocation.

### `pData2`

A pointer to the additional security data.

### `cbData2`

The size, in bytes, of the data pointed to by the **pData2** member. This may be zero if **pData2** contains the data, such as when the data is an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer, a handle, or data specific to the resource manager that can be stored in **pData2** directly without a memory allocation.

### `Id`

The identifier for the security object's type. If the **fWellKnown** member is **FALSE**, then the **Id** member has no special significance other than to help resource managers distinguish it from other classes of security objects. If the **fWellKnown** member is **TRUE**, then the **Id** member is one of the following and the entire structure follows the corresponding representation.

| Value | Meaning |
| --- | --- |
| **SECURITY_OBJECT_ID_OBJECT_SD (1)** | The security descriptor of the resource.<br><br>If **Id** is set to this value, then **pData** points to a security descriptor and **cbData** is the number of bytes in **pData**.<br><br>**pData2** is **NULL** and **cbData2** is 0. |
| **SECURITY_OBJECT_ID_SHARE (2)** | The security descriptor of a network share.<br><br>If **Id** is set to this value, then **pData** points to the [ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation) interface of an object that represents the security context of the share.<br><br>If the security descriptor is not yet available, then **pData2** must be a handle to a waitable object that is signaled when the security descriptor is ready when the [GetSecondarySecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation4-getsecondarysecurity) method returns S_FALSE. The waitable object should be created by the [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function. In this case, **cbData2** is 0.<br><br>This identifier is only applicable to file system objects. |
| **SECURITY_OBJECT_ID_CENTRAL_POLICY (3)** | The security descriptor of a central access policy.<br><br>If **Id** is set to this value, then **pData** points to the security descriptor with an empty DACL, an owner, group, and attribute [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) that match the resource's owner, group, and attributes as well as a SCOPE_SECURITY_INFORMATION_ACE that contains the central policy's ID. **cbData** is set to the number of bytes in **pData**.<br><br>**pData2** is **NULL** and **cbData2** is 0.<br><br>The security descriptor is constructed to allow computing effective permissions to correctly determine when access is limited by the central policy and higher detail of the central access rule cannot be determined. This is used when a central access policy that applies to a resource cannot be resolved into its elemental central access rules. |
| **SECURITY_OBJECT_ID_CENTRAL_ACCESS_RULE (4)** | The security descriptor of a central access rule.<br><br>If **Id** is set to this value, then **pData** points to the security descriptor with an owner, group, and attribute ACEs that match the resource's owner, group, and attributes, and a [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) that matches the central access rule's DACL. **cbData** is set to the number of bytes in **pData**.<br><br>In addition, **pData2** points to a security descriptor with a DACL that contains a conditional ACE that grants 0x1 to Everyone if the resource condition from the central access rule evaluates to **TRUE**. **cbData2** is set to the number of bytes in **pData2**.<br><br>The security descriptor is constructed to allow computing effective permissions to determine when access is limited by the central access policy at the highest detail. That is, access is limited by pointing to a central policy rule. |

### `fWellKnown`

**TRUE** if the security object represents one of the well-know security objects listed in the **Id** member.

## Remarks

When the **Id** member the **SECURITY_OBJECT** structure is set to SECURITY_OBJECT_ID_CENTRAL_ACCESS_RULE, the [ComputeEffectivePermissionWithSecondarySecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-ieffectivepermission2-computeeffectivepermissionwithsecondarysecurity) method must use the **pData2** member of first and only then evaluate the access using the **pData** member.

## See also

[IEffectivePermission2::ComputeEffectivePermissionWithSecondarySecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-ieffectivepermission2-computeeffectivepermissionwithsecondarysecurity)

[ISecurityInformation4::GetSecondarySecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation4-getsecondarysecurity)