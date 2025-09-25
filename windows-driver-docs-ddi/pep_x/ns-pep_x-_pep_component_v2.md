# _PEP_COMPONENT_V2 structure (pep_x.h)

## Description

The **PEP_COMPONENT_V2** structure specifies the power state attributes of a component in the device.

## Members

### `Id`

A component ID that uniquely identifies this component with respect to the other components in the device. The PEP should specify a nonzero value for this member if the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) requires a component ID to distinguish this component from other, similar components in the same device. This member is optional. If this member is not used, it must be set to all zeros.

### `Flags`

A set of component-power-state flags. No flags are currently defined for this member, which is always zero.

### `DeepestWakeableIdleState`

The index of the deepest F*x* state from which the component can wake. Specify 0 for F0, 1 for F1, and so on. This index must be less than **IdleStateCount**.

### `IdleStateCount`

The number of elements in the array that is pointed to by the **IdleStates** member. Additionally, this member specifies the number of F*x* power states that the component supports. A component must support at least one F*x* state (F0).

### `IdleStates`

A pointer to an array of [PO_FX_COMPONENT_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_idle_state) structures. The length of this array is specified by the **IdleStateCount** member. Each array element specifies the attributes of an F*x* power state that is supported by the component. Element 0 describes F0, element 1 describes F1, and so on.

## Remarks

This structure

## See also

[PO_FX_COMPONENT_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_idle_state)