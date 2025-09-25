# IDDCX_UPDATE_REASON enumeration

## Description

A **IDDCX_UPDATE_REASON** value describes why the driver is calling to update the mode list.

## Constants

### `IDDCX_UPDATE_REASON_UNINITIALIZED:0`

Indicates that an **IDDCX_UPDATE_REASON** variable has not yet been assigned a meaningful value.

### `IDDCX_UPDATE_REASON_POWER_CONSTRAINTS:1`

The mode list is changing due to changed power constraints on the host system.

### `IDDCX_UPDATE_REASON_HOST_LINK_BANDWIDTH:2`

The mode list is changing due to changes in bandwidth between the system and the indirect display device.

### `IDDCX_UPDATE_REASON_DISPLAY_LINK_BANDWIDTH:3`

The mode list is changing due to changes in bandwidth between the indirect display device and the monitor.

### `IDDCX_UPDATE_REASON_CONFIGURATION_CONSTRAINTS:4`

The mode list is changing due to constraints of the product when in a new configuration.

### `IDDCX_UPDATE_REASON_OTHER:5`

The mode list is changing due to another reason not listed above.

## See also

[**IDARG_IN_MAXDISPLAYPIPELINERATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_maxdisplaypipelinerate)

[**IDARG_IN_UPDATEMODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_updatemodes)

[**IddCxAdapterUpdateMaxDisplayPipelineRate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterupdatemaxdisplaypipelinerate)

[**IddCxMonitorUpdateModes2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes2)

[**IddCxMonitorUpdateModes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes)