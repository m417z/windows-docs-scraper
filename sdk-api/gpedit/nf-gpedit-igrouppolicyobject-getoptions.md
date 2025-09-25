# IGroupPolicyObject::GetOptions

## Description

The
**GetOptions** method retrieves the options for the GPO.

## Parameters

### `dwOptions` [out]

Receives the options. This parameter can be one or more of the following options.

#### GPO_OPTION_DISABLE_USER

The user portion of the GPO is disabled.

#### GPO_OPTION_DISABLE_MACHINE

The computer portion of the GPO is disabled.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To set the options for a GPO, you can call the
[SetOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-setoptions) method.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)

[SetOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-setoptions)