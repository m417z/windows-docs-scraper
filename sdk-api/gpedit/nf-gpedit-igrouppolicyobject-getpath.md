# IGroupPolicyObject::GetPath

## Description

The
**GetPath** method retrieves the path to the GPO.

## Parameters

### `pszPath` [out]

Pointer to a buffer that receives the path. If the GPO is an Active Directory object, the path is in ADSI name format. If the GPO is a computer object, this parameter receives a file system path.

### `cchMaxLength` [in]

Specifies the maximum number of characters that can be stored in the *pszPath* buffer.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## See also

[GetDSPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getdspath)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)