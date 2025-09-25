# IGroupPolicyObject::GetMachineName

## Description

The
**GetMachineName** method retrieves the computer name of the remote GPO. This is the name specified by the
[OpenRemoteMachineGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-openremotemachinegpo) method.

## Parameters

### `pszName` [out]

Pointer to a buffer that receives the computer name.

### `cchMaxLength` [in]

Specifies the size, in characters, of the *pszName* buffer.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)

[OpenRemoteMachineGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-openremotemachinegpo)