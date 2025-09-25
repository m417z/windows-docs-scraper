# IGroupPolicyObject::GetDSPath

## Description

The
**GetDSPath** method retrieves the Active Directory path to the root of the specified GPO section.

## Parameters

### `dwSection` [in]

Specifies the GPO section. This parameter can be one of the following values.

#### GPO_SECTION_ROOT

Root section

#### GPO_SECTION_USER

User section

#### GPO_SECTION_MACHINE

Computer section

### `pszPath` [out]

Pointer to a buffer that receives the path, in ADSI format (LDAP://cn=*user*, ou=*users*, dc=*coname*, dc=*com*).

### `cchMaxPath` [in]

Specifies the maximum number of characters that can be stored in the *pszPath* buffer.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

If you call the
**GetDSPath** method and specify a computer GPO, the method succeeds, but on return, the *pszPath* parameter contains an empty string. This is because computer GPOs do not have Active Directory storage; they have only file system storage.

To retrieve the file system path to the root of a GPO section, you can call the
[GetFileSysPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getfilesyspath) method.

## See also

[GetFileSysPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getfilesyspath)

[GetPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getpath)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)