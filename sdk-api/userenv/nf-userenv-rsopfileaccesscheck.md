# RsopFileAccessCheck function

## Description

The
**RSoPFileAccessCheck** function determines whether a file's security descriptor grants a specified set of file access rights to the client identified by an **RSOPTOKEN**.

## Parameters

### `pszFileName` [in]

Pointer to the name of the relevant file. The file must already exist.

### `pRsopToken` [in]

Pointer to a valid **RSOPTOKEN** representing the client attempting to gain access to the file.

### `dwDesiredAccessMask` [in]

Specifies an access mask that indicates the access rights to check. This mask can contain a combination of
[generic](https://learn.microsoft.com/windows/desktop/SecAuthZ/generic-access-rights),
[standard](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights), and specific access rights. For more information, see
[Access Rights and Access Masks](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-and-access-masks).

### `pdwGrantedAccessMask` [out]

Pointer to an access mask that receives the granted access rights.

If the function succeeds, the *pbAccessStatus* parameter is set to **TRUE**, and the mask is updated to contain the standard and specific rights granted. If *pbAccessStatus* is set to **FALSE**, this parameter is set to zero. If the function fails, the mask is not modified.

### `pbAccessStatus` [out]

Pointer to a variable that receives the results of the access check.

If the function succeeds, and the requested set of access rights are granted, this parameter is set to **TRUE**. Otherwise, this parameter is set to **FALSE**. If the function fails, the status is not modified.

## Return value

If the function succeeds, the return value is **S_OK**. Otherwise, the function returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

The
**RSoPFileAccessCheck** function indicates, in the *pbAccessStatus* parameter, whether access is granted or denied to the client identified by the **RSOPTOKEN**. If access is granted, the requested access mask becomes the object's granted access mask.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[RSoPAccessCheckByType](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-rsopaccesscheckbytype)