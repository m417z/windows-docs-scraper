# _CLIENT_QUERY_BANK_POWER_INFORMATION_OUTPUT structure

## Description

The **CLIENT_QUERY_BANK_POWER_INFORMATION_OUTPUT** structure contains information about the power-management capabilities of a bank of general-purpose I/O (GPIO) pins.

## Members

### `F1StateSupported`

Indicates whether the GPIO bank supports [component-level power management](https://learn.microsoft.com/windows-hardware/drivers/kernel/component-level-power-management). If this flag is set, the GPIO bank supports component-level power management. Otherwise, it does not. A GPIO bank that supports power management can change between the F0 (fully powered) state and the F1 (low-power) state independently of the Fx power states of the other banks in the GPIO controller. A GPIO bank that does not support component-level power management is always in the F0 power state when the controller is in the D0 power state.

### `Reserved`

Not used.

### `F1IdleStateParameters`

A **PO_FX_COMPONENT_IDLE_STATE** structure that describes the parameters (transition latency, residency requirement, and so on) for the F1 power state of the GPIO bank. For more information about these parameters, see [PO_FX_COMPONENT_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_idle_state).

## Remarks

The unnamed struct inside _CLIENT_QUERY_BANK_POWER_INFORMATION_OUTPUT contains a set of power-management flag bits.

The **BankPowerInformation** member of the [CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_output) structure is a structure of type **CLIENT_QUERY_BANK_POWER_INFORMATION_OUTPUT**.

For more information about GPIO banks, see [Partitioning a GPIO Controller into Banks of Pins](https://learn.microsoft.com/windows-hardware/drivers/gpio/partitioning-a-gpio-controller-into-banks-of-pins).

## See also

- [CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_output)
- [PO_FX_COMPONENT_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_idle_state)