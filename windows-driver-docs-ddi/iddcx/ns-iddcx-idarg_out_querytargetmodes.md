# IDARG_OUT_QUERYTARGETMODES structure

## Description

The **IDARG_OUT_QUERYTARGETMODES** structure contains output arguments for the [**EVT_IDD_CX_MONITOR_QUERY_TARGET_MODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_query_target_modes) and [**EVT_IDD_CX_MONITOR_QUERY_TARGET_MODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_query_target_modes2) callback functions.

## Members

### `TargetModeBufferOutputCount`

[out] If the OS provides the number of target modes, the driver sets this to that value. See [**IDARG_IN_QUERYTARGETMODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_querytargetmodes) for more information.

## See also

[**IDARG_IN_QUERYTARGETMODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_querytargetmodes)