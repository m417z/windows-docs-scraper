# IAccessControl::SetAccessRights

## Description

Replaces the existing access rights on an object with the specified list.

## Parameters

### `pAccessList` [in]

A pointer to the [ACTRL_ACCESS](https://learn.microsoft.com/windows/win32/api/accctrl/ns-accctrl-explicit_access_a) list that contains an array of access lists to be written to the object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol)