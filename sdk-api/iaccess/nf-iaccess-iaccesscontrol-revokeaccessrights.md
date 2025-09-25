# IAccessControl::RevokeAccessRights

## Description

Removes any explicit entries for the list of trustees.

## Parameters

### `lpProperty` [in]

The name of the property. If you are using the COM implementation of [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol), this parameter must be **NULL**.

### `cTrustees` [in]

The number of trustees in the list. This parameter cannot be 0.

### `prgTrustees` [in]

A pointer to an array of trustee names. See [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Even after removing explicit entries, the trustees might still have access entries due to group inclusion.

## See also

[IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol)