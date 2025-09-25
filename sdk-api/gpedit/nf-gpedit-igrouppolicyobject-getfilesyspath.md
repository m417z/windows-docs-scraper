# IGroupPolicyObject::GetFileSysPath

## Description

The
**GetFileSysPath** method retrieves the file system path to the root of the specified GPO section. The path is in UNC format.

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

Pointer to a buffer that receives the path.

### `cchMaxPath` [in]

Specifies the maximum number of characters that can be stored in the *pszPath* buffer.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To retrieve the Active Directory path to the root of a GPO section, you can call the
[GetDSPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getdspath) method.

## See also

[GetDSPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getdspath)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)