# IDARG_IN_QUERYTARGETMODES structure

## Description

The **IDARG_IN_QUERYTARGETMODES** structure contains input arguments for the [**EVT_IDD_CX_MONITOR_QUERY_TARGET_MODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_query_target_modes) callback function.

## Members

### `MonitorDescription`

[in] An [**IDDCX_MONITOR_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_monitor_description) structure that contains the monitor description.

This might not be the monitor description the driver originally provided in the monitor arrival call, which allows for the monitor description to be updated by the OS.

### `TargetModeBufferInputCount`

[in] The number of target modes that can be held in the buffer that **pTargetModes** points to. If the value is zero, then the driver should not copy the target mode list to **pTargetModes**, but should instead set [**IDARG_OUT_QUERYTARGETMODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_querytargetmodes)'s **TargetModeBufferOutputCount** value to indicate the size of buffer required to store the modes.

### `pTargetModes`

[out] Pointer to a buffer of [**IDDCX_TARGET_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_target_mode) structures that the driver should copy the target modes it supports for this monitor to if the value is non-NULL. If **pTargetModes** is NULL, then driver shouldn't copy any data and should instead just set [**IDARG_OUT_QUERYTARGETMODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_querytargetmodes)'s **TargetModeBufferOutputCount** value to indicate the size of buffer required to store the modes.

## See also

[**EVT_IDD_CX_MONITOR_QUERY_TARGET_MODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_query_target_modes)

[**IDARG_OUT_QUERYTARGETMODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_querytargetmodes)

[**IDDCX_MONITOR_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_monitor_description)

[**IDDCX_TARGET_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_target_mode)