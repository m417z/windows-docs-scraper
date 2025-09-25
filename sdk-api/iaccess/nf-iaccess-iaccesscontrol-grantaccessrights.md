# IAccessControl::GrantAccessRights

## Description

Merges the new list of access rights with the existing access rights on the object.

## Parameters

### `pAccessList` [in]

A pointer to the [ACTRL_ACCESS](https://learn.microsoft.com/windows/win32/api/accctrl/ns-accctrl-explicit_access_a) structure that contains an array of access lists for the object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Merging the new access rights list with the existing access rights ensures that the object will have at least the indicated access rights. This merge process consists of adding the new denied access rights before the old denied access rights, and the new allowed access rights before the existing allowed rights. None of the existing rights are removed.

Following a merge, the access rights on an object are ordered as follows:

1. [New Access Denied]
2. [Old Access Denied]
3. [New Access Allowed]
4. [Old Access Allowed]

The system-supplied implementation of [ACTRL_ACCESS](https://learn.microsoft.com/windows/win32/api/accctrl/ns-accctrl-explicit_access_a) structure be set to 1. In addition, the **lpProperty** member of the [ACTRL_PROPERTY_ENTRYW](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-actrl_property_entrya) structure must be **NULL** to indicate that the access entry list applies to the object itself.

## See also

[IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol)