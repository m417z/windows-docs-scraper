# BuildSecurityDescriptorW function

## Description

The **BuildSecurityDescriptor** function allocates and initializes a new [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This function can initialize the new security descriptor by merging specified security information with the information in an existing security descriptor. If you do not specify an existing security descriptor, the function initializes a new security descriptor based on the specified security information.

The **BuildSecurityDescriptor** function creates a [self-relative security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The self-relative format makes the security descriptor suitable for storing in a stream.

## Parameters

### `pOwner` [in, optional]

A pointer to a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure that identifies the owner for the new security descriptor. If the structure uses the TRUSTEE_IS_NAME form, **BuildSecurityDescriptor** looks up the
[security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) associated with the specified trustee name.

If this parameter is **NULL**, the function uses the owner SID from the original security descriptor pointed to by *pOldSD*. If *pOldSD* is **NULL**, or if the owner SID in *pOldSD* is **NULL**, the owner SID is **NULL** in the new security descriptor.

### `pGroup` [in, optional]

A pointer to a [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure that identifies the primary group SID for the new security descriptor. If the structure uses the TRUSTEE_IS_NAME form, **BuildSecurityDescriptor** looks up the SID associated with the specified trustee name.

If this parameter is **NULL**, the function uses the group SID from the original security descriptor pointed to by *pOldSD*. If *pOldSD* is **NULL**, or if the group SID in *pOldSD* is **NULL**, the group SID is **NULL** in the new security descriptor.

### `cCountOfAccessEntries` [in]

The number of
[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures in the *pListOfAccessEntries* array.

### `pListOfAccessEntries` [in, optional]

A pointer to an array of [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures that describe access control information for the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) of the new security descriptor. The function creates the new DACL by merging the information in the array with the DACL in *pOldSD*, if any. If *pOldSD* is **NULL**, or if the DACL in *pOldSD* is **NULL**, the function creates a new DACL based solely on the information in the array. For a description of the rules for creating an
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) from an array of **EXPLICIT_ACCESS** structures, see the
[SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla) function.

If *pListOfAccessEntries* is **NULL**, the new security descriptor gets the DACL from *pOldSD*. In this case, if *pOldSD* is **NULL**, or if the DACL in *pOldSD* is **NULL**, the new DACL is **NULL**.

### `cCountOfAuditEntries` [in]

The number of
[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures in the *pListOfAuditEntries* array.

### `pListOfAuditEntries` [in, optional]

A pointer to an array of [EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a) structures that describe audit control information for the SACL of the new security descriptor. The function creates the new SACL by merging the information in the array with the SACL in *pOldSD*, if any. If *pOldSD* is **NULL**, or the SACL in *pOldSD* is **NULL**, the function creates a new SACL based solely on the information in the array.

If *pListOfAuditEntries* is **NULL**, the new security descriptor gets the SACL from *pOldSD*. In this case, if *pOldSD* is **NULL**, or the SACL in *pOldSD* is **NULL**, the new SACL is **NULL**.

### `pOldSD` [in, optional]

A pointer to an existing self-relative
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure and its associated security information. The function builds the new security descriptor by merging the specified owner, group, access control, and audit-control information with the information in this security descriptor. This parameter can be **NULL**.

### `pSizeNewSD` [out]

A pointer to a variable that receives the size, in bytes, of the security descriptor.

### `pNewSD` [out]

A pointer to a variable that receives a pointer to the new security descriptor. The function allocates memory for the new security descriptor. You must call the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function to free the returned buffer.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If the function fails, it returns a nonzero error code defined in WinError.h.

## Remarks

The **BuildSecurityDescriptor** function is intended for trusted servers that implement or expose security on their own objects. The function uses self-relative security descriptors suitable for serializing into a stream and storing to disk, as a trusted server might require.

> [!NOTE]
> The aclapi.h header defines BuildSecurityDescriptor as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[EXPLICIT_ACCESS](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-explicit_access_a)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SetEntriesInAcl](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setentriesinacla)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)