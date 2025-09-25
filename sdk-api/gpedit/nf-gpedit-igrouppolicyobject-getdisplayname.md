# IGroupPolicyObject::GetDisplayName

## Description

The
**GetDisplayName** method retrieves the display name for the GPO.

## Parameters

### `pszName` [out]

Pointer to a buffer that receives the display name.

### `cchMaxLength` [in]

Specifies the size, in characters, of the *pszName* buffer.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To set the display name for a GPO, you can call the
[SetDisplayName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-setdisplayname) method. Call
[GetName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getname) to retrieve the unique name for a GPO, which is a GUID for an Active Directory object.

## See also

[GetName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getname)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)

[SetDisplayName](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-setdisplayname)