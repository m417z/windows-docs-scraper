# _STOR_POFX_COMPONENT_IDLE_STATE structure

## Description

The **STOR_POFX_COMPONENT_IDLE_STATE** structure specifies the attributes of a functional power state (F-state) of a component in a storage device.

## Members

### `Version`

The version of this structure. Set this member to **STOR_POFX_COMPONENT_IDLE_STATE_VERSION_V1**.

### `Size`

The size of this structure. Set this value to **STOR_POFX_COMPONENT_IDLE_STATE_SIZE**.

### `TransitionLatency`

The transition latency. This latency is the amount of time, in 100-nanosecond units, that the component requires to return from this F-state to the F0 state. For a **STOR_POFX_COMPONENT_IDLE_STATE** structure that specifies the attributes of the F0 state, set this member to zero. Set this member to STOR_PO_FX_UNKNOWN_TIME to indicate that the power management framework (PoFx) should ignore (treat as negligible) the component's transition latency from this F-state when PoFx evaluates which power state to switch to when the component is idle.

### `ResidencyRequirement`

The residency requirement. The residency requirement is the minimum amount of time, in 100-nanosecond units, that the component must spend in this F-state to make a transition to this F-state worthwhile. PoFx uses this member value as a hint to avoid switching a component to an F-state unless the component is likely to remain in this state for at least the amount of time specified by **ResidencyRequirement**. For a STOR_PO_FX_COMPONENT_IDLE_STATE structure that describes the attributes of the F0 state, set this member to zero. Set this member to STOR_PO_FX_UNKNOWN_TIME to indicate that PoFx should ignore (treat as negligible) the component's residency requirement for this F-state when PoFx evaluates which power state to switch to when the component is idle.

### `NominalPower`

The power, in microwatts, that the component consumes in this F-state. Set this member to STOR_PO_FX_UNKNOWN_POWER to indicate that PoFx should ignore (treat as negligible) the component's internal power consumption in this F-state when PoFx evaluates which power state to switch to when the component is idle.

## Remarks

 The [STOR_POFX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_component) structure contains an array of **STOR_POFX_COMPONENT_IDLE_STATE** structures. Each array element specifies the attributes of an F-state. Element 0 describes F0, element 1 describes F1, and so on.

When the miniport driver registers a device with the Storport power management framework, the driver supplies an array of [STOR_POFX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_component) structures. Each array element describes the power attributes of a component in the device.

## See also

[STOR_POFX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_component)