# FWPM_VSWITCH_EVENT_TYPE enumeration

## Description

The **FWPM_VSWITCH_EVENT_TYPE** enumeration specifies the type of a vSwitch event.

## Constants

### `FWPM_VSWITCH_EVENT_FILTER_ADD_TO_INCOMPLETE_LAYER:0`

The filter engine is not enabled on all vSwitch instances. As a result, the filter(s) being added may not be fully enforced.

### `FWPM_VSWITCH_EVENT_FILTER_ENGINE_NOT_IN_REQUIRED_POSITION`

The filter engine to which the filter(s) are being added is not in its required position (typically the first filtering extension in the vSwitch instance). As a result, the filter(s) could be bypassed.

### `FWPM_VSWITCH_EVENT_ENABLED_FOR_INSPECTION`

The filter engine is being enabled for the vSwitch instance.

### `FWPM_VSWITCH_EVENT_DISABLED_FOR_INSPECTION`

The filter engine is being disabled for the vSwitch instance.

### `FWPM_VSWITCH_EVENT_FILTER_ENGINE_REORDER`

The filter engine is being reordered and may not be in the
required position to enforce committed filters.

### `FWPM_VSWITCH_EVENT_MAX`

Maximum value for testing purposes.

## See also

[Windows Filtering Platform API Enumerated Types](https://learn.microsoft.com/windows/desktop/FWP/fwp-enums)