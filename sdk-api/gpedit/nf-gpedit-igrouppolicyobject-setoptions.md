# IGroupPolicyObject::SetOptions

## Description

The
**SetOptions** method sets the options for the GPO.

## Parameters

### `dwOptions` [in]

Specifies the new option values. This parameter can be one or more of the following options. For more information, see the following Remarks section.

#### GPO_OPTION_DISABLE_USER

Disable the user portion of the GPO.

#### GPO_OPTION_DISABLE_MACHINE

Disable the computer portion of the GPO.

### `dwMask` [in]

Specifies the options to change. This parameter can be one or more of the following options. For more information, see the following Remarks section.

#### GPO_OPTION_DISABLE_USER

Disable the user portion of the GPO.

#### GPO_OPTION_DISABLE_MACHINE

Disable the computer portion of the GPO.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

**Note** A policy refresh will be automatically triggered when the user or computer portion of the local Group Policy object is enabled or disabled using the **SetOptions** method.

To change an option, you must set the appropriate flag in the *dwMask* parameter. If the flag is set, then the system reads the *dwOptions* parameter to set the new state. For example, to disable the user portion of a GPO, and leave the computer portion unchanged, call the
**SetOptions** method as follows:

```cpp
SetOptions(GPO_OPTION_DISABLE_USER, GPO_OPTION_DISABLE_USER)
```

To enable the user portion and disable the computer portion, call the
**SetOptions** method as follows:

```cpp
SetOptions(GPO_OPTION_DISABLE_MACHINE, GPO_OPTION_DISABLE_USER | GPO_OPTION_DISABLE_MACHINE)
```

To retrieve the options for a GPO, you can call the
[GetOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getoptions) method.

## See also

[GetOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-getoptions)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)