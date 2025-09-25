## Description

**DXGIDDI_PARTITIONING_EVENT_TYPE** identifies the type of ETW event being reported by [**DxgkCbLogEtwEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_log_etw_event) when **EventGuid** is GUID_DXGKDDI_AZURE_TRIAGE_EVENT.

## Constants

### `DXGK_PARTITION_EVENT_FUNCTION_LEVEL_RESET`

A driver specifies this type to indicate a function level reset (FLR). A FLR when the virtual function (VF) must be reset and all register mappings are reset to attempt to unblock a detected timeout. This is typically the first attempted step of an adapter-wide reset on a vGPU in a guest.

### `DXGK_PARTITION_EVENT_FUNDAMENTAL_WARM_RESET`

A driver specifies this type to indicate a fundamental warm reset (FWR). A FWR is the whole-GPU reset that is typically seen on bare metal (non virtualized) adapter resets. A FWR is typically the second and last thing attempted for an adapter reset on a vGPU when the FLR fails to get the adapter executing again. A FWR is disruptive not only to the virtual machine (VM) with the vGPU wanting to be reset, but to all other VMs with assigned vGPUs from that device, so this level of TDR recovery should be avoided wherever possible.

### `DXGK_PARTITION_EVENT_DRIVER_INTERNAL`

A driver specifies this type to report other event(s) with information that might be helpful for issue triage.

## Remarks

**DXGK_PARTITION_EVENT_FUNCTION_LEVEL_RESET** and **DXGK_PARTITION_EVENT_FUNDAMENTAL_WARM_RESET** provide two separate levels of severity when a driver reports timeout detection and recovery (TDR) events.

See [**DXGKDDICB_PARTITIONING_EVENT_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkddicb_partitioning_event_notification) for additional details.

## See also

[**DxgkCbLogEtwEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_log_etw_event)