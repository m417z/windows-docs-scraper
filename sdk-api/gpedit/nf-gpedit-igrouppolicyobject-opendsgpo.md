# IGroupPolicyObject::OpenDSGPO

## Description

The
**OpenDSGPO** method opens the specified GPO and optionally loads the registry information.

## Parameters

### `pszPath` [in]

Specifies the Active Directory path of the object to open. If the path specifies a domain controller, the GPO is created on that DC. Otherwise, the system will select a DC on the caller's behalf.

### `dwFlags` [in]

Specifies whether or not the registry information should be loaded for the GPO. This parameter can be one of the following values.

#### GPO_OPEN_LOAD_REGISTRY

Load the registry information.

#### GPO_OPEN_READ_ONLY

Open the GPO in read-only mode.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To create a new GPO in the Active Directory, you can call the
[New](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-new) method.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)

[New](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-new)