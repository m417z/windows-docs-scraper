# LookupSecurityDescriptorPartsW function

## Description

The **LookupSecurityDescriptorParts** function retrieves security information from a [self-relative security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `ppOwner` [out, optional]

A pointer to a variable that receives a pointer to a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure. The function looks up the name associated with the owner
[security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) in the *pSD* [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), and returns a pointer to the name in the **ptstrName** member of the **TRUSTEE** structure. The function sets the **TrusteeForm** member to TRUSTEE_IS_NAME.

This parameter can be **NULL** if you are not interested in the name of the owner.

### `ppGroup` [out, optional]

A pointer to a variable that receives a pointer to a [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure. The function looks up the name associated with the primary group SID of the security descriptor, and returns a pointer to the name in the **ptstrName** member of the **TRUSTEE** structure. The function sets the **TrusteeForm** member to TRUSTEE_IS_NAME.

This parameter can be **NULL** if you are not interested in the name of the group.

### `pcCountOfAccessEntries` [out, optional]

A pointer to a **ULONG** that receives the number of
[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures returned in the *pListOfAccessEntries* array. This parameter can be **NULL** only if the *pListOfAccessEntries* parameter is also **NULL**.

### `ppListOfAccessEntries` [out, optional]

A pointer to a variable that receives a pointer to an array of [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures that describe the [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) in the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) of the security descriptor. The
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure in these **EXPLICIT_ACCESS** structures use the TRUSTEE_IS_NAME form. For a description of how an array of **EXPLICIT_ACCESS** structures describes the ACEs in an
[access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL), see the
[GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla) function. If this parameter is **NULL**, the *cCountOfAccessEntries* parameter must also be **NULL**.

### `pcCountOfAuditEntries` [out, optional]

A pointer to a **ULONG** that receives the number of [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures returned in the *pListOfAuditEntries* array. This parameter can be **NULL** only if the *pListOfAuditEntries* parameter is also **NULL**.

### `ppListOfAuditEntries` [out, optional]

A pointer to a variable that receives a pointer to an array of [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures that describe the ACEs in the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) of the security descriptor. The [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure in these **EXPLICIT_ACCESS** structures uses the TRUSTEE_IS_NAME form. If this parameter is **NULL**, the *cCountOfAuditEntries* parameter must also be **NULL**.

### `pSD` [in]

A pointer to an existing [self-relative security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) from which the function retrieves security information.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If the function fails, it returns a nonzero error code defined in WinError.h.

## Remarks

The **LookupSecurityDescriptorParts** function retrieves the names of the owner and primary group of the security descriptor. This function also returns descriptions of the ACEs in the DACL and audit-control entries in the SACL of the security descriptor.

The parameters other than *pSD* can be **NULL** if you are not interested in the information. If you do not want information about the DACL, both *pListOfAccessEntries* and *cCountOfAuditEntries* must be **NULL**. If you do not want information about the SACL, both *pListOfAuditEntries* and *cCountOfAuditEntries* must be **NULL**. Similarly, if you do want DACL or SACL information, both of the corresponding parameters must not be **NULL**.

When you have finished using any of the buffers returned by the *pOwner*, *pGroup*, *pListOfAccessEntries*, or *pListOfAuditEntries* parameters, free them by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

The **LookupSecurityDescriptorParts** function is intended for trusted servers that implement or expose security on their own objects. The function works with a self-relative security descriptor suitable for serializing into a stream and storing to disk, as a trusted server might require.

> [!NOTE]
> The aclapi.h header defines LookupSecurityDescriptorParts as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a)

[GetExplicitEntriesFromAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getexplicitentriesfromacla)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)