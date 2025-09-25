# _PO_FX_COMPONENT_IDLE_STATE structure

## Description

The **PO_FX_COMPONENT_IDLE_STATE** structure specifies the attributes of an Fx power state of a component in a device.

## Members

### `TransitionLatency`

The transition latency. This latency is the amount of time, in 100-nanosecond units, that the component requires to return from this Fx state to the F0 state. For a **PO_FX_COMPONENT_IDLE_STATE** structure that specifies the attributes of the F0 state, set this member to zero.

### `ResidencyRequirement`

The residency requirement. The residency requirement is the minimum amount of time, in 100-nanosecond units, that the component must spend in this Fx state to make a transition to this Fx state worthwhile. PoFx uses this member value as a hint to avoid switching a component to an Fx state unless the component is likely to remain in this state for at least the amount of time specified by **ResidencyRequirement**. For a **PO_FX_COMPONENT_IDLE_STATE** structure that describes the attributes of the F0 state, set this member to zero.

### `NominalPower`

The power, in microwatts, that the component consumes in this Fx state. Set this member to **PO_FX_UNKNOWN_POWER** to indicate that PoFx should ignore (treat as negligible) the component's internal power consumption in this Fx state when PoFx evaluates which power state to switch to when the component is idle.

## Remarks

 The [PO_FX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_v1) structure contains a pointer to an array of **PO_FX_COMPONENT_IDLE_STATE** structures. Each array element specifies the attributes of an Fx state. Element 0 describes F0, element 1 describes F1, and so on.

When the driver registers a device with PoFx, the driver supplies an array of **PO_FX_COMPONENT** structures. Each array element describes the power attributes of a component in the device.

Do not set **TransitionLatency** and **ResidencyRequirement** to **PO_FX_UNKNOWN_TIME** because it may prevent the power management framework (PoFx) from selecting the idle state.

## See also

[PO_FX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_v1)