# _PEP_PERF_STATE structure (pepfx.h)

## Description

The **PEP_PERF_STATE** structure describes a performance state (P-state) in a P-state set in which the P-states are specified as a list of one or more discrete values.

## Members

### `Value`

The discrete value represented by this P-state. For more information, see Remarks.

### `Context`

A pointer to PEP-defined context data. The PEP uses this context to contain additional information about the discrete performance level that cannot be expressed in the **Value** member. This context is opaque to the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The **Context** member is optional and can be set to NULL.

## Remarks

The **Discrete.States** member of the [PEP_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_set) structure is a pointer to an array of **PEP_PERF_STATE** structures. The **Unit** member of the **PEP_COMPONENT_PERF_SET** structure specifies the units in which the **Value** member in each array element is expressed. Component performance can be expressed in hertz (frequency) or in bits per second (bandwidth). For example, if **Value** = 100,000,000 and **Unit** = **PepPerfStateUnitFrequency**, this performance state represents a frequency of 100 megahertz.

Device drivers use the [PO_FX_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_perf_state) structure, which is similar to the **PEP_PERF_STATE** structure.

## See also

[PEP_COMPONENT_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_perf_set)

[PO_FX_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_perf_state)