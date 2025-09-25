# ISecurityInformation4::GetSecondarySecurity

## Description

The **GetSecondarySecurity** method returns additional security contexts that may impact access to the resource.

## Parameters

### `pSecurityObjects` [out]

An array of [SECURITY_OBJECT](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-security_object) structures that contain the secondary security objects associated with the resources that are set on success. The array is owned by the caller and is freed by using the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function. The **pwszName** member is also freed by using **LocalFree**. If the **cbData** or **cbData2** members of the **SECURITY_OBJECT** structure are not zero, then the caller must free the corresponding **pData** or **pData2** by using **LocalFree**. If either of those members are zero, then the corresponding **pData** and **pData2** members are owned by the resource manager and must remain valid until the [EditSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-editsecurity) function returns

### `pSecurityObjectCount` [out]

The number of security objects in the *pSecurityObjects* parameter that are set on success.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

A resource manager does not need to return secondary objects with the **fWellKnown** member set to **TRUE** and the **Id** member set to SECURITY_OBJECT_ID_OBJECT_SD, SECURITY_OBJECT_ID_CENTRAL_POLICY, or SECURITY_OBJECT_ID_CENTRAL_ACCESS_RULE. Security objects with these IDs will be provided by the access control editor when calling [ComputeEffectivePermissionWithSecondarySecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-ieffectivepermission2-computeeffectivepermissionwithsecondarysecurity).

Interpretation of the returned security objects is tied to the implementation of [ComputeEffectivePermissionWithSecondarySecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-ieffectivepermission2-computeeffectivepermissionwithsecondarysecurity).

## See also

[ISecurityInformation4](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation4)