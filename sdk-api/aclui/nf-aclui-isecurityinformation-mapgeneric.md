# ISecurityInformation::MapGeneric

## Description

The **MapGeneric** method requests that the generic access rights in an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) be mapped to their corresponding standard and specific access rights. For more information about generic, standard, and specific access rights, see
[Access Rights and Access Masks](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-and-access-masks).

## Parameters

### `pguidObjectType` [in]

A pointer to a
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the type of object to which the [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) applies. If this member is **NULL** or a pointer to GUID_NULL, the access mask applies to the object itself.

### `pAceFlags` [in]

A pointer to the **AceFlags** member of the
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure from the ACE whose access mask is being mapped.

### `pMask` [in]

A pointer to an access mask that contains the generic access rights to map. Your implementation must map the generic access rights to the corresponding standard and specific access rights for the specified object type.

## Return value

If the function succeeds, the function returns S_OK.

 If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Your **MapGeneric** implementation can call the
[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask) function to map the generic access rights in the access mask.

## See also

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header)

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateSecurityPage](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-createsecuritypage)

[EditSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-editsecurity)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)

[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask)