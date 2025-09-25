# IGroupPolicyObject::New

## Description

The
**New** method creates a new GPO in the Active Directory with the specified display name. The method opens the GPO using the
[OpenDSGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-opendsgpo) method.

## Parameters

### `pszDomainName` [in]

Specifies the Active Directory path of the object to create. If the path specifies a domain controller, the GPO is created on that DC. Otherwise, the system will select a DC on the caller's behalf.

### `pszDisplayName` [in]

Specifies the display name of the object to create.

### `dwFlags` [in]

Specifies whether or not the registry information should be loaded for the GPO. This parameter can be one of the following values.

#### GPO_OPEN_LOAD_REGISTRY

Load the registry information.

#### GPO_OPEN_READ_ONLY

Open the GPO in read-only mode.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To open a GPO that already exists, you can call the
[OpenDSGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-opendsgpo) method.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)

[OpenDSGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-opendsgpo)