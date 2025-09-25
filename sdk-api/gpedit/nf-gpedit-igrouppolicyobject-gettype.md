# IGroupPolicyObject::GetType

## Description

The
**GetType** method retrieves type information for the GPO being edited.

## Parameters

### `gpoType` [out]

Receives the GPO type. The system sets this parameter to one of the following values.

#### GPOTypeDS

Active Directory

#### GPOTypeLocal

Local

#### GPOTypeRemote

Remote

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)