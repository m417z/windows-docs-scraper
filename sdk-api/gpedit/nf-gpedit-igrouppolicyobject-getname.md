# IGroupPolicyObject::GetName

## Description

The
**GetName** method retrieves the unique GPO name.

For Active Directory policy objects, the method returns a GUID. For a local GPO, the method returns the string "Local". For remote objects,
**GetName** returns the computer name.

## Parameters

### `pszName` [out]

Pointer to a buffer that receives the GPO name.

### `cchMaxLength` [in]

Specifies the size, in characters, of the *pszName* buffer.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To retrieve the display name for a GPO, you can call the
[GetDisplayName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getdisplayname) method.

## See also

[GetDisplayName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getdisplayname)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)