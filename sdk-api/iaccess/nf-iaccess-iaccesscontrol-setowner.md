# IAccessControl::SetOwner

## Description

Sets the owner or the group of an item.

## Parameters

### `pOwner` [in]

The address of the [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure for the owner.

### `pGroup` [in]

The address of the [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure for the group.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **SetOwner** method is not implemented by CLSID_DCOMAccessControl.

## See also

[IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol)