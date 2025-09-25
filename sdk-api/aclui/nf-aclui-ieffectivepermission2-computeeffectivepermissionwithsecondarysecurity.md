# IEffectivePermission2::ComputeEffectivePermissionWithSecondarySecurity

## Description

The **ComputeEffectivePermissionWithSecondarySecurity** method computes the effective permissions for an object. It supports integrating secondary or custom security policies. You may choose to provide this additional security information by implementing the [ISecurityInformation4](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation4) interface. This method supports compound identity, which is when a principal's access token contains user and device authorization information.

## Parameters

### `pSid` [in]

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that represents the security principal whose effective permission is being determined.

### `pDeviceSid` [in, optional]

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that represents the device from which the principal is accessing the object. If this is not **NULL** and you are using the [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) function to compute the effective permissions, then the device SID may be compounded with the *pSid* parameter by using the [AuthzInitializeCompoundContext](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializecompoundcontext) function.

### `pszServerName` [in, optional]

The name of the server on which the object resides. This is the same name that was returned from the [ISecurityInformation::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getobjectinformation) method.

### `pSecurityObjects` [in]

An array of security objects. This array is composed of objects that were deduced by the access control editor in addition to the ones returned from the [ISecurityInformation4::GetSecondarySecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation4-getsecondarysecurity) method.

### `dwSecurityObjectCount` [in]

The number of security objects in the *pSecurityObjects* parameter, and the number of results lists in the *pEffpermResultLists* parameter.

### `pUserGroups` [in, optional]

A pointer to additional user groups that should be used to modify the security context which was initialized from the *pSid* parameter. If you are using the [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) function to compute the effective permissions, then the modification may be done by calling the [AuthzModifySids](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzmodifysids) function using AuthzContextInfoGroupsSids as the *SidClass* parameter.

### `pAuthzUserGroupsOperations` [in, optional]

Pointer to an array of [AUTHZ_SID_OPERATION](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_sid_operation) structures that specify how the user groups in the authz context must be modified for each user group in the *pUserGroups* argument. This array contains as many elements as the number of groups in the *pUserGroups* parameter.

### `pDeviceGroups` [in, optional]

A pointer to additional device groups that should be used to modify the security context which was initialized from the *pSid* parameter or one that was created by compounding the contexts that were initialized from the *pSid* and *pDeviceSid* parameters. If you are using the [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) function to compute the effective permissions, then the modification may be done by calling the [AuthzModifySids](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzmodifysids) function using AuthzContextInfoDeviceSids as the *SidClass* parameter.

### `pAuthzDeviceGroupsOperations` [in, optional]

Pointer to an array of [AUTHZ_SID_OPERATION](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_sid_operation) enumeration types that specify how the device groups in the authz context must be modified for each device group in the *pDeviceGroups* argument. This array contains as many elements as the number of groups in the *pDeviceGroups* parameter.

### `pAuthzUserClaims` [in, optional]

Pointer to an [AUTHZ_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_security_attributes_information) structure that contains the user claims context that should be used to modify the security context that was initialized from the *pSid* parameter. If you are using the [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) function to compute the effective permissions, then the modification may be done by calling the [AuthzModifyClaims](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzmodifyclaims) function using AuthzContextInfoUserClaims as the *ClaimClass* parameter.

### `pAuthzUserClaimsOperations` [in, optional]

Pointer to an [AUTHZ_SECURITY_ATTRIBUTE_OPERATION](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_security_attribute_operation) enumeration type that specifies the operations associated with the user claims context.

### `pAuthzDeviceClaims` [in, optional]

A pointer to the device claims context that should be used to modify the security context that was initialized from the *pSid* parameter or one that was created by compounding the contexts that were initialized from the *pSid* and *pDeviceSid* parameters. This may be supplied by the caller, even if the *pDeviceSid* parameter is not. If you are using the [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) function to compute the effective permissions, then the modification may be done by calling the [AuthzModifyClaims](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzmodifyclaims) function using AuthzContextInfoDeviceClaims as the *ClaimClass* parameter.

### `pAuthzDeviceClaimsOperations` [in, optional]

Pointer to an [AUTHZ_SECURITY_ATTRIBUTE_OPERATION](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_security_attribute_operation) enumeration type that specifies the operations associated with the device claims context.

### `pEffpermResultLists` [in, out]

A pointer to an array of the effective permissions results of type [EFFPERM_RESULT_LIST](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-effperm_result_list). This array is *dwSecurityObjectCount* elements long. The array is initialized by the caller and the implementation is expected to set all fields of each member in the array, indicating what access was granted by the corresponding security object.

If a security object was considered, the **fEvaluated** member should be set to **TRUE**. In this case, the **pObjectTypeList** and **pGrantedAccessList** members should both be **cObjectTypeListLength** elements long. The **pObjectTypeList** member must point to memory that is owned by the resource manager and must remain valid until the [EditSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-editsecurity) function exits. The **pGrantedAccessList** member is freed by the caller by using the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function. If the resource manager does not support object ACEs, then the **pObjectTypeList** member should point to the **NULL** GUID, the **cObjectTypeListLength** member should be 1, and the **pGrantedAccessList** member should be a single **DWORD.**

## Return value

If the function is successful, the return value is S_OK.

If the function is successful but returned an approximate result, the return value is S_FALSE.

If the function fails, the return value is an **HRESULT** that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

When the **Id** member the [SECURITY_OBJECT](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-security_object) structure is set to SECURITY_OBJECT_ID_CENTRAL_ACCESS_RULE, the **ComputeEffectivePermissionWithSecondarySecurity** method should use the **pData2** member first and only then evaluate access by using the **pData** member.

It is expected that the caller will use [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) to determine the effective permissions. When possible, the implementation should initialize a remote resource manager on the supplied **pszServerName** member, using the [AuthzInitializeRemoteResourceManager](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializeremoteresourcemanager) function to ensure that the groups and claims are initialized in the same manner as when the principal really accesses the object. If **AuthzInitializeRemoteResourceManager** fails, the implementation may fall back to using the [AuthzInitializeResourceManager](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializeresourcemanager) function and return S_FALSE to indicate that approximate results are returned.

For each of the secondary security objects whose **fEvaluated** member is set to **TRUE**, the access control editor will display which permissions and properties were limited by that object using the **pwszName** member.

## See also

[AUTHZ_SECURITY_ATTRIBUTE_OPERATION](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_security_attribute_operation)

[AuthzInitializeRemoteResourceManager](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzinitializeremoteresourcemanager)

[IEffectivePermission2](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-ieffectivepermission2)

[ISecurityInformation4::GetSecondarySecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation4-getsecondarysecurity)

[SECURITY_OBJECT](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-security_object)