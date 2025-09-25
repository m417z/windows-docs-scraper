# FWPS_VSWITCH_EVENT_DISPATCH_TABLE0_ structure

## Description

The **FWPS_VSWITCH_EVENT_DISPATCH_TABLE0** structure specifies a callout driver-supplied virtual switch event dispatch table.

**Note** **FWPS_VSWITCH_EVENT_DISPATCH_TABLE0** is a specific version of **FWPS_VSWITCH_EVENT_DISPATCH_TABLE**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `vSwitchLifetimeNotifyFn`

The entry point for the [FWPS_VSWITCH_LIFETIME_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_lifetime_event_callback0) callback function or NULL.

### `vSwitchPortEventNotifyFn`

The entry point for the [FWPS_VSWITCH_PORT_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_port_event_callback0) callback function or NULL.

### `vSwitchInterfaceEventNotifyFn`

The entry point for the [FWPS_VSWITCH_INTERFACE_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_interface_event_callback0) callback function or NULL.

### `vSwitchFilterEngineReorderNotifyRn`

The entry point for the [FWPS_VSWITCH_FILTER_ENGINE_REORDER_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_filter_engine_reorder_callback0) callback function or NULL.

### `vSwitchPolicyEventNotifyFn`

The entry point for the [FWPS_VSWITCH_POLICY_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_policy_event_callback0) callback function or NULL.

### `vSwitchRuntimeStateSaveNotifyFn`

The entry point for the [FWPS_VSWITCH_RUNTIME_STATE_SAVE_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_runtime_state_save_callback0) callback function or NULL.

### `vSwitchRuntimeStateRestoreNotifyFn`

The entry point for the [FWPS_VSWITCH_RUNTIME_STATE_RESTORE_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_runtime_state_restore_callback0) callback function or NULL.

## Remarks

The callback driver passes a pointer to an initialized FWPS_VSWITCH_EVENT_DISPATCH_TABLE0 structure to the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0) function.

The following definition is in fwpvi.h:

`#define FWPS_VSWITCH_EVENT_DISPATCH_TABLE FWPS_VSWITCH_EVENT_DISPATCH_TABLE0`

## See also

[FWPS_VSWITCH_FILTER_ENGINE_REORDER_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_filter_engine_reorder_callback0)

[FWPS_VSWITCH_INTERFACE_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_interface_event_callback0)

[FWPS_VSWITCH_LIFETIME_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_lifetime_event_callback0)

[FWPS_VSWITCH_POLICY_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_policy_event_callback0)

[FWPS_VSWITCH_PORT_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_port_event_callback0)

[FWPS_VSWITCH_RUNTIME_STATE_RESTORE_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_runtime_state_restore_callback0)

[FWPS_VSWITCH_RUNTIME_STATE_SAVE_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_runtime_state_save_callback0)

[FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)