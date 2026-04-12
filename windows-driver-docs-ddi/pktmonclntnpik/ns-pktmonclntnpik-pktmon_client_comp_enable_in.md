## Description

The **PKTMON_CLIENT_COMP_ENABLE_IN** structure contains parameters for enabling or disabling packet monitoring on a specific component. This structure is passed to the **[PKTMON_CLIENT_COMP_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_client_comp_enable)** callback to control monitoring behavior.

## Members

### `Header`

A [PKTMON_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_header) structure used for versioning and size validation.

### `CompContext`

A pointer to the component-specific context that was provided during component registration. This context identifies which component is being enabled or disabled.

### `FlowEnabled`

A BOOLEAN value indicating whether packet flow logging should be enabled (TRUE) or disabled (FALSE) for this component.

### `DropEnabled`

A BOOLEAN value indicating whether packet drop logging should be enabled (TRUE) or disabled (FALSE) for this component.

## Remarks

This structure allows selective enabling of flow and drop monitoring, giving components fine-grained control over what packet events they track.

## See also

- [PKTMON_CLIENT_COMP_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_client_comp_enable)
- [PKTMON_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_client_dispatch)
- [PKTMON_COMPONENT_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_component_in)